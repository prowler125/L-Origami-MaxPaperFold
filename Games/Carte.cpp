#include <iostream>
 #include <windows.h> 
 #include <time.h>
 #include <string>

 using namespace std;

 int gotoxy(int r, int c) { // posizionamento cursore a riga 'r' e colonna 'c'
    HANDLE Hout; CONSOLE_SCREEN_BUFFER_INFO ConsoleInfo; 
    Hout = GetStdHandle(STD_OUTPUT_HANDLE); 
    ConsoleInfo.dwCursorPosition.Y = r; ConsoleInfo.dwCursorPosition.X = c;     
    SetConsoleCursorPosition(Hout,ConsoleInfo.dwCursorPosition); } 

 struct record_carta {    // struttura record "carta":
    string tipo;          // tipo  (Asse, Due, Tre, etc.)
	string seme;          // seme  (Denari, Coppe, etc.)
	int giocatore;        // giocatore che possiede la carta (se 0 la carta è ancora nel mazzo)
	};  

 record_carta Carta[40];  // le 40 carte
 int Mazzo[40];           // mazzo di carte (1-carta presente, 0-carta assente)
 int Gio[4][10];          // i 4 giocatori con le relative carte
 string tipo[10]      = {"Asse","Due","Tre","Quattro","Cinque","Sei","Sette","Fante","Cavallo","Re"};
 string seme[4]       = {"Denari","Coppe","Spadi","Bastoni"};
 string cartaccuso[3] = {"Assi","Due","Tre"};
 int acc[4][3];      // totali 'accusi': giocatori (righe), assi-due-tre (colonne)
 int nap[4][4];      // totali 'nalopetane': giocatori (righe), semi (colonne)
 int c,s,g;          // indici degli array ('c'=carta, 's'=seme, 'g'=giocatore)

void inizializza() { // inizializzazione strutture
   g = 0;
   for( s = 0; s < 4; s++ ) {       // ciclo sui semi
      for( c = 0; c < 10; c++ ) {   // ciclo sui semi
         Carta[g].tipo = tipo[c]; 
         Carta[g].seme = seme[s];
         Carta[g].giocatore = 0;
         g++;
         }
      }
   for( g = 0; g < 4; g++ ) {        // ciclo sui giocatori
      for( int i = 0; i < 4; i++ ) { // ciclo sui semi (e su assi-due-tre)
         nap[g][i] = 0;
         if ( i < 3 ) acc[g][i] = 0; }      
      }                               
   }                               
 
 void distribuisci() { // distribuzione casuale carte
   srand(time(0));     // setta il numero iniziale del generatore numeri casuali
   for( g = 0; g < 4; g++ ) {       // ciclo sui giocatori
      for( c = 0; c < 10; c++ ) {   // ciclo sulle carte da distribuire
         do {
            s = rand() % 40;               // estrae casualmente la carta
  		    }
         while (Carta[s].giocatore > 0);   // se la carta è già stata assegnata ripete l'estrazione
         Carta[s].giocatore = g;           // assegna la carta al giocatore 
         }
      }  
   }

 void visualizza() { // visualizza carte dei giocatori
   int col,row;
   for( g = 0; g < 4; g++ ) {                        // ciclo sui giocatori
      row = 3; col = g * 20 + 1;
      gotoxy(row,col); cout << "GIOCATORE " << g+1;
      for ( c = 0; c < 40 ; c++) {                   // ciclo sulle carte
          if (Carta[c].giocatore == g) {             // se la carta è del giocatore corrente,
              row = row + 1;                         // la visualizza
              gotoxy(row,col);
              cout << row-3 << " " << Carta[c].tipo << " " << Carta[c].seme;  
		     }
        }    
      }
   }

 void accuso() { // dichiarazione degli eventuali 'accusi' dei giocatori
   int col,row,t,c1,c2,c3;
   for( g = 0; g < 4; g++ ) {    // ciclo sui 4 giocatori
      for ( c = 0; c < 40 ; c++) // totali assi-due-tre giocatore corrente
          {   
           if (Carta[c].giocatore == g)
		      {
		       if (Carta[c].tipo == "Asse") acc[g][0]++;
		       if (Carta[c].tipo == "Due")  acc[g][1]++;
		       if (Carta[c].tipo == "Tre")  acc[g][2]++;
			  }
          }
          if (acc[g][0]>0 || acc[g][1]>0  || acc[g][2]>0) // ci possono essere una o più napoletane
             {
               for ( s = 0; s < 4 ; s++)
                  { c1 = 0; c2 = 0; c3 = 0;
                  	for ( c = 0; c < 40; c++ ) 
                  	   { if (Carta[c].giocatore == g)
                            {
    			     if (Carta[c].tipo == "Asse" && Carta[c].seme == seme[s]) c1++;
    			     if (Carta[c].tipo == "Due"  && Carta[c].seme == seme[s]) c2++;
    			     if (Carta[c].tipo == "Tre"  && Carta[c].seme == seme[s]) c3++;
			    }
		           }
                    if ( c1 + c2 + c3 == 3) nap[g][s] = 3; // napoletana !
				  }		 
		     }
      // visualizzazione eventuali accusi del giocatore corrente
      row = 14; col = g * 20 + 1; t = 0;
      for ( c = 0; c < 3 ; c++) { // accusa eventuali 3 o 4 assi-due-tre
         if (acc[g][c] >= 3) {
            t = t + acc[g][c]; row = row + 1; gotoxy(row,col);
            cout<<acc[g][c]<<" "<<cartaccuso[c]; }
         }
      for ( s = 0; s < 4 ; s++) { // accusa eventuali napoletane
         if (nap[g][s] >= 3) {
            t = t + nap[g][s]; row = row + 1; gotoxy(row,col);
            cout<<"Napoletana "<<seme[s]; }
         }
      row = row + 1; gotoxy(row,col); 
      if (t > 0)                  // totale accuso
          cout<<"ACCUSO "<<t;
      else
          cout<<"...";
      }
   }

int main() { // gioco del "TreSette", distribuzione carte e verifica 'accuso'
   char Cont;
   do {
        system("cls");
        printf ("\nTreSette - distribuzione carte ed ACCUSO <ClaMa>\n\n");
        inizializza();      // inizializza le strutture dati
        distribuisci();     // distribuisce le carte ai giocatori
        visualizza();       // visualizza le carte distriuite ai giocatori
        accuso();           // dichiarazione degli eventuali 'accusi' dei giocatori
        gotoxy(20,1);
		cout << "Ancora (s/n) ? "; cin >> Cont;  
       }
   while (Cont=='s');
   return 0; }
  
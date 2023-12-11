#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

// Dichiarazione delle variabili globali

int labirinto[10][10];
int x, y;
int cavaliere;

// Funzione per generare il labirinto

void generaLabirinto()
{
    // Inizializza il labirinto con dei muri
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            labirinto[i][j] = 1;
        }
    }

    // Genera le porte
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (rand() % 2 == 0)
            {
                labirinto[i][j] = 0;
            }
        }
    }

    // Genera il cavaliere
    x = rand() % 10;
    y = rand() % 10;
    cavaliere = 1;
}

// Funzione per stampare il labirinto

void stampaLabirinto()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (labirinto[i][j] == 1)
            {
                cout << " ";
            }
            else if (labirinto[i][j] == 0)
            {
                cout << " ";
            }
            else if (labirinto[i][j] == cavaliere)
            {
                cout << "C";
            }
        }
        cout << endl;
    }
}

// Funzione per controllare se il cavaliere è in una trappola

bool inTrappola()
{
    if (labirinto[x][y] == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Funzione per controllare se il cavaliere ha raggiunto il centro

bool raggiuntoCentro()
{
    if (x == 4 && y == 5)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Funzione per spostare il cavaliere

void spostaCavaliere(int dx, int dy)
{
    x += dx;
    y += dy;
}

int main()
{
    generaLabirinto();

    while (!raggiuntoCentro())
    {
        stampaLabirinto();

        char input;
        cin >> input;

        if (input == 'w')
        {
            spostaCavaliere(0, -1);
        }
        else if (input == 's')
        {
            spostaCavaliere(0, 1);
        }
        else if (input == 'a')
        {
            spostaCavaliere(-1, 0);
        }
        else if (input == 'd')
        {
            spostaCavaliere(1, 0);
        }
        if (inTrappola())
        {
            cout << "Il cavaliere è caduto in una trappola!" << endl;
            break;
        }
    }
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int labirinto[10][10];
int x, y;
int cavaliere;

void generaLabirinto()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            labirinto[i][j] = 1;
        }
    }

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

    x = rand() % 10;
    y = rand() % 10;
    cavaliere = 1;
}
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
}
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const char fi[] = "U5.txt";
const char fo[] = "U5Rez.txt";

const int CMax = 100;

struct Stotis{
            int nr;
            int iejo = 0;
            int isejo = 0;
            int bendras = 0;
};


// Aprašomi globalūs kintamieji
Stotis S[CMax];
int k = 0;
ofstream o(fo);

//Funkcijų prototitai
void Nuskaityti();
void Rikiuoti();
Stotis MaxZmoniu();
int Yra(int nr);
int VisoZmoniu();
void SpauzdintiPirma();
void SpauzdintiAntra();
void SpauzdintiKitus();

int main()
{
    Nuskaityti();
    SpauzdintiPirma();
    o.close();
    return 0;
}

void Nuskaityti()
{
    ifstream f(fi);
    int m, nr, d, j, ilip, islip;
    f >> m;
    for (int i = 0; i < m; i++)
    {
        f >> nr;
        f >> d;
        f >> ilip;
        f >> islip;
        j = Yra(nr);
        if(j >= 0)
        {
            S[j].iejo += ilip;
            S[j].isejo += islip;
            S[j].bendras += (islip + ilip);
        }
        else{
            S[k].nr = nr;
            S[k].iejo += ilip;
            S[k].isejo += islip;
            S[k].bendras += (islip + ilip);
            k++;
        }
    }
    f.close();
}

void SpauzdintiPirma()
{
    Rikiuoti();
    for (int i = 0; i < k; i++)
    {
        o << right << setw(6) << S[i].nr;
    }
    o << endl;
    SpauzdintiAntra();
}
void SpauzdintiAntra()
{
    for(int i = 0; i < k; i++)
    {
        o << right << setw(6) << S[i].bendras;
    }
    o << endl;
    SpauzdintiKitus();
}

void SpauzdintiKitus()
{
    o << right << setw(6) << MaxZmoniu().nr << endl;
    o << right << setw(6) << VisoZmoniu();
}


Stotis MaxZmoniu()
{
    int max;
    max = 0;
    Stotis index;
    for(int i = 0; i < k; i++)
    {
        if(S[i].bendras > max)
        {
            max = S[i].bendras;
            index = S[i];
        }
    }
    return index;
}

void Rikiuoti()
{
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < (k - 1); j++)
        {
            if(S[j].nr > S[j+1].nr)
            {
                Stotis temp;
                temp = S[j];
                S[j] = S[j+1];
                S[j+1] = temp;
            }
        }
    }
}

int VisoZmoniu()
{
    int res = 0;
    for (int i = 0; i < k; i++)
    {
        res += S[i].iejo;
    }
    return res;
}

int Yra(int nr)
{
    for(int i = 0; i < k; i++)
    {
        if(S[i].nr == nr) return i;
    }
    return -1;
}

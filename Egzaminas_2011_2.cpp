#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void nuskaityti(string p[], int t[][100], int a[][100], int& poros, int& teis)
{
    string p1, p2;

    int i, j;

    ifstream f;
    f.open("./data/2011_U1_2.txt");

    f >> poros;
    f >> teis;

    for(i = 0; i < poros; i++){
        f>>p1;
        f>>p2;
        p[i] = p1 + " " + p2;
        for(j = 0; j < teis;j++){
            f >> t[i][j];
        }
        for(j = 0; j < teis;j++){
            f >> a[i][j];
        }
    }
    f.close();

}

void task(int t[], int teis, int taskai[], int a)
{
    int maxx, minn, viso;

    viso = 0;
    maxx = 0;
    minn = 11;

    for(int i = 0; i < teis; i++){


        if(t[i] > maxx){
            maxx = t[i];
        }
        if(t[i] < minn){
            minn = t[i];
        }
        taskai[a] += t[i];
    }
    taskai[a] = taskai[a] - maxx - minn;


}

void rikiuote(int poros, int taskai[],string p[])
{
    int maxx, minn, j;
    maxx = 0;
    minn = 100;
    j = 0;
    string g;
    int v;
    for(int x=0;x<poros;x++){
               for(int z=0;z<poros;z++){
                    v = z;
                    if(taskai[z] < taskai[z+1]){
                        v = taskai[z];
                        g = p[z];
                        taskai[z] = taskai[z+1];
                        p[z] = p[z+1];
                        p[z+1] = g;
                        taskai[z+1] = v;
                    }
                }
            }
}

int main()
{
    int t[100][100], a[100][100];
    string p[100];
    int taskai_t[100], taskai_a[100], taskai[100], taskai_final[100];

    int poros, teis, eil[100];
    teis = 0;
    poros = 0;

    nuskaityti(p, t, a, poros, teis);
    for(int i = 0; i < poros; i++){
        task(t[i], teis, taskai_t, i);
        task(a[i], teis, taskai_a, i);
        taskai[i] = taskai_t[i] + taskai_a[i];
    }

    rikiuote(poros, taskai, p);

    ofstream o;
    o.open("./data/2011_U1rez_2.txt");

    for (int i = 0; i < poros; i++){
        o << setw(20) << left << p[i] << taskai[i] << endl;
    }

    return 0;
}

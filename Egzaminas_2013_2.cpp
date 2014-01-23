#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const char fi[] = "./data/2013_U2.txt";
const char fo[] = "./data/2013_U2rez.txt";

struct Miestai{
                string vardas;
                string apskritis;
                int gyventojai;
};

struct Apskritys{
                string vardas;
                Miestai maziausias;
                int min;
                int gyventojai;
};

void Nuskaityti(Miestai M[], Apskritys[], int & l, int & a);

int main()
{
    Miestai M[100];
    Apskritys A[100];

    int l, a;

    Nuskaityti(M, A, l, a);

    ofstream o(fo);
    o << a << endl;
    for (int i = 0; i < a; i++){
        o << setw(13) << left << A[i].vardas << " "
            << A[i].min << " "
            << A[i].gyventojai << endl;
    }

    return 0;
}

void Nuskaityti(Miestai M[], Apskritys A[], int & l, int & a)
{
    ifstream f(fi);

    f >> l;

    int j, k;
    bool galima;
    k = 1;

    for (int i = 0; i < l ; i++){
        f >> M[i].vardas;
        f >> M[i].apskritis;
        f >> M[i].gyventojai;
        galima = true;
        for (j = 0; j < k; j++){
            if(M[i].apskritis == A[j].vardas){
                galima = false;
                A[j].gyventojai += M[i].gyventojai;
                if(M[i].gyventojai < A[j].min){
                    A[j].min = M[i].gyventojai;
                }
                break;
            }
        }
        if(galima == true){
            A[k-1].vardas = M[i].apskritis;
            A[k-1].gyventojai = M[i].gyventojai;
            A[k-1].min = 99999999;
            k++;
        }
    }
    a = k -1;

}

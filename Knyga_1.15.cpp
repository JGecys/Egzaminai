#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct Miestas{string pav,
                    valst;
                int kiek;
};

const char fi[] = "./Data/AtrinkimasU1.txt";

void Nuskaityti(Miestas A[], int & n);
void Atrinkti(Miestas A[], Miestas B[], int n, int & m);
int Yra(Miestas B[], int m, string miestas);

int main()
{
    Miestas A[100], B[100];
    int n, m;

    Nuskaityti(A, n);
    Atrinkti(A, B, n, m);

    for(int i = 0; i < m; i++){
        cout << setw(15) << B[i].valst << setw(10) << B[i].kiek << endl;
    }

    return 0;
}

int Yra(Miestas B[], int m, string miestas)
{

    for(int i = 0; i < m; i++)
    {
        if(B[i].valst == miestas){
            return i;
        }
    }
    return -1;

}

void Atrinkti(Miestas A[], Miestas B[], int n, int & m)
{
    m = 0;
    for(int i = 0; i < n; i ++)
    {
        int k = Yra(B, m, A[i].valst);
        if(k>=0)
        {
            B[k].kiek ++;
        }
        else{
            B[m] = A[i];
            m++;
        }
    }
}

void Nuskaityti(Miestas A[], int & n)
{
    ifstream f(fi);

    f >> n;
    for (int i = 0; i < n; i ++)
    {
        f >> A[i].pav;
        f >> A[i].valst;
        A[i].kiek = 1;
    }
    f.close();
}

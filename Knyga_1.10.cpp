#include <iostream>
#include <fstream>

using namespace std;

const char fi[] = "./Data/irasymasimasyva.txt";

void Nuskaityti(int A[], int & n);
int Rasti(int A[], int n);
void Iterpti(int A[], int & n, int l);

int main()
{
    int A[100], n, l;

    Nuskaityti(A, n);
    l = Rasti(A, n);
    if(l >= 0){
        Iterpti(A, n, l);
        for ( int i = 0; i < n; i++){
            cout << "-------" << endl;
            cout << A[i] << endl;
            cout << "-------" << endl;
        }
    }
    else{
        cout << "Nera tokios reiksmes" << endl;
    }


    return 0;
}

void Iterpti(int A[], int & n, int l)
{
    for (int i = n; i >= l; i--){
        A[i+1] = A[i];
    }
    A[l] = 11;
    n++;
}

int Rasti(int A[], int n)
{
    for(int i = 0; i < n; i++){
        if(A[i] == 11 && A[i+1] != 11) return (i+1);
    }
    return -1;

}

void Nuskaityti(int A[], int & n)
{
    ifstream f(fi);

    f >> n;
    for(int i = 0; i < n; i++){
        f >> A[i];
    }
    f.close();
}

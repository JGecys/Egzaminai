#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

const char fi[] = "./data/2013_U1.txt";
const char fo[] = "./data/2013_U1rez.txt";

struct Imone{
            string vardas;
            int atstumas;
};

void Nuskaityti(Imone I[], int & l, int & t);
int atstumas(int x, int y);
double abs(int x);
void print(int k, int tt, string last);

int main()
{
    Imone I[100];
    int l;
    int t;
    int k;
    k =0;

    string last;

    int tt;
    tt = 0;

    Nuskaityti( I, l, t);

    for (int i =0; i < l; i++){
        if(tt + I[i].atstumas * 2 < t){
            tt += I[i].atstumas * 2;
            k++;
            last = I[i].vardas;
        }
        else {
            break;
        }

    }
    print(k, tt, last);


    return 0;
}

void print(int k, int tt, string last)
{
    ofstream o(fo);
    o << k << " " << tt << " " << last;
    o.close();
}

void Nuskaityti(Imone I[], int & l, int & t)
{
    ifstream f(fi);

    int x, y;

    f >> l;
    f >> t;
    for(int i = 0; i < l; i++){
        f>> I[i].vardas;
        f>> x;
        f>> y;
        I[i].atstumas = atstumas(x, y);
    }
    f.close();

}
int atstumas(int x, int y)
{
    int z;
    z = abs(x)+ abs(y);
    return z;
}

double abs(int x)
{
    x = sqrt(x*x);
    return x;
}

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const char fi[] = "./data/2012_U2.txt";
const char fo[] = "./data/2012_U2rez.txt";

struct Dievas{
                string vardas;
                int taskai;
                int teig_num;
};

void Nuskaityti(Dievas D[], int & l, int & k);
void Best(Dievas D[], int l, int & winner);

int main()
{
    Dievas D[5];
    int l, k;
    int winner;
    winner = 0;

    Nuskaityti(D, l, k);
    Best(D, l, winner);

    ofstream o(fo);
    o << setw(20) << left << D[winner].vardas << D[winner].taskai;
    o.close();
    return 0;

}

void Nuskaityti(Dievas D[], int & l, int & k)
{
    ifstream f(fi);

    f >> l;
    f >> k;

    int kauliukai, j;

    for(int i = 0; i < l; i++){
        f >> D[i].vardas;
        D[i].taskai = 0;
        D[i].teig_num = 0;
        for(j = 0; j < k; j++){
            f >> kauliukai;
            if(kauliukai % 2 == 0){
                D[i].taskai += kauliukai;
                D[i].teig_num++;
            }
            if(kauliukai % 2 != 0){
                D[i].taskai += -kauliukai;
            }
        }
    }
    f.close();
}

void Best(Dievas D[], int l, int & winner)
{
    int maxx, pos[100], j, i;
    maxx = 0;
    j = 0;

    for (i = 0; i < l; i++){
        if(D[i].taskai >= maxx){
            maxx = D[i].taskai;
            pos[j] = i;
            j++;
        }
    }
    j = 0;
    for (i = 0; i < l; i++){
        if (D[i].taskai == maxx){
            j++;
        }
    }

    if (j == 1){
        winner = pos[j];
    }
    else{
        maxx = 0;
        j=0;
        for (i = 0; i < l ; i++){
            if(D[i].teig_num > maxx){
                maxx = D[i].teig_num;

                j++;
            }
        }

        if (j == 1){
            winner = j;
        }
        else{
            for (i = 0; i < l; i++){
                if(D[i].teig_num > maxx){
                    winner = i;
                    break;
                }
            }
        }

    }

}

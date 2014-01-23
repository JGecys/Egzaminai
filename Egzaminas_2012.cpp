#include <iostream>
#include <fstream>

using namespace std;

const char fi[] = "./data/2012_U1.txt";
const char fo[] = "./data/2012_U1rez.txt";

struct Krepsininkas{int numeris;
                    int laikai;
                    int laikas[100];
                    int laikas_aiksteleje;
                    int laikas_ant_suoliuko;
};

void Nuskaityti(Krepsininkas K[], int & l);
void Start(Krepsininkas K[], int l, int start[]);
void Eiliskumas(int start[]);
void Max(Krepsininkas K[], int l, int & max, int & max_num, int & did, int & did_num);

int main()
{
    Krepsininkas K[100];

    int l;

    int max, max_num;
    int did, did_num;

    int start[100];

    Nuskaityti(K, l);
    Start(K, l, start);
    Max(K, l, max, max_num, did, did_num);


    ofstream o(fo);

    for (int i = 0; i < 5; i++){
        o << start[i] << " ";
    }
    o << endl;
    o << max_num << " " << max << endl;
    o << did_num << " " << did << endl;
    o.close();

    return 0;

}

void Nuskaityti(Krepsininkas K[], int & l)
{
    ifstream f(fi);

    f >> l;

    int i, j;

    for (i = 0; i < l; i++){
        f>>K[i].numeris;
        f>>K[i].laikai;
        K[i].laikas_aiksteleje = 0;
        K[i].laikas_ant_suoliuko = 0;
        for (j = 0; j<K[i].laikai; j++){
            f >> K[i].laikas[j];
            if (K[i].laikas[j] > 0){
                K[i].laikas_aiksteleje += K[i].laikas[j];
            }
            if (K[i].laikas[j] < 0){
                K[i].laikas_ant_suoliuko += -K[i].laikas[j];
            }
        }
    }
    f.close();

}

void Start(Krepsininkas K[], int l, int start[])
{
    int j;

    j = 0;

    for(int i = 0; i < l; i++){
        if (K[i].laikas[0] > 0){
            start[j] = K[i].numeris;
            j++;
        }
    }

    Eiliskumas(start);

}

void Eiliskumas(int start[])
{
    int temp, i, j;

    for (i = 0; i < 5; i++){
        for(j = 0; j < 4; j++){
            if(start[j]> start[j+1]){
                temp = start[j+1];
                start[j+1] = start[j];
                start[j] = temp;
            }
        }
    }

}

void Max(Krepsininkas K[], int l, int & max, int & max_num, int & did, int & did_num)
{
    max = 0;
    did = 0;

    for(int i = 0; i < l; i++){
        if (K[i].laikas_aiksteleje > max){
            max = K[i].laikas_aiksteleje;
            max_num = K[i].numeris;
        }

        if (K[i].laikas_ant_suoliuko > did){
            did = K[i].laikas_ant_suoliuko;
            did_num = K[i].numeris;
        }
    }

}

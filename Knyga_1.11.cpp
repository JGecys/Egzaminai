#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const char fi[] = "./Data/DarbasSuSimboliais.txt";

struct Simbolis{
                char s;
                int k;
};

int Kiek(char s);
void Rikiuoti(Simbolis S[], int n);

int main()
{
    Simbolis S[200];

    int index;
    index = 0;
    for (char i = 'a'; i <= 'z'; i++)
    {
        S[index].s = i;
        S[index].k = Kiek(i);
        index++;
    }

    Rikiuoti(S, index);

    for(int g = 0; g < index; g++){
        cout << setw(4) << left << S[g].s << setw(3) << S[g].k << endl;
    }
    cout << "//-------------------------------------//" << endl;

    return 0;
}


void Rikiuoti(Simbolis S[], int n)
{
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            if(S[j].k < S[j+1].k){
                Simbolis temp;
                temp = S[j];
                S[j] = S[j+1];
                S[j+1] = temp;
            }
        }
    }
}


int Kiek(char s)
{
    char a;
    int k;
    k = 0;
    ifstream f(fi);
    while(!f.eof()){
        f.get(a);
        if(!f.eof() && (a == s)){
            k++;
        }
    }
    f.close();


    return k;
}

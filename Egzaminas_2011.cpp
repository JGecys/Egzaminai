#include <iostream>
#include <fstream>

using namespace std;

void type(int p[100][100], int k, int& vyr, int& mot, int& mpor, int& vpor);
void liek(int vpor, int mpor, int vyr, int mot, int& vliek, int& mliek);

int main()
{
    ifstream f;
    ofstream o;

    int k, p[100][100], j;
    int vyr, mot, mpor, vpor, vliek, mliek;
    int c = 0;

    f.open("./data/2011_U1.txt");

    f>>k;
    for(int i = 0; i < k; i++ ){
        for(j = 0; j < 3; j++){
            f >> p[i][j];

        }
    }
    f.close();

    type(p, k, vyr, mot, mpor, vpor);
    liek(vpor, mpor, vyr, mot, vliek, mliek);

    o.open("./data/2011_U1rez.txt");
    o << mpor << endl;
    o << vpor << endl;
    o << mliek << endl;
    o << vliek << endl;

    o.close();

    return 0;



}

void type(int p[100][100], int k, int& vyr, int& mot, int& mpor, int& vpor)
{
    int i;
    int mk, md, vk, vd = 0;
    int mmin, vmin = 0;

    mk = 0;
    md = 0;
    vk = 0;
    vd = 0;

    for(i = 0; i < k; i++){
        if(p[i][0] == 3 && p[i][1] == 1){
            vk++;
        }
        if (p[i][0] == 3 && p[i][1] == 2){
            vd++;
        }
        if ((p[i][0] == 4) && (p[i][1] == 2)){
            md++;
        }
        if (p[i][0] == 4 && p[i][1] == 1){
            mk++;
        }
    }

    cout << md << endl;
    if(mk > md){
        mmin = md;
    }
    else {
        mmin = mk;}

    if(vk > vd){
        vmin = vd;
    }
    else{
        vmin = vk;}

    mot = mk + md;
    vyr = vk + vd;

    mpor = mmin;
    vpor = vmin;

}

void liek(int vpor, int mpor, int vyr, int mot, int& vliek, int& mliek)
{
    vliek = vyr - vpor * 2;
    mliek = mot - mpor * 2;

}

/*
CERINTA: Având la dispoziţie o imagine color A, pătratică, de dimensiune m x m şi un factor de scală s, unde
implicit m este multiplu întreg de s, să se redimensioneze imaginea A după următorul algoritm:
fiecare bloc de triplete de dimensiune s x s din A este înlocuit în imaginea rezultată M cu un singur
triplet de valori [Rmax Gmax Bmax], calculate ca fiind valorile maxime ale celor trei componente
pentru blocul respectiv. Imaginea A se parcurge de la stânga la dreapta, şi de sus în jos iar blocurile
de valori sunt considerate ca fiind nesuprapuse (disjuncte).
Să se afişeze pe ecran imaginea rezultată M.

EXEMPLU INPUT SI OUTPUT:
Input:
4
2
100 50 100
80 60 100
90 55 98
100 100 100
80 60 90
110 50 80
115 70 180
110 55 160
110 50 80
100 40 70
100 50 80
10 50 20
10 40 83
110 50 80
170 200 70
210 150 180

Output:
110 60 100
115 100 180
110 50 83
210 200 180
*/

#include <iostream>
#include <vector>

using namespace std;

struct Culori{
    int r,g,b;
};

int main() {
    vector<Culori> v;
    //vector<Culori> inc;
    vector<Culori> final;
    struct Culori c;
    struct Culori maxim;
    int m,s,mr=0,mg=0,mb=0;
    cin>>m;
    cin>>s;
    struct Culori A[m][m];
    for(int i=0;i<m*m;i++) {
        cin>>c.r>>c.g>>c.b;
        v.push_back(c);
    }
    int k=0;
    for(int i=0;i<m;i++) {
        for(int j=0;j<m;j++) {
            A[i][j]=v[k];
            k++;
        }
    }
    int a=0,b=0;
    while(b<m) {
        while(a<m) {
            for(int i=b;i<b+s;i++) {
                for(int j=a;j<a+s;j++) {
                    if(A[i][j].r>mr) {
                        mr=A[i][j].r;
                    }
                    if(A[i][j].g>mg) {
                        mg=A[i][j].g;
                    }
                    if(A[i][j].b>mb) {
                        mb=A[i][j].b;
                    }
                }
            }
            maxim.r=mr;
            maxim.g=mg;
            maxim.b=mb;
            final.push_back(maxim);
            mr=0;
            mg=0;
            mb=0;
            a+=s;
            
        }
        a=0;
        b+=s;
    }
    for(int i=0;i<final.size();i++) {
        cout<<final[i].r<<" "<<final[i].g<<" "<<final[i].b<<endl;
    }
    return 0;
}

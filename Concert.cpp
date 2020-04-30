/*
CERINTA: Scrieţi un program care selectează în mod automat concertul cu cost total minim (bilet + transport
dus-întors) la care poţi participa (pentru care eşti disponibil).

EXEMPLU INPUT SI OUTPUT:
Input:
4 4.5 0.06
06 07 15 07
Bucuresti 10 07 200 0
Timisoara 15 07 150 400
Ploiesti 05 08 150 60
Brasov 21 08 180 160

Output:
Ploiesti 160.80
*/

#include <iostream>
#include <iomanip>

using namespace std;

struct Concerte{
    string nume;
    int zi,luna,pret,distanta;
    float prettot;
};

int main() {
    struct Concerte c;
    int n,zii,lunai,zif,lunaf;
    string minn;
    float Pb, Cm, minp=100000;
    cin>>n>>Pb>>Cm;
    cin>>zii>>lunai>>zif>>lunaf;
    for(int i=0;i<n;i++) {
        cin>>c.nume>>c.zi>>c.luna>>c.pret>>c.distanta;
        if(c.luna<lunai) {
            c.prettot=c.pret+((2*c.distanta*Pb*Cm)/3);
            if(c.prettot<minp) {
                minp=c.prettot;
                minn=c.nume;
            }
        }
        else if(c.luna>lunaf) {
            c.prettot=c.pret+((2*c.distanta*Pb*Cm)/3);
            if(c.prettot<minp) {
                minp=c.prettot;
                minn=c.nume;
            }
        }
        else if(c.luna==lunai && lunai!=lunaf) {
            if(c.zi<zii) {
                c.prettot=c.pret+((2*c.distanta*Pb*Cm)/3);
                if(c.prettot<minp) {
                    minp=c.prettot;
                    minn=c.nume;
                }
            }
        }
        else if(c.luna==lunaf && lunai!=lunaf) {
            if(c.zi>zif) {
                c.prettot=c.pret+((2*c.distanta*Pb*Cm)/3);
                if(c.prettot<minp) {
                    minp=c.prettot;
                    minn=c.nume;
                }
            }
        }
        else if(c.luna==lunai && lunai==lunaf) {
            if(c.zi<zii || c.zi>zif) {
                c.prettot=c.pret+((2*c.distanta*Pb*Cm)/3);
                if(c.prettot<minp) {
                    minp=c.prettot;
                    minn=c.nume;
                }
            }
        }

    }
    cout<<minn<<" "<<fixed<<setprecision(2)<<minp<<endl;
    return 0;
}

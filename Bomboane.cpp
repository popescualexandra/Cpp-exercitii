/*
CERINTA: Dându-se un număr n pozitiv, reprezentând numărul de zile în care băiatul primeşte bani de la 
tatăl său, apoi n numere pozitive, reprezentând suma de bani pe care o primeşte băiatul într-o anumită zi,
apoi n perechi de numere pozitive, care reprezintă costul şi aroma bomboanelor din magazin într-o anumită 
zi, să se calculeze numărul de puncte de fericire al lui Andrei. Numărul de puncte de fericire va creşte 
sau va scădea cu numărul pozitiv prin care este reprezentată aroma, conform spuselor din enunţ. Presupunem
că la început Andrei avea 0 lei şi 0 puncte de fericire.

EXEMPLU INPUT SI OUTPUT:
Input:
3
10 10 10
10 20
9 10 
11 50

Output:
80
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> bani;
    int n,b,pb,f,fericire=0,suma=0,max=0;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>b;
        bani.push_back(b);
    }
    for(int i=0;i<n;i++) {
        cin>>pb>>f;
        suma+=bani[i];
        if(suma>=pb) {
            suma-=pb;
            fericire+=f;
            if(f>max) {
                max=f;
            }
        }
        else{
            if(f>=max) {
                fericire-=f;
            }
        }
    }
    cout<<fericire<<endl;
    return 0;
}

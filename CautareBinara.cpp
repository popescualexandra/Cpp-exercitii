/*
CERINTA: Având la dispoziţie un set de valori întregi, distincte, reprezentate sub forma unui vector, v[], să se
localizeze poziţia unei anumite valori, x, specificată de utilizator, folosind un algoritm de căutare
binară. Valorile din vector sunt mai întâi ordonate crescător. Dacă valoarea căutată x este identică
cu valoarea din mijlocul vectorului, atunci algoritmul se încheie şi valoarea a fost găsită. Dacă
valoarea căutată este mai mică decât valoarea din mijlocul vectorului, procesul de căutare se repetă
pentru sub-vectorul stâng, adică prima jumătate a valorilor din vector, comparând cu noua valoare
din mijloc. Dacă valoarea căutată este mai mare decât valoarea din mijlocul vectorului, procesul de
căutare se repetă pentru sub-vectorul drept, adică a doua jumătate a valorilor din vector şi aşa mai
departe. Vectorul este divizat succesiv în două până când, fie este găsită valoarea căutată, fie subvectorul
curent are dimensiunea unu. În cazul în care un sub-vector are un număr par de elemente,
atunci se consideră valoarea din mijloc a vectorului din care provine, ca fiind implicit parte din
acest sub-vector, ceea ce conduce mereu la un sub-vector cu un număr impar de elemente.
Programul va afişa pe ecran toate valorile cu care este comparată valoarea x, adică valorile din
mijloc până la finalizarea procesului de căutare.

EXEMPLU INPUT SI OUTPUT:
Input:
11
20
40
11
54
100
56
67
45
24
21
78
50

Output:
45
67
56
54
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> numere;
    vector<int> v;
    int n,nr,c,mij,copie,ok=1;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>nr;
        v.push_back(nr);
    }
    cin>>c;
    sort(v.begin(),v.end());
    /*
    for(int i=0;i<v.size();i++) {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    */
    while(v.size()>0 && ok==1) {
        mij = (v.size())/2;
        if(c>v[mij] && v.size()%2==1) {
            numere.push_back(v[mij]);
            for(int i=0;i<=mij;i++) {
                v.erase(v.begin());
            }
        }
        else if(c>v[mij] && v.size()%2==0) {
            numere.push_back(v[mij-1]);
            for(int i=0;i<mij;i++) {
                v.erase(v.begin());
            }
        }
        else if(c<v[mij] && v.size()%2==1) {
            numere.push_back(v[mij]);
            copie=v.size();
            for(int i=mij;i<copie;i++) {
                v.erase(v.begin()+mij);
            }
        }
        else if(c<v[mij] && v.size()%2==0) {
            numere.push_back(v[mij]);
            copie=v.size();
            for(int i=mij+1;i<=copie;i++) {
                v.erase(v.begin()+mij);
            }
        }
        else if(v[mij]==c) {
            numere.push_back(v[mij]);
            ok=0;
        }
    }
    
    for(int i=0;i<numere.size();i++) {
        cout<<numere[i]<<endl;
    }
    
    return 0;
}

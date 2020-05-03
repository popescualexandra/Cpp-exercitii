/*
CERINTA: Mobilierul şi celelalte obiecte dintr-o firmă trebuie mutate cu maşinile într-o nouă locaţie. Toate
obiectele au fost ambalate în cutii de diferite mărimi (volume), iar aranjarea lor în maşini se va face
într-o manieră ce urmăreşte minimizarea numărului de maşini de transport necesare. Managerul de
mutare ştie că are un număr suficient de maşini astfel încât să încarce toate cutiile. În fiecare maşină
încap cutii însumând în total un volum D. De asemenea, managerul de mutare ştie câte cutii cu un
anumit volum sunt de încărcat. Regulile de încărcare a maşinilor sunt:
i. se încarcă pe rând câte o maşină;
ii. se alege întotdeauna să se completeze maşina curentă cu cea mai mare cutie disponibilă;
iii. se trece la următoarea maşină numai în condiţiile în care în maşina curentă nu mai poate fi
plasată nicio cutie dintre cele rămase şi
iv. toate cutiile au fost încărcate în maşini.
Scrieţi un program care îl poate ajuta pe managerul de mutare să aranjeze cutiile în maşini în mod
eficient, conform regulilor enunţate mai sus.

EXEMPLU INPUT SI OUTPUT:
Input:
200 5
2 130
4 120
2 80
3 60
7 50

Output:
130 60
130 60
120 80
120 80
120 60
120 50
50 50 50 50
50 50
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> nr;
    vector<int> afis;
    int D,k,n,p,s=0;
    cin>>D>>k;
    for(int i=0;i<k;i++) {
        cin>>n>>p;
        for(int j=0;j<n;j++) {
            nr.push_back(p);
        }
    }
    while(nr.size()>0) {
        for(int i=0;i<nr.size();i++) {
            if(s+nr[i]<=D) {
                s+=nr[i];
                afis.push_back(nr[i]);
                nr.erase(nr.begin()+i);
                i--;
            }
        }
        for(int i=0;i<afis.size();i++) {
            cout<<afis[i]<<" ";
        }
        afis.clear();
        s=0;
        cout<<endl;
    }
    return 0;
}

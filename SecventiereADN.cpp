/*
CERINTA: În cadrul domeniului bioinformaticii, echipamentele de secvențiere de ADN preiau o probă
biologică și produc un fișier text ce conține secvența de ADN detectată. Se cunoaște faptul că o secvență 
de ADN este reprezentată printr-un lung șir de caractere A, T, C și G, reprezentând nucleotidele Adenină, 
Timină, Guanină și Citozină. De asemenea, se cunoaște faptul că ADN-ul este format din două secvențe în 
oglindă, precum se vede în imaginea de mai jos, unde o nucleotidă A se leagă întotdeauna cu o nucleotidă
T, iar o nucleotidă C cu una G, și invers. În plus, a doua secvență este citită întotdeauna de 
echipamentul de secvențiere în sens invers decât prima (de la sfârșit la început). Dându-se un șir de ADN 
primit de la un echipament de secvențiere ce reprezintă concatenarea ambelor secvențe în ordinea săgeții 
din imagine, să se determine dacă citirea e corectă (dacă aparține unei perechi de secvențe de ADN valide).

EXEMPLU INPUT SI OUTPUT:
Input:
ATCATCGTAACGTACGTTACGAAGAT

Output:
4
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<char> ADN;
    vector<char> ADN2;
    int ok=1,index;
    char p;
    char c;
    while(cin>>c) {
        ADN.push_back(c);
    }
    int n=ADN.size();
    for(int i=0;i<n/2;i++) {
        p=ADN.size()-1;
        ADN2.push_back(ADN[p]);
        ADN.erase(ADN.begin()+p);
    }
    for(int i=0;i<ADN.size();i++) {
        if((ADN[i]=='A' && ADN2[i]=='T') || (ADN[i]=='T' && ADN2[i]=='A') || (ADN[i]=='C' && ADN2[i]=='G') || (ADN[i]=='G' && ADN2[i]=='C')) {
            ok=1;
        }
        else{
            ok=0;
            index = i+1;
            break;
        }
    }
    if(ok==1) {
        cout<<"0"<<endl;
    }
    else {
        cout<<index<<endl;
    }
    return 0;
}

/*
CERINTA: Dându-se un număr n pozitiv reprezentand numărul de elemente din şir, apoi cele n elemente ale 
şirului, să se verifice dacă şirul este supra-crescător, iar dacă acesta nu este supracrescător, să se
modifice termenii necorespunzători (modificând cel mai mic număr de termeni), astfel încât să se genereze
un şir supra-crescător. Şirul este acceptat dacă şirul iniţial a fost supra-crescător sau dacă şirul 
corectat a necesitat cel mult 3 corecţii pe poziţii din prima jumătate a şirului.

EXEMPLU INPUT SI OUTPUT:
Input:
5 
2 
22 
24 
100
500

Output:
1 
3 
ACCEPT
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> numere;
    vector<int> sch;
    int n,nr,schimb=0,suma=0,schimbp=0;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>nr;
        numere.push_back(nr);
    }
    for(int i=0;i<numere.size();i++) {
        if(numere[i]<=suma) {
            numere[i] = suma+1;
            sch.push_back(i+1);
            schimb++;
            if(i<=numere.size()/2) {
                schimbp++;
            }
        }
        suma+=numere[i];
    }
    cout<<schimb<<endl;
    for(int i=0;i<sch.size();i++) {
        cout<<sch[i]<<endl;
    }
    if(schimbp>=3 || schimb-schimbp>0) {
        cout<<"RESPINS"<<endl;
    }
    else {
        cout<<"ACCEPT"<<endl;
    }
    return 0;
}

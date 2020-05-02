/*
CERINTA: Să se afle cel mai mare număr natural m, scris în baza 10, a cărui scriere în baza 2 se poate 
obține prin una sau mai multe permutări circulare ale scrierii în baza 2 a numărului n.

EXEMPLU INPUT SI OUTPUT:
Input:
13

Output:
14
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    vector<int> da;
    int n,c,numar=0,maxim=0,copie;
    cin>>n;
    while(n>0) {
        c=n%2;
        da.push_back(c);
        n=n/2;
    }
    for(int j=0;j<da.size();j++) {
        for(int i=0;i<da.size();i++) {
            numar += da[i]*pow(2,i);
        }
        if(numar>maxim) {
            maxim=numar;
        }
        numar=0;
        copie=da[0];
        da.erase(da.begin());
        da.push_back(copie);
        }
    cout<<maxim<<endl;
    return 0;
}

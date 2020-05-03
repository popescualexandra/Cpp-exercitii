/*
CERINTA: Într-o succesiune de numere naturale întâlnite pe Pământ, ET observă că unele sume parțiale ale
acestor numere se divid cu 3 în timp ce alte sume parțiale nu se divid. ET și-a pus problema următoare: 
dacă am un șir de n numere naturale, care este numărul maxim de elemente ale acestui șir a căror sumă se
divide cu 3? Pentru că datele le obține printr-un program generat pe loc și rulat imediat în memoria sa
internă, el poate afla şi care este această sumă, dacă ea există. Fiind dată o succesiune de n numere
naturale, determinați numărul maxim de elemente succesive din seria dată ce alcătuiesc o secvenţă a cărei 
sumă se divide cu 3 precum şi valoarea sumei respective.

EXEMPLU INPUT SI OUTPUT:
Input:
7
10
6
7
12
4
7
19

Output:
5 39
*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> nr;
    int n,a,k,count=0,S=0,ok=0;
    int Smax, nmax;
    cin>>n;
    k=n;
    for(int i=0;i<n;i++) {
        cin>>a;
        nr.push_back(a);
    }
    while(k>0) {
        while(k+count<=n) {
            for(int i=count;i<k+count;i++) {
                S=S+nr[i];
            }
            if(S%3==0 && S!=0) {
                Smax=S;
                nmax=k;
                ok=1;
                break;
            }
            count++;
            S=0;
        }
        if(ok==1) {
            break;
        }
        else{
            k--;
            count=0;
        }
    }
    if(ok==0) {
        cout<<"0"<<endl;
    }
    else{
        cout<<nmax<<" "<<Smax<<endl;
    }
    return 0;
}

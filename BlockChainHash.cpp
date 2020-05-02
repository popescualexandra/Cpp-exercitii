/*
CERINTA: Se dau două numere naturale N şi k și apoi încă N numere naturale. Se cere să se determine 
valoarea maximă a hash-ului care se va obține aplicând algoritmul de hash celor N numere folosind k 
pentru numărul de iterații de transformare, conform descrierii de mai sus.

EXEMPLU INPUT SI OUTPUT:
Input:
2 2
5734 1234

Output:
264
*/

#include <iostream>

using namespace std;

int main() {
    int n,k,nr,copie,copie2=0,F=0, final=0,c,countcifre=0,c1,c2,maxim=0;
    cin>>n>>k;
    for(int i=0;i<n;i++) {
        cin>>nr;
        copie=nr;
        for(int j=0;j<k;j++) {
            while(copie>0) {
                c=copie%10;
                countcifre++;
                copie2 = copie2*10+c;
                copie/=10;
            }
            //cout<<copie2<<" ";
            if(countcifre>1) { 
                for(int p=1;p<countcifre;p++) {
                    c1=copie2%10;
                    copie2/=10;
                    c2=copie2%10;
                    if(c1>c2) {
                        final=final*10+(c1-c2);
                    }
                    else {
                        final=final*10+(c2-c1);
                    }
                }
            }
            else if(countcifre==1) {
                final=copie2;
            }
            //cout<<final<<" ";
            F+=final;
            countcifre=0;
            copie2=0;
            copie=final;
            final=0;
        }
        cout<<endl;
        if(F>maxim) {
            maxim=F;
        }
        F=0;
    }
    cout<<maxim<<endl;
    return 0;
}

/*
CERINTA: Împreună cu echipa de la firmă ați inventat un nou algoritm de generare de numere 
pseudo-aleatoare. Pentru a valida că generatorul poate fi folosit în algoritmi criptografici 
(cryptographically secure) trebuie să implementați și să rulați o baterie de teste. Unul din aceste 
teste verifică numărul de apariții pentru fiecare secvență posibilă de doi biți: 00, 01, 10 și 11 cât 
și raportul între numărul de biți de 0 și de 1. Pentru ca secvența de biți să fie aleatoare, trebuie 
ca numărul de apariții pentru fiecare din cele patru perechi să fie aproximativ egale și în același timp 
numărul de biți de 0 să fie aproximativ egal cu cei de 1. Mai precis, trebuie ca raporturile R1 dintre 
numărul de apariții a perechii care apare de cele mai multe ori și numărul de apariții a perechii care 
apare de cele mai puține ori, cât și raportul R2 între numărul de apariții ale celui mai frecvent bit și
numărul de apariții ale celui mai puțin frecvent bit să fie mai mici sau egale cu 110%. Dându-se un număr 
n reprezentând numărul de biți generat de RNG și secvența de n biți, să se calculeze raporturile 
R1 și R2 și să se decidă dacă generatorul este valid sau nu.

EXEMPLU INPUT SI OUTPUT:
Input:
18
101100110111100001

Output:
1.50 1.25
0
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    vector<char> biti;
    vector<float> aparitii;
    int n;
    float aoo=0,aou=0,auo=0,auu=0,ao=0,au=0;
    char b;
    float r1,r2;
    cin>>n;
    for(int j=0;j<n;j++) {
        cin>>b;
        biti.push_back(b);
    }
    //cout<<endl;
    int i=0;
    while(i<biti.size()-1) {
        if(biti[i]=='0' && biti[i+1]=='0') {
            aoo++;
        }
        else if(biti[i]=='0' && biti[i+1]=='1') {
            aou++;
        }
        else if(biti[i]=='1' && biti[i+1]=='0') {
            auo++;
        }
        else if(biti[i]=='1' && biti[i+1]=='1') {
            auu++;
        }
        i+=2;
    }
    //cout<<aoo;
    aparitii.push_back(aoo);
    aparitii.push_back(aou);
    aparitii.push_back(auo);
    aparitii.push_back(auu);
    sort(aparitii.begin(),aparitii.end());
    //cout<<aparitii[3]<<" "<<aparitii[0];
    r1=aparitii[3]/aparitii[0];
    for(int k=0;k<biti.size();k++) {
        if(biti[k]=='0') {
            ao++;
        }
        else {
            au++;
        }
    }
    if(au>ao) {
        r2=au/ao;
    }
    else {
        r2=ao/au;
    }
    cout<<fixed<<setprecision(2)<<r1<<" "<<fixed<<setprecision(2)<<r2<<endl;
    if(r1*100<=110 && r2*100<=110) {
        cout<<"1"<<endl;
    }
    else {
        cout<<"0"<<endl;
    }
    return 0;
}

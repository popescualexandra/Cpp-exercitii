/*
CERINTA: Trebuie să scrieți un software pentru un atelier de reparații laptopuri care să ajute tehnicienii
să rezolve problemele care apar. Atelierul are în stoc componente din fiecare din următoarele categorii:
carcasă, tastatură, placă de bază, ecran, procesor, memorie și SSD. Pentru ca un laptop să funcționeze 
corect, acesta trebuie să aibă câte una din fiecare din componentele de mai sus, funcționale. În service 
vin laptopuri în care una sau mai multe din componente pot fi defecte, caz în care trebuie înlocuite sau 
laptopuri cu toate componentele funcționale (dar cu softul virusat), care nu necesită nicio reparație
hardware. Dacă un laptop nu poate fi reparat din lipsă de piese, el este dezasamblat imediat, și 
componentele sale funcționale sunt folosite pentru a repara alte laptopuri care intră în service mai
târziu. Dându-se numărul de piese din stocul original al atelierului și laptopurile care vin în service, 
împreună cu piesele defecte și funcționale pentru fiecare, să se determine și să se afișeze câte laptopuri
va repara atelierul.

EXEMPLU INPUT SI OUTPUT:
Input:
3 4 1 3 0 4 5
4
1 0 1 1 0 1 1
0 1 0 1 1 1 1
1 1 0 1 1 1 1
1 1 1 1 1 1 1

Output:
3
*/

#include <iostream>

using namespace std;

int main() {
    int C,T,PB,E,P,M,SSD;
    int c,t,pb,e,p,m,ssd;
    int ok=1,reparate=0;
    int n;
    cin>>C>>T>>PB>>E>>P>>M>>SSD;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>c>>t>>pb>>e>>p>>m>>ssd;
        if(c==0) {
            if(C==0) {
                ok=0;
                T+=t;
                PB+=pb;
                E+=e;
                P+=p;
                M+=m;
                SSD+=ssd;
                //break;
            }
        }
        if(t==0) {
            if(T==0) {
                ok=0;
                C+=c;
                PB+=pb;
                E+=e;
                P+=p;
                M+=m;
                SSD+=ssd;
                //break;
            }
        }
        if(pb==0) {
            if(PB==0) {
                ok=0;
                C+=c;
                T+=t;
                E+=e;
                P+=p;
                M+=m;
                SSD+=ssd;
                //break;
            }
        }
        if(e==0) {
            if(E==0) {
                ok=0;
                C+=c;
                T+=t;
                PB+=pb;
                P+=p;
                M+=m;
                SSD+=ssd;
                //break;
            }
        }
        if(p==0) {
            if(P==0) {
                ok=0;
                C+=c;
                T+=t;
                PB+=pb;
                E+=e;
                M+=m;
                SSD+=ssd;
                //break;
            }
        }
        if(m==0) {
            if(M==0) {
                ok=0;
                C+=c;
                T+=t;
                PB+=pb;
                E+=e;
                P+=p;
                SSD+=ssd;
                //break;
            }
        }
        if(ssd==0) {
            if(SSD==0) {
                ok=0;
                C+=c;
                T+=t;
                PB+=pb;
                E+=e;
                P+=p;
                M+=m;
                //break;
            }
        }
        if(ok==1) {
            reparate++;
            if(c==0) {
                C--;
            }
            if(t==0) {
                T--;
            }
            if(pb==0) {
                PB--;
            }
            if(e==0) {
                E--;
            }
            if(p==0) {
                P--;
            }
            if(m==0) {
                M--;
            }
            if(ssd==0) {
                SSD--;
            }
        }
        ok=1;
    }
    cout<<reparate<<endl;
    return 0;
}

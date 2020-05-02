/*
CERINTA: Dându-se ora la care ajungeți la cinematograf, scrieți un program care să selecteze din lista 
de filme pe cel care respectă cel mai bine dorințele voastre.

EXEMPLU INPUT SI OUTPUT:
Input:
16:45
4
18:00 15 Bohemian-Rhapsody
16:50 20 Mos-Craciun-in-misiune
12:00 13 Creed-II
16:55 20 Grinch

Output:
Mos-Craciun-in-misiune
*/

#include <iostream>
#include <vector>

using namespace std;

struct film{
    int h, m,pret;
    char ch;
    string nume;
};

int main() {
    vector<film> filme;
    vector<film> final;
    int ora, minut;
    char c;
    string fin;
    cin>>ora>>c>>minut;
    int n;
    cin>>n;
    struct film f;
    for(int i=0;i<n;i++) {
        cin>>f.h>>f.ch>>f.m>>f.pret>>f.nume;
        filme.push_back(f);
    }
    for(int i=0;i<n;i++) {
        if(ora==filme[i].h) {
            if(minut<=filme[i].m) {
                final.push_back(filme[i]);
            }
        }
    }
    if(final.size()==0) {
        for(int i=0;i<n;i++) {
            if(ora<filme[i].h) {
                final.push_back(filme[i]);
            }    
        }
    }
    int minh = 24, minm = 59, minp = 100;
    for(int i=0;i<final.size();i++) {
        if(final[i].h<minh) {
            minh = final[i].h;
        }
        if(final[i].h==minh) {
            if(final[i].m<=minm) {
                minm=final[i].m;
                //fin = final[i].nume;
            }
        }
    }
    for(int i=0;i<final.size();i++) {
        if(final[i].m==minm && final[i].h==minh) {
            if(final[i].pret<=minp) {
                minp=final[i].pret;
                fin = final[i].nume;
            }
        }
    }
    
    cout<<fin<<endl;
    return 0;
}

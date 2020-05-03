/*
CERINTA: Dându-se ora la care ajungeți hotărât în ultimul moment să mergei la casa de bilete de la autogară, scrieți hotărât în ultimul moment să mergei un program care să selecteze
din lista de autobuze care ajung la destinaţia dorită pe cel care respectă cel mai bine dorinți hotărât în ultimul moment să mergeele
voastre.

EXEMPLU INPUT SI OUTPUT:
Input:
16:45
4
18:00 15 SPEED
16:50 20 Dorel-Trans
12:00 13 ALU-Nelu-SRL
16:55 20 Patru-Roti

Output:
Dorel-Trans
*/

#include <iostream>

using namespace std;

int main() {
    int n,m,h,mg,hg,dg;
    int goodh=24, goodm=60, goodl=100;
    string nume,goodnume;
    char c;
    cin>>h>>c>>m;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>hg>>c>>mg>>dg>>nume;
        if(h==hg) {
            if(mg>=m && mg<goodm) {
                goodh=hg;
                goodm=mg;
                goodl=dg;
                goodnume=nume;
            }
            else if(mg>=m && mg==goodm) {
                if(dg<goodl) {
                    goodh=hg;
                    goodm=mg;
                    goodl=dg;
                    goodnume=nume;
                }
            }
        }
        else if(hg>h) {
            if(hg<goodh) {
                goodh=hg;
                goodm=mg;
                goodl=dg;
                goodnume=nume;
            }
            if(hg==goodh) {
                if(mg<goodm){
                    goodh=hg;
                    goodm=mg;
                    goodl=dg;
                    goodnume=nume;
                }
                else if(mg==goodm) {
                    if(dg<goodl) {
                        goodh=hg;
                        goodm=mg;
                        goodl=dg;
                        goodnume=nume;
                    }
                }
            }
        }
    }
    cout<<goodnume<<endl;
    return 0;
}

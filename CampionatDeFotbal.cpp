/*
EXEMPLU DE INPUT SI OUTPUT:
Input:
4
6
Romania 4 – 0 Franta
Italia 2 – 1 Rusia
Franta 3 – 0 Italia
Rusia 2 – 2 Romania
Romania 1 – 0 Italia
Franta 2 – 1 Rusia

Output:
Romania 7 7 2
Franta 6 5 5
Italia 3 2 5
Rusia 1 4 6
*/

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool sortare(int a, int b) {
    return a>b;
}

int main() {
    vector<int> maxim;
    map<string,int> puncte;
    map<string,int> inscrise;
    map<string,int> primite;
    string echipa1, echipa2;
    int gol1, gol2, max=0;
    char c;
    int k, n;
    cin>>k>>n;
    for(int i=0;i<n;i++) {
        cin>>echipa1>>gol1>>c>>gol2>>echipa2;
        inscrise[echipa1] += gol1;
        primite[echipa1] += gol2;
        inscrise[echipa2] += gol2;
        primite[echipa2] += gol1;
        if(gol1>gol2) {
            puncte[echipa1] += 3;
            puncte[echipa2] += 0;
        }
        else if(gol1==gol2) {
            puncte[echipa1] += 1;
            puncte[echipa2] += 1;
        }
        else if(gol1<gol2) {
            puncte[echipa2] +=3;
            puncte[echipa1] +=0;
        }
    }
    
    for(pair<string,int> p:puncte) {
        maxim.push_back(p.second);
    }
    sort(maxim.begin(),maxim.end(),sortare);
    for(int i=0;i<maxim.size();i++) {
        for(pair<string,int> pair1:puncte) {
            for(pair<string,int> pair2:inscrise) {
                for(pair<string,int> pair3:primite) {
                    if(maxim[i]==pair1.second && pair1.first==pair2.first && pair1.first==pair3.first && pair2.first==pair3.first) {
                        cout<<pair1.first<<" "<<pair1.second<<" "<<pair2.second<<" "<<pair3.second<<endl;
                    }
                }
            }
        }
    }
    return 0;
}

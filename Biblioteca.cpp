/*
CERINTA: Cărţile din biblioteca UPB trebuie mutate într-o nouă locaţie, iar aranjarea lor pe rafturi se 
va face într-o manieră inovativă, urmărindu-se minimizarea numărului de rafturi necesare. Bibliotecara 
știe că are un număr suficient de rafturi încât să pună toate cărțile. Pe fiecare raft încap cărți
însumând în total D pagini. De asemenea, ştie câte cărţi cu un anumit număr de pagini există în bibliotecă.
Dat fiind acestea şi urmărind să ocupe cât mai puţine rafturi, bibliotecara şi-a propus să aranjeze 
cărţile pe rafturi:
i. raft după raft,
ii. alegând întotdeauna să completeze raftul curent cu cea mai groasă carte disponibilă,
iii. trecând la următorul raft numai în condiţiile în care pe raftul curent nu mai poate fi plasată 
nicio carte dintre cele rămase şi
iv. asigurându-se că a plasat pe rafturi toate cărţile.
Scrieţi un program care o poate ajuta pe bibliotecară să aranjeze cărţile pe rafturi în mod eficient,
conform regulilor enunţate mai sus.

EXEMPLU INPUT SI OUTPUT:
Input:
200 5
2 130
4 120
2 80
3 60
7 50

Output:
130 60
130 60
120 80
120 80
120 60
120 50
50 50 50 50
50 50
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> nr;
    vector<int> afis;
    int D,k,n,p,s=0;
    cin>>D>>k;
    for(int i=0;i<k;i++) {
        cin>>n>>p;
        for(int j=0;j<n;j++) {
            nr.push_back(p);
        }
    }
    while(nr.size()>0) {
        for(int i=0;i<nr.size();i++) {
            if(s+nr[i]<=D) {
                s+=nr[i];
                afis.push_back(nr[i]);
                nr.erase(nr.begin()+i);
                i--;
            }
        }
        for(int i=0;i<afis.size();i++) {
            cout<<afis[i]<<" ";
        }
        afis.clear();
        s=0;
        cout<<endl;
    }
    return 0;
}

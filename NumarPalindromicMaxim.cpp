/*
CERINTA: Un studiu de marketing cerut de o galerie de artă mai excentrică a arătat că, în mod surprinzător,
clienţii analizează o perioadă mai mare de timp exponatele care au preţuri ce pot fi exprimate ca un
palindrom şi de obicei le preferă, chiar şi în cazul în care un alt obiect similar are un preţ ceva mai
scăzut. Pe de altă parte, din anumite motive (doar de ei ştiute) artiştii, care creează aceste produse,
vor ca numerele care definesc preţul unui obiect de artă sa fie atent elaborate şi să conţină doar
anumite cifre considerate de ei ca fiind foarte importante. Sub aceste constrângeri, proprietarii
galeriei de artă vor să maximizeze câştigurile şi să afişeze cele mai mari preţuri posibile în
condiţiile menţionate.
Astfel, se cere să se realizeze un program care interpretează o secvenţă de cifre nenule oferite la
intrare, în vederea obţinerii unor reprezentări zecimale (numere în bază 10). Plecând de la cifrele
oferite sunt posibile mai multe reprezentări zecimale. Dintre numerele zecimale astfel obţinute se va
alege cel mai mare număr care are proprietatea de palindrom (vedeţi explicaţiile de mai jos).

EXEMPLU INPUT SI OUTPUT:
Input:
6
5 9 8 5 9 8

Output:
985589
*/

#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
#include <stack>
#include <algorithm>

using namespace std;

bool sortare(int a, int b) {
    return a>b;
}

int main() {
    map<int,int> cifre;
    stack<int> st;
    vector<int> ord;
    int n,m,count=0,element;
    int k=0,ok=0;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>m;
        cifre[m]++;
        ord.push_back(m);
    }
    sort(ord.begin(),ord.end(),sortare);
    for(pair<int,int>p:cifre) {
        if(p.second%2==1) {
            count++;
        }
    }
    if(count>1) {
        cout<<"0"<<endl;
    }
    else {
        while(ord.size()!=0) {
            if(cifre[ord[k]]%2==0 && cifre[ord[k]]!=0) {
                cout<<ord[k];
                st.push(ord[k]);
                cifre[ord[k]]=cifre[ord[k]]-2;
                                ord.erase(ord.begin());
                ord.erase(ord.begin());
            }
            else if(cifre[ord[k]]%2==1 && cifre[ord[k]]>1) {
                cout<<ord[k];
                st.push(ord[k]);
                cifre[ord[k]]=cifre[ord[k]]-2;
                ord.erase(ord.begin());
                ord.erase(ord.begin());
            }
            else if(cifre[ord[k]]==1) {
                element=ord[k];
                
                ok=1;
                cifre[ord[k]]=cifre[ord[k]]-1;
                ord.erase(ord.begin());
            }
        }
        if(ok==1) {
            cout<<element;
        }
        while(st.size()!=0) {
            cout<<st.top();
            st.pop();
        }
    }
    cout<<endl;
    return 0;
}

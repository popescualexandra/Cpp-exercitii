/*
CERINTA: Scrieţi un program care verifică dacă o grilă de Sudoku este completată corect sau nu.

EXEMPLU INPUT SI OUTPUT:
Input:
1 2 3 4 5 6 7 8 9
4 5 6 7 8 9 1 2 3
7 8 9 1 2 3 4 5 6
2 3 4 5 6 7 8 9 1
5 6 7 8 9 1 2 3 4
8 9 1 2 3 4 5 6 7
3 4 5 6 7 8 9 1 2
6 7 8 9 1 2 3 4 5
9 1 2 3 4 5 6 7 8

Output:
Corect
*/

#include <iostream>
#include <vector>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v;
    vector<int> verif;
    int n,ok=1,count=0;;
    for(int i=0;i<81;i++) {
        cin>>n;
        v.push_back(n);
    }
    for(int i=0;i<9;i++) {
        for(int j=0;j<9;j++) {
            verif.push_back(v[(9*i)+j]);
        }
        sort(verif.begin(),verif.end());
        for(int k=0;k<verif.size()-1;k++) {
            if(verif[k+1]!=verif[k]+1) {
                ok=0;
                break;
            }
        }
        verif.clear();
    }
    for(int i=0;i<9;i++) {
        for(int j=0;j<9;j++) {
            verif.push_back(v[(9*j)+i]);
        }
        sort(verif.begin(),verif.end());
        for(int k=0;k<verif.size()-1;k++) {
            if(verif[k+1]!=verif[k]+1) {
                ok=0;
                break;
            }
        }
        verif.clear();
    }
    int a,b,c=0,d=0;
    while(c<9 && d<9) {
        for(a=c;a<c+3;a++) {
            for(b=d;b<d+3;b++) {
                verif.push_back(v[(9*a)+b]);
                cout<<v[(9*a)+b]<<" ";
                
            }
            b=d;
        }
        cout<<endl;
        count++;
        sort(verif.begin(),verif.end());
        for(int k=0;k<verif.size()-1;k++) {
            if(verif[k+1]!=verif[k]+1) {
                ok=0;
                break;
            }
        }
        verif.clear();
        d+=3;
        if(count<2) {
            c=0;
            //count=0;
        }
        else if(count>=2 && count<5) {
            c=3;
        }
        else if(count>=5 && count<8){
            c=6;
        }
        
    }
    if(ok==1) {
        cout<<"Corect"<<endl;
    }
    else{
        cout<<"Gresit"<<endl;
    }
    return 0;
}

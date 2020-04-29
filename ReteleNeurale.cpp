/*
EXEMPLU INPUT SI OUTPUT:
Input:
3 5 2
1 -2 3 4 5
8 5 -3 1 1
7 6 4 -2 0
4 1
2 9
7 2
1 1
2 8
4 5 6

Output:
2
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<float> v;
    vector<float> w;
    vector<float> x;
    vector<float> s;
    vector<float> y;
    int m,n,p;
    float nr,suma=0,t,j=0,k=0,maxim=0,index;
    cin>>m>>n>>p;
    for(int i=0;i<m*n;i++) {
        cin>>nr;
        v.push_back(nr);
    }
    for(int i=0;i<n*p;i++) {
        cin>>nr;
        w.push_back(nr);
    }
    for(int i=0;i<m;i++) {
        cin>>nr;
        x.push_back(nr);
    }
    while(j<n) {
        for(int i=0;i<m;i++) {
            t=x[i]*v[n*i+j];
            suma+=t;
        }
        s.push_back(suma);
        suma=0;
        j++;
    }
    while(k<p) {
        for(int i=0;i<s.size();i++) {
            t=s[i]*w[p*i+k];
            suma+=t;
        }
        y.push_back(suma);
        suma=0;
        k++;
    }
    for(int i=0;i<y.size();i++) {
        if(y[i]>maxim) {
            maxim=y[i];
            index=i;
        }
    }
    cout<<index+1<<endl;
    return 0;
}

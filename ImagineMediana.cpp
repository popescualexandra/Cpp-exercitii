/*
EXEMPLU INPUT SI OUTPUT:
Input:
3
3
0
3
1
0
4
3
255
4
255

Output:
0
1
1
0
3
3
0
4
3
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> so;
    vector<int> v;
    int m,n,nr;
    cin>>m;
    cin>>n;
    int A[m+2][n+2];
    int B[m+2][n+2];
    for(int i=0;i<m*n;i++) {
        cin>>nr;
        v.push_back(nr);
    }
    int k=0;
    for(int i=0;i<m+2;i++) {
        for(int j=0;j<n+2;j++) {
            if(i==0 || j==0 || i==m+1 || j==n+1) {
                A[i][j]=0;
            }
            else {
                A[i][j]=v[k];
                k++;
            }
        }
    }
    for(int i=1;i<m+1;i++) {
        for(int j=1;j<n+1;j++) {
            so.push_back(A[i-1][j]);
            so.push_back(A[i][j-1]);
            so.push_back(A[i][j]);
            so.push_back(A[i][j+1]);
            so.push_back(A[i+1][j]);
            sort(so.begin(),so.end());
            B[i][j]=so[2];
            so.clear();
        }
    }
    for(int i=1;i<m+1;i++) {
        for(int j=1;j<n+1;j++) {
            cout<<B[i][j]<<endl;
        }
    }
    return 0;
}

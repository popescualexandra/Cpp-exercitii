/*
EXEMPLU INPUT SI OUTPUT:
Input:
3
4 3 2 1 0 -1 -2 -3 -4 -3
3 2 1 0 -1 -2 -3 -4 -3 -2
2 1 0 -1 -2 -3 -4 -3 -2 -1

Output:
3.00 2.00 1.00 0.00 -1.00 -2.00 -3.00 -3.33 -3.00 -2.00
1.33 2.00 2.00 1.00 0.00 -1.00 -2.00 -3.00 -4.00 -3.00
1.33 1.00 1.67 1.00 1.00 0.00 -1.00 -2.00 -3.00 -3.33
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n, b;
    float c,suma=0;
    float A[65536][10];
    float D0[10];
    float copie[65536][10];
    float D1[10];
    float D2[10];
    cin>>n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<10;j++) {
            cin>>c;
            A[i][j]=c;
        }
    }
    //DD=0
    b=0;
    while(b<10) {
        for(int i=0;i<n;i++) {
            suma+=A[i][b];
        }
        D0[b]=suma/n;
        suma=0;
        b++;
    }
    for(int i=0;i<10;i++) {
        cout<<fixed<<setprecision(2)<<D0[i]<<" ";
    }
    cout<<endl;
    //DD=1;
    for(int i=0;i<n;i++) {
        for(int j=0;j<10;j++) {
            copie[i][j]=A[i][j];
        }
    }
    b=n-1;
    while(b>0) {
        for(int j=9;j>=0;j--) {
            copie[b][j]=copie[b][j-b];
        }
        b--;
    }
    for(int i=1;i<n;i++) {
        for(int a=0;a<i;a++) {
            copie[i][a]=0;
        }
    }
    suma=0;
    b=0;
    while(b<10) {
        for(int i=0;i<n;i++) {
            suma+=copie[i][b];
        }
        D1[b]=suma/n;
        suma=0;
        b++;
    }
    for(int i=0;i<10;i++) {
        cout<<fixed<<setprecision(2)<<D1[i]<<" ";
    }
    cout<<endl;
    //D2
    for(int i=0;i<n;i++) {
        for(int j=0;j<10;j++) {
            copie[i][j]=A[i][j];
        }
    }
    b=n-1;
    while(b>0) {
        for(int j=9;j>=0;j--) {
            copie[b][j]=copie[b][j-b*2];
        }
        b--;
    }
    for(int i=1;i<n;i++) {
        for(int a=0;a<i*2;a++) {
            copie[i][a]=0;
        }
    }
    suma=0;
    b=0;
    while(b<10) {
        for(int i=0;i<n;i++) {
            suma+=copie[i][b];
        }
        D2[b]=suma/n;
        suma=0;
        b++;
    }
    for(int i=0;i<10;i++) {
        cout<<fixed<<setprecision(2)<<D2[i]<<" ";
    }
    cout<<endl;
    return 0;
}

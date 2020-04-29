/*
CERINTA: Scrieţi un program care, primind la intrare coordonatele în spaţiu ale planetelor şi punctul de start,
să calculeze distanţa totală parcursă de navă pentru vizitarea tuturor planetelor.

EXEMPLU INPUT SI OUTPUT:
Input:
4
0 2 0
10 2 0
10 0 0
0 0 0
5 1 0

Output:
19.10
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct Planete{
    float x,y,z;
};

int main() {
    vector<Planete> v;
    struct Planete p;
    int n,index;
    float dmin=10000000,d,df=0;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>p.x>>p.y>>p.z;
        v.push_back(p);
    }
    cin>>p.x>>p.y>>p.z;
    while(v.size()>0) {
        for(int i=0;i<v.size();i++) {
            d=sqrt((p.x-v[i].x)*(p.x-v[i].x)+(p.y-v[i].y)*(p.y-v[i].y)+(p.z-v[i].z)*(p.z-v[i].z));
            if(d<dmin) {
                dmin=d;
                index=i;
            }
        }
        p.x=v[index].x;
        p.y=v[index].y;
        p.z=v[index].z;
        df+=dmin;
        dmin=10000000;
        v.erase(v.begin()+index);
    }
    cout<<fixed<<setprecision(2)<<df<<endl;
    return 0;
}

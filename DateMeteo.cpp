/*
CERINTA: Scrieţi un program care, pe baza temperaturilor înregistrate pe parcursul a N zile consecutive,
determină o secvenţă de zile având lungime maximă, pentru care temperaturile înregistrate au alternat ca 
semn. Dacă există mai multe astfel de secvenţe, meteorologii sunt interesaţi de cea mai recentă. Dacă nu 
există măcar două zile consecutive cu temperaturi alternante ca semn, ei vor înregistra rezultatul 0, 
neavând date suficiente pentru calcule suplimentare. În plus, meteorologii sunt interesați și de procentul 
valorilor pozitive și negative înregistrate pe parcursul celor N zile.

EXEMPLU INPUT SI OUTPUT:
Input:
9
0 -2 0 -1 -2 3 -2 -3 3

Output:
4
0 -2 0 -1
+:44.44% -:55.56%
*/

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main(){
    vector<int> temp;
    vector<int> in;
    vector<int> bune;
    int n,t,count=0,copie=0;
    float cp=0, cn=0,p,ne;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>t;
        temp.push_back(t);
    }
    for(int i=0;i<temp.size();i++) {
        if(temp[i]>=0 && temp[i+1]<0) {
            count++;
            in.push_back(temp[i]);
        }
        else if(temp[i]<0 && temp[i+1]>=0) {
            count++;
            in.push_back(temp[i]);
        }
        else{
            count++;
            in.push_back(temp[i]);
            if(count>=copie) {
                copie=count;
                bune.clear();
                for(int j=0;j<in.size();j++) {
                    bune.push_back(in[j]);
                }
            }
            count=0;
            in.clear();
        }
        if(i==temp.size()-1){
            //count++;
            //in.push_back(temp[i]);
            if(count>copie) {
                copie=count;
                bune.clear();
                for(int j=0;j<in.size();j++) {
                    bune.push_back(in[j]);
                }
            }
            count=0;
            in.clear();
        }
    }
    for(int i=0;i<temp.size();i++) {
        if(temp[i]>=0) {
            cp++;
        }
        else {
            cn++;
        }
    }
    if(copie>=2) {
        cout<<copie<<endl;
        for(int i=0;i<bune.size();i++) {
            cout<<bune[i]<<" ";
        }
        cout<<endl;
        p=(cp*100)/temp.size();
        ne=100-p;
        cout<<"+:"<<fixed<<setprecision(2)<<p<<"% -:"<<fixed<<setprecision(2)<<ne<<"%"<<endl;
    }
    else {
        cout<<"0"<<endl;
    }
    return 0;
}

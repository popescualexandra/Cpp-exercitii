/*
CERINTA: Prognoza preţului Bitcoin este un lucru care vă interesează foarte mult pentru că aţi putea să
tranzacţionaţi online în momentele propice reuşind astfel să câştigaţi mulţi bani. Aţi aflat şi despre 
un algoritm simplu de prognoză care funcţionează bine în anumite condiţii şi v-ati propus să-l implementaţi.
Algoritmul prezice preţul de la momentul t făcând media aritmetică a preţurilor de la momentele de timp
t-1, t-2, ..., t-n. Folosind acest algoritm de prognoză, v-ati decis să identificaţi preţul maxim şi 
preţul minim ce urmează să se atingă în următoarea perioadă şi astfel să ştiţi exact care sunt moementele 
propice pentru cumpărarea sau vânzarea de Bitcoin. Scrieţi un program care preia la intrare preţurile
Bitcoin din ultimele n zile şi prognozează preţurile din următoarele p zile. Identificaţi apoi preţul 
maxim şi preţul minim ce se vor atinge în perioada prognozată.

EXEMPLU INPUT SI OUTPUT:
Input:
4 3
1.13 2.1 3.68 4.5

Output:
2.85 3.28 3.58
3.58 2.85
*/

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    vector<float> temp;
    int n,p;
    float t,tmin=10000,tmax=0;
    float suma=0,medie,pr;
    cin>>n>>p;
    for(int i=0;i<n;i++) {
        cin>>t;
        temp.push_back(t);
    }
    int k=0;
    for(int i=0;i<p;i++) {
        for(int j=k;j<k+n;j++) {
            suma+=temp[j];
        }
        medie = suma/n;
        if(medie<tmin) {
            tmin=medie;
        }
        if(medie>tmax) {
            tmax=medie;
        }
        cout<<fixed<<setprecision(2)<<medie<<" ";
        temp.push_back(medie);
        k++;
        suma=0;
    }
    cout<<endl;
    //cout<<tmax<<" "<<tmin<<endl;
    pr=tmax-tmin;
    cout<<fixed<<setprecision(2)<<tmax<<" "<<fixed<<setprecision(2)<<tmin<<endl;
    return 0;
}

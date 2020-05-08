/*
CERINTA: Scrieţi un program care procesează o listă de tranzacţii bancare (caracterizate prin expeditor, destinatar şi sumă tranzacţionată)
şi stabileşte cel mai lung lanţ de tranzacţii şi suma care a ajuns de la primul expeditor la ultimul destinatar. Un lanţ de tranzacţii 
reprezintă o listă ordonată de tranzacţii în care destinatarul din tranzacţia i reprezintă expeditorul pentru tranzacţia i+1. 
Prima voastră sarcină, fiind mai simplă, presupune că în lista de tranzacţii de intrare:
- nu vor exista tranzacţii cu care să se poată forma lanţuri ciclice;
- un nume A poate apărea doar o dată cu rolul de expeditor şi doar o dată cu rolul de destinatar.

EXEMPLU INPUT SI OUTPUT:
Input:
4
Ciprian Ion 10
Andrei Gheorghe 24
Ion Andrei 15
Vasile Cornel 15

Output:


Ciprian Ion Andrei Gheorghe
10 
/*

#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(){
    map<string, pair<string, double>> mapa;
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++) {
        string expeditor, destinatar;
        int suma;
        cin>>expeditor>>destinatar>>suma;
        mapa[expeditor] = {destinatar,suma};
    }
    vector<string> vectMax;
    double sumaMax;
    for(auto  p:mapa){
        vector<string> newVect={p.first,p.second.first};
        double newSum = p.second.second;
        while(mapa.count(newVect.back())==1){
            newSum = min(newSum,mapa[newVect.back()].second);
            newVect.push_back(mapa[newVect.back()].first);
        }
        if(newVect.size()>vectMax.size() || (newVect.size()==vectMax.size() && newSum>sumaMax)){
            vectMax = newVect;
            sumaMax=newSum;
        }
    }
    for(auto s:vectMax){
        cout<<s<<" ";
    }
    cout<<endl<<sumaMax<<endl;
    return 0;
}

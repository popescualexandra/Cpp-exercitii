/*
CERINTA: Pentru că echipa cu care lucrați a dezvoltat o nouă arhitectură de procesor RISC, ați decis să-i
ajutați în etapa de dezvoltare prin realizarea unui simulator software pentru procesorul respectiv.
Simulatorul va primi, ca și procesorul real, o secvență de instrucțiuni care va trebui executată iar
starea finală a datelor va trebui afișată la ieșire. Procesorul are un set de 16 registre numerotate de
la 0 la 15 și deocamdată nu are memorie.
Procesorul știe să execute următoarele instrucțiuni, pe care trebuie să le interpreteze și programul vostru:
• lconst <dst> <val> – se scrie valoarea <val> în registrul <dst>; 
• add <dst> <src0> <src> – se adună valorile din registrele <src0> și <src1> și rezultatul se scrie în
registrul <dst>;
• mul <dst> <src0> <src> – se înmulțesc valorile din registrele <src0> și <src1> și rezultatul se 
scrie în registrul <dst>; 
• div <dst> <src0> <src> – se împart valorile din registrele <src0> și <src1> și câtul se scrie în
registrul <dst>; 
• print <reg> - se afișează valoarea din registrul <reg>. 
Dacă la execuția unei instrucțiuni de tip div împărțitorul este zero, se va afișa fraza Exception: 
line <index>, unde index reprezintă a câta instrucțiune nu a putut fi executată, iar programul se va
încheia. Toate registrele au inițial valoarea 0. Dându-se o secvență de instrucțiuni ca cele de mai sus,
executați-le și afișați valorile printate de program.

EXEMPLU INPUT SI OUTPUT:
Input:
8 
lconst 0 10 
print 0 
lconst 2 1 
add 1 0 2
mul 2 0 1 
lconst 1 2 
div 0 2 1 
print 0

Output:
10 55
*/

#include <iostream>
#include <map>

using namespace std;

int main() {
    map<int,int> myMap;
    int n,dst,val,src0,src,reg,ct,ok=1;
    string instr;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>instr;
        if(instr=="lconst") {
            cin>>dst>>val;
            myMap[dst]=val;
        }
        else if(instr=="add") {
            cin>>dst>>src0>>src;
            ct=myMap[src0]+myMap[src];
            myMap[dst]=ct;
        }
        else if(instr=="mul") {
            cin>>dst>>src0>>src;
            ct=myMap[src0]*myMap[src];
            myMap[dst]=ct;
        }
        else if(instr=="div") {
            cin>>dst>>src0>>src;
            if(myMap[src]==0) {
                cout<<"Exception: line "<<i+1<<endl;
                ok=0;
                break;
            }
            else {
                ct=myMap[src0]/myMap[src];
                myMap[dst]=ct;
            }
        }
        else if(instr=="print") {
            cin>>reg;
            for(pair<int,int>p:myMap) {
                if(p.first==reg) {
                    cout<<p.second<<endl;
                }
            }
        }
    }
    return 0;
}

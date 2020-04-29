/*
CERINTA: Să se înlocuiască dintr-un text dat toate secvenţele de caractere marcate ca nepotrivite, cu o
secvenţă de acelaşi număr de steluţe (*).

EXEMPLU INPUT SI OUTPUT:
Input:
puslamaua de dan a devenit extrem de
antipatic. pe langa comportamentul
lui agresiv, are si masina aia
absolut dezgustatoare.
4
puslama antipatic agresiv dezgustator

Output:
*******ua de dan a devenit
extrem de *********. pe
langa comportamentul lui
*******, are si masina aia
absolut dezgustatoare.
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    string str, cuvinte;
    int n;
    getline(cin,str);
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>cuvinte;
        while(str.find(cuvinte)!=string::npos) {
            int found=str.find(cuvinte);
            for(int j=found;j<cuvinte.size()+found;j++) {
                str[j]='*';
            }
        }
    }
    cout<<str<<endl;
    return 0;
}

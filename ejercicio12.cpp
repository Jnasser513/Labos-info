#include <iostream>

using namespace std;

int main(){
    int n, resto, nuevonum=0;
    
    cout <<"Ingrese el numero que quiere invertir: ";
    cin >> n;
    while(n>0){
        resto=n%10;
        n=n/10;
        nuevonum=nuevonum*10+resto;
    }
    cout <<"El numero invertido es:" << nuevonum;

    return 0;
}


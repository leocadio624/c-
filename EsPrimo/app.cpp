#include<iostream>
using namespace std;

bool esPrimo(int numero){

    if(numero == 0 || numero == 1 || numero == 4) return false;

    for(int i = 2; i < numero/2; i++){
        if(numero % i == 0){
            return false;
        }

    }

    return true;

}


int main(){

    
    for(int i = 1; i <= 10; i++){
        cout<<i<<" - "<<esPrimo(i)<<endl;
    }
    
    

    return 0;
}
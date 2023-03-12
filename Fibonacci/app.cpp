#include<iostream>
using namespace std;


int main(){
    unsigned long long aux = 1, fib = 0, lim, i;
    unsigned long long l[1000];

    cin >> lim;

    if(lim > 0){
        for(i=1; i <= lim; i++){
            aux += fib;
            fib = aux - fib;
            l[i-1] = fib;
        }
        //cout<<fib;

    }

    for(i=0; i < lim; i++)
        cout<<l[i]<<endl;



    cout<<"\n";
    return 0;

}
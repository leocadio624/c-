#include<iostream>
#include<string>

using namespace std;

int size_ = 25;
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37,
        41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

int binarySearch(int x){
    int min = 0;
    int max = size_ - 1;

    while(min <= max){
        int guess = min + (max - min)/2;
        cout<<"guess:"+to_string(guess)+" max:"+to_string(max)+" min:"+to_string(min)<<endl;
        
        

        if (primes[guess] == x)
            return guess;
        else if(primes[guess] < x)
            min = guess + 1;
        else
            max = guess - 1;
        

    }
    return -1;
}
int main(){
    
    int x;
    cout<<"Ingrese un numero"<<endl;
    cin >> x;
    cout<<""<<endl;

    int position = binarySearch(x);
    cout<<position<<endl;

    
        


    return 0;
}



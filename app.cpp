#include<iostream>
using namespace std;

int size_ = 0;
int n_llaves;

int entradas[100000];
int llaves[100000];


int binarySearch(int x){
    int min = 0;
    int max = size_ - 1;
    
    while(min <= max){
        int guess = min + (max - min)/2;
        
        if (entradas[guess] == x)
            return guess + 1;
        else if(entradas[guess] < x)
            min = guess + 1;
        else
            max = guess - 1;
        

    }
    return 0;
}




int main(){
    
    
    
    cin >> size_;
    for(int i = 0; i<size_; i++)
        cin >> entradas[i];
    
    cin >> n_llaves;
    for(int i = 0; i<n_llaves; i++)
        cin >> llaves[i];
    
    for(int i = 0; i<n_llaves; i++){        
        //cout << llaves[i] << endl;
        //cout << binarySearch( llaves[i] ) << endl;
        cout << binarySearch( llaves[i] ) << " ";
    }
    

    cout<<""<<endl;
    
    
    return 0;
}

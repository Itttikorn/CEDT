#include<iostream>
using namespace std;

int main(){
    long num;
    cin >> num;
    long divided=num;
    for(long i=2;i<=num;i++){
        while(divided%i==0){
            divided = divided/i;
            cout<<i;
            if(divided!=1){
                cout << "*";
            }else{
                break;
            }
        }
        
    }
}
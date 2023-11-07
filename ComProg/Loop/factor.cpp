#include<iostream>
using namespace std;

int main(){
    long num,m=2;
    cin >> num;
    //long divided=num;
    while(m*m<=num){
        if(num%m==0){
            cout<<m<<"*";
            num = num/m;
            m=2;
        }else{
            m++;
        }
    }
    cout << num;
}
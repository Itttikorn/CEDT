#include<iostream>
#include<cmath>
using namespace std;

long long power(int base, int exponent){
    long long result=1;
    for(int i=1;i<exponent;i++){
        result*=base;
    }
    //cout << "Result" << endl;
    return result;
}

int main(){
    long long num1,num2;
    cin >> num1 >> num2;
    long long digits=0;
    
    long long num1length = to_string(num1).length();
    long long num2length = to_string(num2).length();

    //cout << num1length << " " << num2length << endl;

    if(num1length==num2length){
        digits=(num2-num1)*num1length;
        digits+=num1length;
    }else{
        digits+=((power(10,num1length+1)-num1)*num1length);
        //cout << (power(10,num1length)-num1) << endl;
        //digits+=num1length;
        num1length++;
        //cout << "before" << digits << endl;
        while(num1length < num2length){
            digits+=(9*power(10,num1length)*num1length);
            //cout << "in" << (9*power(10,num1length)*num1length) << endl;
            num1length++;
        }
        digits+=((num2-power(10,num1length))*num1length);
        //cout << "after" << ((num2-power(10,num2length))*num1length) << endl;
        digits+=num2length;

    }
    cout << digits;
}
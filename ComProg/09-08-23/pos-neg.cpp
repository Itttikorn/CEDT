#include <iostream>
using namespace std;
int main() {
    int num;
    cin >> num;
    if (num>0){
        cout << "positive";
    }else if(num==0){
        cout << "zero";
    }else if(num<0){
        cout << "negative";
    }
    cout << endl;
    if(num%2 == 0){
        cout << "even";
    }else{
        cout << "odd";
    }
}
#include <iostream>
using namespace std;
int main() {
    string number;
    cin >> number;
    if(number.length()!=10){
        cout << "Not a mobile number";
    }else if(number[0]!='0'){
        cout << "Not a mobile number";
    }else if((number[1]!='6')&&(number[1]!='8')&&(number[1]!='9')){
        cout << "Not a mobile number";
    }else{
        cout << "Mobile number";
    }
}
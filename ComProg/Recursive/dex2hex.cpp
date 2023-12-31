#include <iostream>
using namespace std;
string dec2hex(int d) {
    //cout << d << endl;
    string num[16] = {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
    if (d<16){
        return num[d];
    }
    return dec2hex(d/16) + dec2hex(d%16);
} 

int main() {
    int d;
    while (cin >> d) {
        cout << d << " -> " << dec2hex(d) << endl;
    }
    return 0;
} 
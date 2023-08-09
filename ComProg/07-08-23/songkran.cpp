#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int yearBE;
    int yearAD;

    cin >> yearBE;
    yearAD = yearBE - 543;
    int y = yearAD%100;
    int sk = (y+(y/4)+11)%7;
    cout << sk;
}
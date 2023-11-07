#include<iostream>
#include<cmath>
#include<string>
using namespace std;
int main(){
    string text;
    cin >> text;
    int num0 = int(text[0])-48;
    int num1 = int(text[1])-48;
    int num2 = int(text[2])-48;
    int num3 = int(text[3])-48;
    int num4 = int(text[4])-48;
    int num5 = int(text[5])-48;
    int num6 = int(text[6])-48;
    int num7 = int(text[7])-48;
    int num8 = int(text[8])-48;
    int num9 = int(text[9])-48;
    int num10 = int(text[10])-48;
    int num11 = int(text[11])-48;
    int num12 = (11-(((13*num0)+(12*num1)+(11*num2)+(10*num3)+(9*num4)+(8*num5)+(7*num6)+(6*num7)+(5*num8)+(4*num9)+(3*num10)+(2*num11))%11))%10;

    cout << num0 << "-" << num1 << num2 << num3 << num4 << "-" << num5 << num6 << num7 << num8 << num9 << "-"  << num10 << num11 << "-" << num12;
}
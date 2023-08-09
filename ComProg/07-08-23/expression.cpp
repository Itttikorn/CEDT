#include<iostream>
#include<cmath>
using namespace std;
int main(){
    float answer;
    float top;
    float bottom;
    top = M_PI-((10*9*8*7*6*5*4*3*2*1)/pow(8,8))+pow((log(9.7)),((7/sqrt(71))-sin(40*M_PI/180)));
    bottom = (pow(1.2,cbrt(2.3)));
    answer = top/bottom;
    cout << answer;
}
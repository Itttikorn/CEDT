#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double s1,s2,s3,s4;
    cin >> s1 >> s2 >> s3 >> s4;
    double max,min;
    if(s1<=s2 && s1<=s3 && s1<=s4){
        s1=0;
    }else if(s2<=s3 && s2<=s4 && s2<=s1){
        s2=0;
    }else if(s3<=s4 && s3<=s1 && s3<=s2){
        s3=0;
    }else if(s4<=s1 && s4<=s2 && s4<=s3){
        s4=0;
    }
    if(s1>=s2 && s1>=s3 && s1>=s4){
        s1=0;
    }else if(s2>=s3 && s2>=s4 && s2>=s1){
        s2=0;
    }else if(s3>=s4 && s3>=s1 && s3>=s2){
        s3=0;
    }else if(s4>=s1 && s4>=s2 && s4>=s3){
        s4=0;
    }
    double x = (s1+s2+s3+s4)/2;
    cout <<  round(x*100.0)/100.0;
}
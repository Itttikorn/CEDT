#include<iostream>
#include<cmath>
using namespace std;
int main(){
    long double xe,ye,re,rp,xm,ym;
    cin >> xe >> ye >> re >> rp >> xm >> ym;

    long double C = sqrt(pow(xe-xm,2)+pow(ye-ym,2));
    long double A = xm-xe;
    long double B = ym-ye;
    long double c = re-rp;
    long double b = B*(c/C);
    long double a = A*(c/C);
    long double xp = xe+a;
    long double yp = ye+b;
    cout << round(xp) << " "<<round(yp);

}
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main(){
    double x1;
    double x2;

    double a;
    double b;
    double c;

    cin >> a;
    cin >> b;
    cin >> c;

    x1 = (-b-sqrt(pow(b,2)-4*a*c))/2/a;
    x2 = (-b+sqrt(pow(b,2)-4*a*c))/2/a;

    double x1ans = round(x1*1e3)/1e3;
    double x2ans = round(x2*1e3)/1e3;

    cout << x1ans  << " " << x2ans;
}
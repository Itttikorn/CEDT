#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main(){
    long double w;
    long double h;
    cin >> w;
    cin >> h;
    
    long double Mos;
    long double Hay;
    long double Boy;
    long double lock;

    lock = log10(w);

    Mos = (sqrt(w*h))/60;
    Hay = 0.024265*pow(w,0.5378)*pow(h,0.3964);
    Boy = 0.0333*pow(w,(0.6157-(0.0188*lock)))*pow(h,0.3);

    cout << setprecision(15) << Mos << endl << Hay << endl << Boy << endl;
}
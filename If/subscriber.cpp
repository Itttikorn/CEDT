#include <iostream>
#include <cmath>
using namespace std;

int main(){
    long double subs;
    cin >> subs;
    if(subs<1000){
        cout << subs;
    }else if(subs <1000000){
        subs /= 1000;
        if (subs < 10){
            cout << round(subs*10)/10.0<<"K";
        }else{
            cout << round(subs)<<"K";
        }   
    }else if(subs <1000000000){
        subs /= 1000000;
        if (subs < 10){
            cout << round(subs*10)/10.0<<"M";
        }else{
            cout << round(subs)<<"M";
        }
    }else{
        subs /= 1000000000;
        if (subs < 10){
            cout << round(subs*10)/10.0<<"B";
        }else{
            cout << round(subs)<<"B";
        }
    }
}
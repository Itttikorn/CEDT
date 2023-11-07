#include <iostream>
using namespace std;
int main() {
    int a,b,c,d,tmp;
    cin >> a >> b >> c >> d;
    if(a>b){
        tmp = a;
        a = b;
        b = tmp;
        if(d>=a){
            if(c>d){
                c=c-a;
            }
        }else{
            c=c+a;
        }
        b=a+c+d;
    }else{
        if (c>a && a>=b){
            d=d+a;
        }
        if(d>c){
            b=b+2;
        }else{
            b=2*b;
        }
    }
    cout << a << " " << b << " " << c << " " << d;
}
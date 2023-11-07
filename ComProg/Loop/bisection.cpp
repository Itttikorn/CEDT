#include<iostream>
#include<cmath>
using namespace std;

int main(){
    long double a,n=1,count=1,u,l,x;
    cin >> a;
    while(n<a){
        n*=10;
        count++;
    }
    u=count;
    l=0;
    x=(u+l)/2.00;
    while(abs(a-pow(10,x))>pow(10,-10)*max(a,pow(10,x))){
        if(pow(10,x)>a){
            u=x;
        }else if(pow(10,x)<a){
            l=x;
        }
        x=(u+l)/2.00;
    }
    cout << x;
    int r=x;
    if(x-r==0){
        cout<<".0";
    }

}
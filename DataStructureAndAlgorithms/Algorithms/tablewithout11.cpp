#include<bits/stdc++.h>
using namespace std;

int main(){
    //not finished
    int n;
    cin >> n;
    long long m = pow(pow(2,n),2);
    cout << m << endl;
    m-=(m*0.25);
    m-=2*pow(2,n);
    cout << m;
}
#include<bits/stdc++.h>
using namespace std;

long gcd(long a, long b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}


int main(){
    string full,notdup,dup;
    cin >> full >> notdup >> dup;

    string alldeci = notdup + dup;
    string bottom1 = "";
    for (int i = 0; i < dup.length(); i++) {
        bottom1 = bottom1 + "9";
    }
    string bottom2 = "";
    for (int i = 0; i < notdup.length(); i++) {
        bottom2 = bottom2 + "0";
    }
    string bottomtext = bottom1+bottom2;


    int top = stoi(alldeci)-stoi(notdup);
    int bottom = stoi(bottomtext);
    top = top + stoi(full)*bottom;
    long double hrm = gcd(top,bottom);
    top = top/hrm;
    bottom = bottom/hrm;
    cout << top << " / " << bottom;
}
#include <iostream>
using namespace std;
int to_sec(int h,int m, int s){
    int ans = h*60*60 + m*60 + s;
    return ans;
}

int diff(int h1, int m1, int s1, int h2, int m2, int s2){
    int t1 = to_sec(h1,m1,s1);
    int t2 = to_sec(h2,m2,s2);
    return t2-t1;
}
int main() {
    int h1,m1,s1, h2,m2,s2;
    cin >> h1 >> m1 >> s1;
    cin >> h2 >> m2 >> s2;
    cout << diff(h1,m1,s1,h2,m2,s2);
}
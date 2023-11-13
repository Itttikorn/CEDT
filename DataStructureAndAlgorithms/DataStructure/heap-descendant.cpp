#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,a;
    cin >> n >> a;
    set<int> s;
    s.insert(a);
    for(auto itr = s.begin();itr!=s.end();itr++){
        int newdad1 = (*itr+1)*2-1;
        int newdad2 = (*itr+1)*2;
        if(newdad1 >= n) continue;
        s.insert(newdad1);
        if(newdad2 >= n) continue;
        s.insert(newdad2);
    }
    cout << s.size() << endl;
    for(auto itr = s.begin();itr!=s.end();itr++){
        cout << *itr << " ";
    }
    return 0;
}
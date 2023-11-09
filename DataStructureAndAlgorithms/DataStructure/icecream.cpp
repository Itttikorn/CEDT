#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int n,m,start;
    cin >> n >> m >> start;
    vector<int>table(100003);
    while (n--){
        int a,s;
        cin >> a >> s;
        table[a]=s;
    }
    for (int i = 0; i <= 100002; ++i){
        table[i]=(start=table[i]?:start) +table[i-1];
    }
    while (m--){
        int price,call;
        cin >> price >> call;
        cout << (table[call]>=price?lower_bound(table.begin(),table.begin()+call+1,price):
        lower_bound(table.begin()+call,table.end(),price+table[call])) -table.begin() << " ";
    }
}

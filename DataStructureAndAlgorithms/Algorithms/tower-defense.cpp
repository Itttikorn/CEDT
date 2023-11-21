#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,k,w;
    int sum=0;
    cin >> n >> m >> k >> w;
    int p[m]; //monster pos
    int h[m]; //monster hp
    int t[k]; //tower pos

    vector<vector<int>> table;
    for(int i=0;i<m;i++){
        int in;
        cin >> in;
        p[i] = in;
    }
    for(int i=0;i<m;i++){
        int in;
        cin >> in;
        h[i] = in;
        sum+=h[i];
    }
    for(int i=0;i<k;i++){
        int in;
        cin >> in;
        t[i] = in;
    }
    for(int i=0;i<k;i++){
        int leftpos = t[i]-w;
        int rightpos = t[i]+w;
        for(int j=0;j<m;j++){
            if(p[j] >= leftpos && p[j] <=rightpos){
                if(h[j]>0){
                    h[j]--;
                    sum--;
                }
                break;
            }
        }
    }

    cout << sum << endl;
}
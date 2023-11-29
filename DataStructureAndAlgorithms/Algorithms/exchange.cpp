#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int k;
    cin >> k;
    for(int p=0;p<k;p++){
        int n;
        cin >> n;
        //vector<vector<double>> table(n,vector<double>(n));
        vector<vector<double>> dist(n,vector<double>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> dist[i][j];
                //if(i==j) dist[i][j] = 0;
            }
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    dist[i][j] = max(dist[i][j],dist[i][k] * dist[k][j]);
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout << dist[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        bool check = true;
        for(int i=0;i<n;i++){
            if(dist[i][i]>1){
                check = false;
            }
        }
        if(check){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
    }
}
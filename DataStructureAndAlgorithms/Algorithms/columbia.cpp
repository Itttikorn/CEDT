#include <bits/stdc++.h>
using namespace std;

int main(){
    int r,c;
    cin >> r >> c;
    vector<vector<int>> table(r,vector<int>(c));
    vector<vector<int>> dist(r,vector<int>(c,INT_MAX));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> table[i][j];
        }
    }
    queue<pair<int,int>> q;
    q.push({0,0});
    dist[0][0] = 0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        int t = dist[x][y];
        q.pop();
        if(x-1>=0 && dist[x-1][y] > t+table[x-1][y]){
            q.push({x-1,y});
            dist[x-1][y] = t+table[x-1][y];
        }
        if(x+1<r && dist[x+1][y] > t+table[x+1][y]){
            q.push({x+1,y});
            dist[x+1][y] = t+table[x+1][y];
        }
        if(y-1>=0 && dist[x][y-1] > t+table[x][y-1]){
            q.push({x,y-1});
            dist[x][y-1] = t+table[x][y-1];
        }
        if(y+1<c && dist[x][y+1] > t+table[x][y+1]){
            q.push({x,y+1});
            dist[x][y+1] = t+table[x][y+1];
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    
}
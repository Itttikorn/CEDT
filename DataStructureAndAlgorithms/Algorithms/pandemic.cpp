#include<bits/stdc++.h>
using namespace std;

int main(){
    int r,c,t;
    cin >> r >> c >> t;
    vector<vector<int>> table(r,vector<int>(c));
    queue<pair<int,int>> infected;
    int count=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> table[i][j];
            if(table[i][j]==1){
                infected.push({i,j});
                count++;
            }
        }
    }
    for(int d=0;d<t;d++){
        int currentsize = infected.size();
        for(int i=0;i<currentsize;i++){
            auto loc = infected.front();
            infected.pop();
            int x = loc.first;
            int y = loc.second;
            //fill top
            if(x-1>=0){
                if(table[x-1][y]==0){
                    table[x-1][y] = 1;
                    infected.push({x-1,y});
                    count++;
                }
            }
            //fill bottom
            if(x+1<r){
                if(table[x+1][y]==0){
                    table[x+1][y] = 1;
                    infected.push({x+1,y});
                    count++;
                }
            }
            //fill left
            if(y-1>=0){
                if(table[x][y-1]==0){
                    table[x][y-1] = 1;
                    infected.push({x,y-1});
                    count++;
                }
            }
            //fill right
            if(y+1<c){
                if(table[x][y+1]==0){
                    table[x][y+1] = 1;
                    infected.push({x,y+1});
                    count++;
                }
            }

        }
    }
    // cout << "Result" << endl;
    // for(auto &a : table){
    //     for(auto &b : a){
    //         cout << b << " ";
    //     }
    //     cout << endl;
    // }
    cout << count;
}
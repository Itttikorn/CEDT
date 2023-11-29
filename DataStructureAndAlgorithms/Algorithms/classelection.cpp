#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> start(n);
    vector<int> finish(n);
    vector<pair<int,int>> time(n);
    for(int i=0;i<n;i++){
        cin >> start[i];
    }
    for(int i=0;i<n;i++){
        cin >> finish[i];
        time[i] = {finish[i],start[i]};
    }
    int count=0;
    int prev=-1;
    sort(time.begin(),time.end());
    for(int i=0;i<n;i++){
        if(time[i].second >= prev){
            prev = time[i].first;
            count++;
        }
    }
    cout << count;
}
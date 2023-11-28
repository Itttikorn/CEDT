#include<bits/stdc++.h>
using namespace std;

int main(){
    int f,w,n;
    cin >> f >> w >> n;
    vector<int> food(f);
    for(int i=0;i<f;i++){
        cin >> food[i];
    }
    if(w==0){
        cout << f;
        return 0;
    }
    sort(food.begin(),food.end());
    int range = 2*w;
    int count=1;
    int outofrange = food[0] + range;
    for(auto itr = food.begin();itr!=food.end();itr++){
        if(outofrange < *itr){
            count++;
            outofrange = *itr+range;
        }
    }
    cout << count;
}
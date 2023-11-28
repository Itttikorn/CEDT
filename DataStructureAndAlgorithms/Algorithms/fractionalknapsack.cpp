#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double w,n;
    cin >> w >> n;
    vector<double> price(n);
    vector<double> weight(n);
    vector<tuple<double,double,double>> priceperweight(n);
    for(int i=0;i<n;i++){
        cin >> price[i];
    }
    for(int i=0;i<n;i++){
        cin >> weight[i];
        priceperweight[i] = make_tuple(price[i]/weight[i],price[i],weight[i]);
    }
    sort(priceperweight.begin(),priceperweight.end(),greater());
    // for(auto &a : priceperweight){
    //     cout << get<0>(a) << " ";
    // }
    //cout << endl;
    double moneysum = 0;
    for(int i=0;i<n;i++){
        if(w<=get<2>(priceperweight[i])){
            moneysum += w/get<2>(priceperweight[i])*get<1>(priceperweight[i]);
            break;
        }
        moneysum+=get<1>(priceperweight[i]);
        w-=get<2>(priceperweight[i]);
    }
    cout << fixed << setprecision(4) << moneysum;
}
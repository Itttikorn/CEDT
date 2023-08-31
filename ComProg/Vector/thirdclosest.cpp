#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<tuple<double,int,double,double>> v;
    int n;
    cin >> n;
    double x1=0.0,y1=0.0,x2,y2,distance;
    for(int i=0;i<n;i++){
        cin >> x2 >> y2;
        int number=i+1;
        distance = sqrt(pow(x1-x2,2)+pow(y1-y2,2));
        v.push_back(make_tuple(distance,number,x2,y2));
    }
    sort(v.begin(),v.end());
    auto itr = v.begin()+2;
    cout << "#" << get<1>(*itr) << ": (" << get<2>(*itr) << ", " << get<3>(*itr) << ")";
}
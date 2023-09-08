#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<tuple<double,string,double>> sales;
    string name;
    bool sold=false;
    while(cin >> name){
        if(name == "END"){
            break;
        }
        double price;
        cin >> price;
        sales.push_back(make_tuple(0,name,price));
    }
    string salename;
    while(cin >> salename){
        for(int i=0;i<sales.size();i++){
            if(get<1>(sales[i])==salename){
                get<0>(sales[i]) += get<2>(sales[i]);
                sold=true;
            }
        }
    }
    sort(sales.begin(),sales.end());
    int to_print = sales.size()-3;
    //cout << sold << endl;
    if(to_print<0){
        to_print=0;
    }
    if(sold){
        for(int i=sales.size()-1;i>=to_print;i--){
            if(get<0>(sales[i])!=0){
                cout << get<1>(sales[i]) << " " << get<0>(sales[i]) << endl;
            }
        }
    }else{
        cout << "No Sales";
    }
}
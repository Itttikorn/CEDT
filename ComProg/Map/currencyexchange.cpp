#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    map<string,double> table;
    string name;
    double multiplier;
    string in;
    for(int i=0;i<n;i++){
        cin >> name >> multiplier;
        //cout << name << " " << multiplier << endl;
        table[name] = multiplier;
    }
    int money;
    cin >> money;
    string in2;
    getline(cin,in2);
    string order = in2.substr(1,in2.length()-1);
    cout << money << " " << order.substr(0,3);
    for(int i=0;i<order.length()-3;i+=4){
        string from = order.substr(i,3);
        string to = order.substr(i+4,3);
        //cout << from << " " << to << endl;
        int newmoney;
        if(from==to){
            newmoney=money;
        }else if(to=="THB"){
            newmoney=money*table.find(from)->second;
        }else if(from=="THB"){
            newmoney=money/table.find(to)->second;
        }else{
            newmoney=money*table.find(from)->second/table.find(to)->second;
        }
        cout << " -> " << newmoney << " " << to;
        money = newmoney;
    }
}
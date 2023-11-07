#include<bits/stdc++.h>
using namespace std;

int main(){
    string partyname;
    int voters;
    map<string,double> info;
    float total=0;
    while(partyname!="END"){
        cin >> partyname;
        if(partyname == "END"){
            break;
        }
        cin >> voters;
        total+=voters;
        info[partyname] = voters;
    }
    //cout << total/100.0 << endl;
    float avgperseat = total/100.0;
    vector<tuple<double,int,string>> result;
    vector<tuple<double,string>> decimal;
    int seatleft=100;
    for(auto itr=info.begin();itr!=info.end();itr++){
        //cout << itr->second << "/" << avgperseat << "="<< itr->second/avgperseat << endl;
        result.push_back(make_tuple(floor(itr->second/avgperseat),itr->second,itr->first));
        decimal.push_back(make_tuple((itr->second/avgperseat)-floor(itr->second/avgperseat),itr->first));
        seatleft-=floor(itr->second/avgperseat);
        //cout << (itr->second/avgperseat) << "-" << floor(itr->second/avgperseat) << "=" << (itr->second/avgperseat)-floor(itr->second/avgperseat) << endl;
        //cout << seatleft << endl;
        //cout << itr->first << " " << int(itr->second/avgperseat) << " " << itr->second << endl;
    }
    sort(decimal.begin(),decimal.end());
    for(int i=decimal.size()-1;i>=decimal.size()-seatleft;i--){
        for(int j=0;j<result.size();j++){
            //cout << get<1>(decimal[i]) << " " << get<1>(result[j]) << endl;
            if(get<1>(decimal[i])==get<2>(result[j])){
                //cout << get<1>(decimal[i]) << " " << get<1>(result[j]) << endl;
                get<0>(result[j])++;
                break;
            }
        }
    }
    sort(result.begin(),result.end());
    for(int i=result.size()-1;i>=0;i--){
        if(floor(get<0>(result[i]))!=0){
            cout << get<2>(result[i]) << " " << floor(get<0>(result[i])) << " " << get<1>(result[i]) << endl;
        }else{
            break;
        }
    }
}
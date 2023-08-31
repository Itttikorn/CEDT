#include<bits/stdc++.h>
using namespace std;

//NOT FINISHED
int main(){
    string mode;
    cin >> mode;
    int num;
    vector<int> numlist;
    while(cin >> num){
        numlist.push_back(num);
    }
    vector<pair<int,vector<int>>> result;

    int count=0;
    if(mode=="first"){
        for(auto itr = numlist.begin(); itr!= numlist.end(); itr++){
            if(count==0){
                vector<int> insert = {*itr};
                result.push_back(make_pair(*itr , insert));
            }else{
                for(int i=0;i<result.size();i++){
                    pair<int,vector<int>> result2 = result[i];
                    if(*itr + result2.first() <= 100){

                    }
                }
            }
            count++;
        }
    }
    for(auto itr=result.begin();itr!=result.end();itr++){
        pair<int,vector<int>> pairofresult = *itr;
        vector<int> v = pairofresult.second;
        for(auto itr2 = v.begin();itr2!=v.end();itr2++){
            cout << *itr2 << " ";
        }
        cout << endl;
    }
}
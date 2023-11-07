#include<bits/stdc++.h>
using namespace std;

int main(){
    string mode;
    cin >> mode;
    vector<int> numlist;
    int num;
    while(cin >> num){
        numlist.push_back(num);
    }

    //push first number;
    if(mode=="first"){
        vector<tuple<int,int,vector<int>>> result;
        vector<int> first;
        first.push_back(numlist[0]);
        result.push_back(make_tuple(numlist[0],-1,first));
        for(auto itr = numlist.begin()+1;itr!=numlist.end();itr++){
            bool added=false;
            //cout << *itr << endl;
            for(int i = 0; i < result.size();i++){
                //cout << *itr << "+" << result[i].first << "=" << *itr+result[i].first << endl;
                if(*itr+get<0>(result[i])<=100){
                    get<2>(result[i]).push_back(*itr);
                    get<1>(result[i])=-(get<2>(result[i]).size());
                    get<0>(result[i])+=*itr;
                    added=true;
                    break;
                }
            }
            //not fit
            if(added==false){
                //cout << "new" << *itr << endl;
                vector<int> newv;
                newv.push_back(*itr);
                result.push_back(make_tuple(*itr,-1,newv));
            }
        }
        sort(result.begin(),result.end());
        for(int i=result.size()-1;i>=0;i--){
            sort(get<2>(result[i]).begin(),get<2>(result[i]).end());
            for(auto itr = get<2>(result[i]).begin();itr!=get<2>(result[i]).end();itr++){
                cout << *itr << " ";
            }
            cout << endl;
        }
    }else if(mode=="best"){
        vector<tuple<int,int,int,vector<int>>> result;
        vector<int> first;
        first.push_back(numlist[0]);
        result.push_back(make_tuple(numlist[0],-1,1,first));
        for(auto itr = numlist.begin()+1;itr!=numlist.end();itr++){
            int best=100;
            int bestlocation=0;
            bool added=false;
            for(int i=0;i<result.size();i++){
                //run through all list
                //cout << *itr << "+" << get<0>(result[i]) << "=" << *itr+get<0>(result[i]) << endl;
                if(*itr+get<0>(result[i]) <= 100){
                    if(100 - (*itr+get<0>(result[i])) < best){
                        best=100-(*itr+get<0>(result[i]));
                        bestlocation = i;
                    }
                }
            }
            //cout << "Best" << best << endl;
            if(best==100){
                //cout << "new" << *itr << endl;
                vector<int> newv;
                newv.push_back(*itr);
                result.push_back(make_tuple(*itr,-1,1,newv));
            }else{
                get<3>(result[bestlocation]).push_back(*itr);
                get<1>(result[bestlocation])=-(get<3>(result[bestlocation]).size());
                get<0>(result[bestlocation])+=*itr;
                added=true;
            }
        }
        for(int i=0;i<result.size();i++){
            sort(get<3>(result[i]).begin(),get<3>(result[i]).end());
            get<2>(result[i])=-get<3>(result[i])[0];
        }
        sort(result.begin(),result.end());
        for(int i=result.size()-1;i>=0;i--){
            for(auto itr = get<3>(result[i]).begin();itr!=get<3>(result[i]).end();itr++){
                cout << *itr << " ";
            }
            cout << endl;
        }
    }
}
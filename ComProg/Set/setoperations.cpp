#include<bits/stdc++.h>
using namespace std;

int main(){
    string in;
    int count=0;
    vector<set<int>> orders;
    while(getline(cin,in)){
        set<int> newset;
        for(int i=0;i<in.length();i++){
            int counter=0;
            for(int j=i;j<in.length();j++){
                if(j==in.length()-1){
                    counter++;
                    newset.insert(stoi(in.substr(i,counter)));
                    i=j;
                    break;
                }
                if(in[j]==' '){
                    newset.insert(stoi(in.substr(i,counter)));
                    i=j;
                    break;
                }else{
                    counter++;
                }
            }
        }
        //count++;
        // for(auto itr = newset.begin();itr!=newset.end();itr++){
        //     cout << *itr << " ";
        // }
        // cout << endl;
        orders.push_back(newset);
    }
    //cout << count;

    //union
    set<int> unionset;
    int sizes = orders.size();
    for(int i=0;i<sizes;i++){
        for(auto itr = orders[i].begin() ; itr!= orders[i].end() ; itr++){
            unionset.insert(*itr);
        }
    }
    cout << "U: ";
    for(auto itr = unionset.begin();itr!=unionset.end();itr++){
        cout << *itr << " ";
    }
    cout << endl;

    //intersect
    set<int> intersectset;
    for(auto itr = unionset.begin();itr!=unionset.end();itr++){
        int foundcount=0;
        for(int i=0;i<sizes;i++){
            if(orders[i].find(*itr)!=orders[i].end()){
                foundcount++;
            }
        }
        if(foundcount==sizes){
            intersectset.insert(*itr);
        }
    }
    cout << "I: ";
    if(intersectset.size()!=0){
        for(auto itr = intersectset.begin();itr!=intersectset.end();itr++){
            cout << *itr << " ";
        }
    }else{
        cout << "empty set";
    }
    cout << endl;

    //difference
    set<int> diffset=orders[0];
    for(int i=0;i<sizes-1;i++){
        set<int> newdiffset;
        for(auto itr=diffset.begin();itr!=diffset.end();itr++){
            if(orders[i+1].find(*itr)==orders[i+1].end()){
                newdiffset.insert(*itr);
            }
        }
        diffset=newdiffset;
    }


    cout << "D: ";
    if(diffset.size()!=0){
        for(auto itr = diffset.begin();itr!=diffset.end();itr++){
            cout << *itr << " ";
        }
    }else{
        cout << "empty set";
    }
    cout << endl;
}
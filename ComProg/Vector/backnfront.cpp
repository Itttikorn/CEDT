#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    string ipt;
    int count=0;
    vector<int>v;
    while(cin >> ipt){
        if (ipt.length()==0){
            continue;
        }else{
            int num = stoi(ipt);
            if(ipt=="-1"){
                break;
            }
            if(count%2==0){
                v.push_back(num);
            }else if(count%2!=0){
                v.insert(v.begin(),num);
            }
            count++;
        }
        
    }
    if (v.size()==0){
        cout << "[]";
    }else{
        cout << "[";
        for(auto itr=v.begin();itr!=v.end();itr++){
            cout << *itr;
            if(itr!=v.end()-1){
                cout << ", ";
            }
        }
        cout << "]";
    }
}
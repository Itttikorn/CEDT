#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector<int> list;
    while(cin >> n){
        list.push_back(n);
    }
    list.push_back(-1);
    int maxrange=0;
    int firstindex=0;
    int lastindex=0;
    //             num first last
    vector<tuple<int,int,int>> saved;
    for(auto itr=list.begin();itr!=list.end();itr++){
        lastindex=firstindex+1;
        for(auto itr2=itr;itr2!=list.end()-1;itr2++){
            //cout << *itr2 << " " << *(itr2+1);
            if (*itr2 != *(itr2+1)){
                //cout << "yes" << endl;
                if(lastindex-firstindex>maxrange){
                    saved.clear();
                    saved.push_back(make_tuple(*itr2,firstindex,lastindex));
                    maxrange=lastindex-firstindex;
                    //cout << "Break"<<firstindex<<lastindex<<maxrange<<endl;
                }else if(lastindex-firstindex==maxrange){
                    saved.push_back(make_tuple(*itr2,firstindex,lastindex));
                    //cout << "Break"<<firstindex<<lastindex<<maxrange<<endl;
                }
                itr=itr2;
                firstindex=lastindex;
                break;
            }else{
                lastindex++;
            }
        }
    }
    //check vector
    sort(saved.begin(),saved.end());
    for(auto itr=saved.begin();itr!=saved.end();itr++){
        cout << get<0>(*itr) << " --> x[ " << get<1>(*itr) << " : " << get<2>(*itr) <<" ]" << endl;
    }
}
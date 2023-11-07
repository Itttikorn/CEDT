#include<iostream>
#include<set>
using namespace std;

int main(){
    string n;
    set<int> s;
    while(cin >> n){
        if(n.length()==0){
            break;
        }
        s.insert(stoi(n));
        cin.ignore();
    }
    int count=0;
    cout << s.size() << endl;
    for(auto i=s.begin(); i!=s.end() && count<10; i++){
        cout << *i << " ";
        count++;
    }
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    int namecount;
    cin >> namecount;
    map<string,string> names;
    map<string,string> names2;
    string firstname,secondname;
    for(int i=0;i<namecount;i++){
        cin >> firstname >> secondname;
        names[firstname] = secondname;
        names2[secondname] = firstname;
    }
    int orderscount;
    string searchname;
    cin >> orderscount;
    for(int i=0;i<orderscount;i++){
        cin >> searchname;
        bool found=false;
        if(names.find(searchname)!=names.end()){
            cout << names.find(searchname)->second << endl;
            found=true;
            continue;
        }
        if(names2.find(searchname)!=names2.end()){
            cout << names2.find(searchname)->second << endl;
            found=true;
            continue;
        }
        if(found==false){
            cout << "Not found" << endl;
        }
    }
}
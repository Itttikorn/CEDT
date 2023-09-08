#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    map<string,int> deptlist;
    map<string,string> result;
    for(int i=0;i<n;i++){
        string deptname;
        int seats;
        cin >> deptname >> seats;
        deptlist[deptname] = seats;
    }
    int m;
    cin >> m;
    vector<tuple<double,string,vector<string>>> students;
    for(int i=0;i<m;i++){
        string id;
        double score;
        string in1,in2,in3,in4;
        cin >> id >> score >> in1 >> in2 >> in3 >> in4;
        vector<string> newvector;
        newvector.push_back(in1);
        newvector.push_back(in2);
        newvector.push_back(in3);
        newvector.push_back(in4);
        students.push_back(make_tuple(score,id,newvector));
        result[id] = "";
    }
    sort(students.begin(),students.end());
    for(int i=students.size()-1;i>=0;i--){
        vector<string> selection = get<2>(students[i]);
        for(int j=0;j<selection.size();j++){
            if(deptlist.find(selection[j])->second>0){
                deptlist.find(selection[j])->second--;
                result[get<1>(students[i])] = selection[j];
                break;
            }
        }
    }
    for(auto itr = result.begin();itr!=result.end();itr++){
        cout << itr->first << " " << itr->second << endl;
    }
}
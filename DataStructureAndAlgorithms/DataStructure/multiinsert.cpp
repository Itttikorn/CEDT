#include <iostream>
#include <vector>
using namespace std;
void multiple_add(vector<int> &v, int value, int position, int count) {
 //for(int i=0;i<count;i++){
    auto pos = v.begin()+position;
    //v.insert(pos,count,value);
 //}
    vector<int> back,front;
    for(auto itr = v.begin();itr!=pos;itr++){
        front.push_back(*itr);
    }
    for(auto itr = pos;itr!=v.end();itr++){
        back.push_back(*itr);
    }
    for(int i=0;i<count;i++){
        front.push_back(value);
    }
    for(auto itr=back.begin();itr!=back.end();itr++){
        front.push_back(*itr);
    }
    v = front;
}
int main() {
 std::ios_base::sync_with_stdio(false);
 cin.tie(0);
 int n,value,position,count;
 cin >> n >> value >> position >> count;
 vector<int> v(n);
 for (int i = 0; i < n; i++) cin >> v[i];
 multiple_add(v,value,position,count);
 cout << "After call multiple_add" << endl << "Size = " << v.size() << endl;
 for (auto &x : v) cout << x << " ";
 cout << endl;
}
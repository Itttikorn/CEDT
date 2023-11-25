#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> lawn(n+1);
    lawn[0] = 0;
    for(int i=1;i<=n;i++){
        int in;
        cin >> in;
        lawn[i] = in;
        lawn[i] += lawn[i-1];
    }
    for(int i=0;i<m;i++){
        int begin;
        long long budget;
        cin >> begin >> budget;
        begin++;
        int l = begin;
        int r = n;
        long long answer = 0;
        while(l<=r){
            int mid = (l+r)/2;
            if((lawn[mid]-lawn[begin-1])+(mid-begin+1)*k <= budget){
                l=mid+1;
                answer = lawn[mid]-lawn[begin-1];
            }else{
                r = mid-1;
            }
        }
        cout << answer << "\n";
    }
}
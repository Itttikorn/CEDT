#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int c,r;
    cin >> r >> c;
    float arr[c][r];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> arr[j][i];
        }
    }
    for(int i=1;i<r-1;i++){
        for(int j=1;j<c-1;j++){
            float sum = (  arr[j-1][i-1]   + arr[j-1][i]   + arr[j-1][i+1] +
                            arr[j][i-1]     + arr[j][i]     + arr[j][i+1] +
                            arr[j+1][i-1]   + arr[j+1][i]   + arr[j+1][i+1] );
            float avg=sum/9;
            cout << round(avg*100)/100.0 << " ";
        }
        cout << endl;
    }
}
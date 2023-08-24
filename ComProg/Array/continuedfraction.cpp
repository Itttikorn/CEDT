#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int num;
    cin >> num;
    int a[num];
    double count=0;
    for(int i=0;i<num;i++){
        cin >> a[i];
    }
    cout << a[0] << endl;
    for(int i=1;i<num;i++){
        double res=a[i];
        for(int j=i;j>0;j--){
            //cout << a[j] << a[j-1];
            double fraction = 1.0/res;
            double full = a[j-1];
            res = full+fraction;
            //cout <<"full" << full << endl;
        }
        cout << setprecision(10) << res << endl;
    }
}
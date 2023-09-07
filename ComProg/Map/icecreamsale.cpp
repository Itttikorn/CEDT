#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string name;
    double price;
    map<string,double> pricetable;
    map<string,double> saletable;
    for(int i=0;i<n;i++){
        cin >> name >> price;
        pricetable[name] = price;
        saletable[name] = 0;
    }
    int m;
    cin >> m;
    string salename;
    int amount;
    double total=0;
    double maxsaleprice=0;
    for(int i=0;i<m;i++){
        cin >> salename >> amount;
        if(pricetable.find(salename)!=pricetable.end()){
            double saleprice = amount*pricetable.find(salename)->second;
            saletable[salename] += saleprice;
            if (saletable[salename]>=maxsaleprice){
                maxsaleprice = saletable[salename];
            }
            total+=saleprice;
        }
    }
    if(total!=0){
        cout << "Total ice cream sales: " << total << endl;
        cout << "Top sales: ";
        for(auto itr = saletable.begin();itr!=saletable.end();itr++){
            if(itr->second==maxsaleprice){
                cout << itr->first << " ";
            }
        }
    }else{
        cout << "No ice cream sales";
    }
}
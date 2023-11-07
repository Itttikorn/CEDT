#include<iostream>
using namespace std;

string get_word(int num, string text){
    //cout << num << endl;
    string ones[] = { "", "one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine ", "ten ", "eleven ", "twelve ", "thirteen ", "fourteen ", "fifteen ", "sixteen ", "seventeen ", "eighteen ", "nineteen " };
    string tens[] = { "", "", "twenty ", "thirty ", "forty ", "fifty ", "sixty ", "seventy ", "eighty ", "ninety " };
    string result="";
    if(num>19){
        result+=tens[num/10];
        result+=ones[num%10];
    }else{
        result+=ones[num];
    }

    if(num){
        result+=text;
    }
    return result;
}

int main(){
    string number;
    cin >> number;
    string calstring = "000000000000000";
    int diff=15-number.length();
    for(int i=number.length()-1;i>=0;i--){
        calstring[i+diff]=number[i];
    }
    //cout << "calstring " << calstring << endl;
    string word = "";
    word+=get_word((stoi(calstring.substr(0,1))),"hundred ");
    word+=get_word((stoi(calstring.substr(1,2))),"trillion ");
    word+=get_word((stoi(calstring.substr(3,1))),"hundred ");
    word+=get_word((stoi(calstring.substr(4,2))),"billion ");
    word+=get_word((stoi(calstring.substr(6,1))),"hundred ");
    word+=get_word((stoi(calstring.substr(7,2))),"million ");
    word+=get_word((stoi(calstring.substr(9,1))),"hundred ");
    word+=get_word((stoi(calstring.substr(10,2))),"thousand ");
    word+=get_word((stoi(calstring.substr(12,1))),"hundred ");
    word+=get_word((stoi(calstring.substr(13,2))),"");

    if(number=="0"){
        word="zero";
    }
    cout << word;
}
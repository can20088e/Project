#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;


ll fun(string s){
    ll left = 0, right = 127;
    ll columnleft = 0, columnright = 8;
    for(ll i = 0; i < 7; ++i){
        if(s[i] == 'F' && i == 6) return left;
        else if(s[i] == 'B' && i == 6) return right;
        if(s[i] == 'F'){
            right = (left + right) / 2;
        }else{
            left = (right + 1 + left) / 2;
        }
    }
}

ll fun1(string s){
    ll left = 0, right = 7;
    for(ll i = 7; i < 10; ++i){
        if(s[i] == 'L' && i == 9) return left;
        else if(s[i] == 'R' && i == 9) return right;
        if(s[i] == 'L'){
            right = (left + right) / 2;
        }else{
            left = (right + 1 + left) / 2;
        }
    }
}


int main(){
    string s = ""; 
    string line;
    ifstream myfile ("C:\\Users\\RT\\Desktop\\advent.txt");
    vector<ll> v;
    while (getline (myfile,line)){
      ll ans = 0;
      s = line; 
      ans += fun(s) * 8;
      ans += fun1(s);
      v.push_back(ans);
    }
    sort(v.begin(), v.end(), greater<ll>());
    cout << v[0] << endl;
    for(ll i = 1; i < v.size() - 1; ++i){
        if(v[i] - v[i + 1] > 1)cout << v[i] - 1 << endl;
    }
    cout << "asfasfas";
    return 0;
}

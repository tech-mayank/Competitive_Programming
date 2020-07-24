#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll len_sub(string x,string y,ll n,ll m){
    if(n == 0 || m == 0){
        return 0;
    }
    if(x[n-1] == y[m-1]){
        return 1 + len_sub(x,y,n-1,m-1);
    }
    else{
        return max(len_sub(x,y,n,m-1) , len_sub(x,y,n-1,m));
    }
}
int main(){
    string x,y;
    cin>>x;
    cin>>y;
    ll n = x.length();
    ll m = y.length();
    cout<<len_sub(x,y,n,m);
}


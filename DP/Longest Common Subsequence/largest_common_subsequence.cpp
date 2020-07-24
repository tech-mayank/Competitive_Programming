#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll lcs(string x,string y,ll n,ll m){
    if(n == 0 || m == 0){
        return 0;
    }
    if(x[n-1] == y[m-1]){
        return 1 + lcs(x,y,n-1,m-1);
    }
    else{
        return max(lcs(x,y,n-1,m), lcs(x,y,n,m-1));
    }
}
int main(){
    string x;
    string y;
    cin>>x;
    cin>>y;
    ll n = x.length();
    ll m = y.length();
    cout<<lcs(x,y,n,m)<<endl;
}

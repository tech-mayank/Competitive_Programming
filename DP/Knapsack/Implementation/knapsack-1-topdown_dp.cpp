#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int n,w;
    cin>>n>>w;
    ll weights[n];
    ll values[n];
    for(int i = 0;i<n;i++){
        cin>>weights[i]>>values[i];
    }
    ll t[n+1][w+1];
    for(ll i = 0;i<n+1;i++){
        for(ll j = 0;j<w+1;j++){
            if(j==0 || i==0){
                t[i][j] = 0;
            }
        }
    }

    for(ll i = 1;i<n+1;i++){
        for(ll j = 1;j<w+1;j++){
            if(weights[i-1] <= j){
                t[i][j] = max(values[i-1] + t[i-1][j-weights[i-1]], t[i-1][j]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    cout<<t[n][w]<<endl;

}


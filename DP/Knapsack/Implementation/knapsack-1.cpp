#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll knapsack(ll weights[],ll values[],ll W,ll n){
    if(n==0 || W == 0){
        return 0;
    }
    if(weights[n-1] <= W){
        return max(values[n-1] + knapsack(weights,values,W-weights[n-1],n-1), knapsack(weights,values,W,n-1));
    }
    else if(weights[n-1] > W){
        return knapsack(weights,values,W,n-1);
    }

}
int main(){
    ll n,c;
    cin>>n>>c;
    ll weights[n];
    ll values[n];
    for(int i = 0;i<n;i++){
        cin>>weights[i]>>values[i];
    }
    ll ans = knapsack(weights,values,c,n);
    cout<<ans<<endl;
}


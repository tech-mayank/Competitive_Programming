#include<bits/stdc++.h>
using namespace std;
vector<int> subset(int arr[],int sum,int n){
    int dp[n+1][sum+1] = {0};
    for(int i = 0;i<n+1;i++){
        for(int j = 0;j<sum+1;j++){
            if(i==0){
                dp[i][j] = 0;
            }
            if(j==0){
                dp[i][j] = 1;
            }
        }
    }
    for(int i = 1;i<n+1;i++){
        for(int j = 1;j<sum+1;j++){
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    vector<int> vec;
    for(int j = 0;j<=sum/2;j++){
        if(dp[n][j] == 1){
            vec.push_back(j);
        }
    }
    return vec;
}
int main(){
    int n=0,su =0;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
        su = su + arr[i];
    }
    vector<int> res;
    res = subset(arr,su,n);
    vector<int> :: iterator it;
    int mn = INT_MAX;
    for(it = res.begin();it != res.end();it++){
        mn = min(mn,(su-2**it));
    }
    cout<<mn<<endl;
}

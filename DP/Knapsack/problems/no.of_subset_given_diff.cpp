#include<bits/stdc++.h>
#define ll long long
using namespace std;
//top down dp table for subset sum problem
int subset_sum(int arr[],int n,int sum){
    int dp[n+1][sum+1] = {-1};
    for(int i = 0;i<n+1;i++){
        for(int j = 0;j<sum+1;j++){
            if(i==0){
                dp[i][j] = 0;
            }
            if(j ==0){
                dp[i][j] = 1;
            }
        }
    }
    for(int i = 1;i<n+1;i++){
        for(int j = 1;j<sum+1;j++){
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}
int main(){
    //input the array, it's size and diif of the subsets required.
    int n=0,diff=0;
    int arr[n];
    cin>>n>>diff;
    int su = 0;
    for(ll i = 0;i<n;i++){
        cin>>arr[i];
        su = su + arr[i];
    }
    int sum = (diff + su)/2;
    cout<<subset_sum(arr,n,sum)<<endl;  // it will return no. of pair of subsets of given difference.
}


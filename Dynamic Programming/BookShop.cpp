#include <bits/stdc++.h>
using namespace std;
int memoise(int ind,int n,int balance,vector<int>&rupees,vector<int>&pages,vector<int>&dp){
    if(ind==n-1){
        if(balance>rupees)
        else return 0;
    }
    if(dp[ind]!=-1)return dp[ind];
}
int main()
{
    int n, balance;
    cin >> n >> balance;
    vector<int> rupees(n), pages(n);
    for (int i = 0; i < n; i++)
        cin >> rupees[i];
    for (int i = 0; i < n; i++)
        cin >> pages[i];
    vector<int>
    return 0;
}
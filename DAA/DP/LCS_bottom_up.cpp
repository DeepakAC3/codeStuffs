#include<bits/stdc++.h>
using namespace std;
int max(int a, int b) {
    return (a > b) ? a : b;
}
//iterative
//bottom up
int lcs(string s1, string s2, int m, int n,int dp[][7]) {
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            else if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}

void printLCS(string s1, string s2, int m, int n, int dp[][7], string& lcs_str) {
    int i=m,j=n;
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1])
        {
            lcs_str=s1[i-1]+lcs_str;
            i--;j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }   
}

int main() {
    string X, Y;
    cout<<"Enter the first string: ";
    cin>>X;
    cout<<"Enter the second string: ";
    cin>>Y;
    int m = X.length();
    int n = Y.length();
    int dp[7][7];

    cout << "Length of LCS is " << lcs(X, Y, m, n,dp) << endl;

    string lcs_str;
    printLCS(X, Y, m, n, dp, lcs_str);
    cout<<"\nThe longest common subsequence is: "<<lcs_str<<endl;
    return 0;
}
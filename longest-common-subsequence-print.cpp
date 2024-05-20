

#include <bits/stdc++.h>
using namespace std;
string f(string &s1, string &s2, int i, int j,vector<vector<string>>&dp)
{
  if (i == s1.size() || j == s2.size())
  {
    return "";
  }
  if(dp[i][j].size()>0) return dp[i][j];
  if(s1[i]==s2[j]){
    return dp[i][j]=s1[i]+f(s1,s2,i+1,j+1,dp);
  }
  string left=f(s1,s2,i+1,j,dp);
  string right=f(s1,s2,i,j+1,dp);
  return dp[i][j]=(left.size()>right.size())?left :right;
}
int main()
{
  string s1 = "abac";
  string s2 = "cabcaaac";
  vector<vector<string>>dp(s1.length(),vector<string>(s2.length(),""));
  cout<<f(s1,s2,0,0,dp);
}

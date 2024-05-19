class Solution
{
public:
    vector<vector<vector<int>>> dp;
  int f(vector<int> &p, int k, int i, bool ongoing)
  {
    if (i == p.size() || k == 0)
    {
      return 0;
    }
    if(dp[i][k][ongoing]!=-1){
      return dp[i][k][ongoing];
    }
    int notake =  f(p, k, i + 1, ongoing);
    if (ongoing)
    {
      return dp[i][k][ongoing]= max(notake, f(p, k - 1, i + 1, !ongoing) + p[i]); // if there is an ongoing transaction so we only can sell this one
    }
    else
    {
      return dp[i][k][ongoing]= max(notake, f(p, k, i + 1, !ongoing) - p[i]); // if there is not ongoing transaction so we only can buy this one and the price will negate
    }
  }
  int maxProfit(int k, vector<int> &p)
  {
    dp.resize(p.size(), vector<vector<int>>(k+1, vector<int>(2,-1)));
    return f(p, k, 0, false);
  }
};

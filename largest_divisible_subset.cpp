#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> ans;
        vector<int> dp(n,1);
        vector<int> index(n,-1);
        int maxlen=1;
        int maxind = 0;
        for(int i = 1;i<nums.size();i++)
        {
            for(int j = 0;j < i;j++)
            {
                if(nums[i] %nums[j] == 0)
                {
                    if(1+dp[j] > dp[i])
                    {
                        index[i] = j;
                        dp[i] = 1 + dp[j];
                    }
                   
                    
                    
                }
                
                // maxlen = max(maxlen,dp[i]);
            }
            if(maxlen<dp[i])
            {
                maxind = i;
                maxlen = dp[i];
            }
        }
        while(maxind != -1)
        {
            ans.push_back(nums[maxind]);
            maxind = index[maxind];
        }
        return ans;
        
    }
};
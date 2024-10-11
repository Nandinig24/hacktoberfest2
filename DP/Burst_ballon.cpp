https://leetcode.com/problems/burst-balloons/

class Solution {
public:
    int find(int i,int j,vector<int>&nums,vector<vector<int>>&dp){
        if(i>j)
        return 0;

        if(dp[i][j]!=-1)
        return dp[i][j];
        int mx=INT_MIN;

        for(int k=i;k<=j;k++){
            mx=max(mx,nums[i-1]*nums[k]*nums[j+1]+find(i,k-1,nums,dp)+find(k+1,j,nums,dp));
        }
return dp[i][j]=mx;
        
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
            nums.insert(nums.begin(),1);   // age pich1 1 insert kr do

        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int ans=find(1,n,nums,dp);
        return ans;



    }
};

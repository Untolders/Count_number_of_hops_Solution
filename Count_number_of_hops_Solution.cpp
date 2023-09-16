*****************************************************************************************************************************************************************************  Question  ********************************************************************************************

A frog jumps either 1, 2, or 3 steps to go to the top. In how many ways can it reach the top of Nth step. As the answer will be large find the answer modulo 1000000007.

Example 1:

Input:
N = 1
Output: 1
Example 2:

Input:
N = 4
Output: 7
Explanation:Below are the 7 ways to reach
4
1 step + 1 step + 1 step + 1 step
1 step + 2 step + 1 step
2 step + 1 step + 1 step
1 step + 1 step + 2 step
2 step + 2 step
3 step + 1 step
1 step + 3 step
Your Task:
Your task is to complete the function countWays() which takes 1 argument(N) and returns the answer%(10^9 + 7).

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ N ≤ 105


  ***************************************************************************************************************************************************************************  Solution  **********************************************************************************************
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        
        // your code here
         const int MOD=1000000007;
            if(n==0)
            return 1;
            if(n<0)
            return 0;//as we don't want a negative value in the number of loops
        
        int dp[n+1];
        dp[0]=1;//one way to go top in one step
        
         for(int i=1;i<=n;i++){
             dp[i]=0;//counts no. of ways to go to the top by storing in dp[i]
              for(int j=1;j<=3;j++){
                  if(i-j>=0){
                      dp[i]=(dp[i]+dp[i-j])%MOD;
                  }
              }
         }
       return dp[n]; 
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends
  

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<long>>dp (n,vector<long>(K+1,INT_MAX));
        K=min(K,n-2);
        dp[src][0]=0;
        for(const auto &flight:flights){
            auto start = flight[0];
            auto end = flight[1];
            auto price = flight[2];
            if(start==src)
                dp[end][0]=min(dp[end][0],(long)price);
        }

        for (int k = 1; k <= K; k++) {
            for (const auto& flight : flights) {
                auto u = flight[0];
                auto v = flight[1];
                auto w = flight[2];
                // The minimum price of reach end in k steps is the minimum of w (price) 
                // of reaching v in k - 1 steps (no need to transfer at step k) and
                // the mimimum of reaching end v in k steps.
                dp[v][k] = min({dp[v][k - 1], dp[v][k], dp[u][k - 1] + w});
            }
        }

        return dp[dst][K]==INT_MAX?-1:dp[dst][K];
    }
};
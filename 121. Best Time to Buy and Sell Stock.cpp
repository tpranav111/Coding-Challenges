//121. Best Time to Buy and Sell Stock      https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minP = INT_MAX;
        int maxP = 0;
        for(int i=0; i<n; i++){
            if(prices[i] < minP)
                minP = prices[i];
            if(prices[i] - minP > maxP)
                maxP = prices[i] - minP;
        }
        return maxP;
    }
};
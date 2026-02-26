class Solution {
public:
    int maxProfit(vector<int>& prices) {
         int min_price = INT_MAX;   
        int max_price = 0;        

        for (int i = 0; i < prices.size(); i++) {
            int price = prices[i];

            if (price < min_price) {
                min_price = price;     
            }
            else {
                max_price = max(max_price, price - min_price);
            }
        }
        return max_price;
    }
};
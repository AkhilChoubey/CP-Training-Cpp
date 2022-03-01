
// we are given with array of prices , we have to return max profit(sum of all profits) , by buying and selling the product.
//  Ex - [7, 1, 5, 3, 6, 4]
//  output : 7 (5-1 = 4 , 6 - 3 = 3) = 4 + 3 = 7

// Logic : If the next element is greater than current element , it will give us profit and
//         we will add profit for all the cases where next element is greater than previous one.

int maxProfit(vector<int> &prices)
{
    int profit = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] > prices[i - 1])
        {
            profit += prices[i] - prices[i - 1];
        }
    }
    return profit;
}
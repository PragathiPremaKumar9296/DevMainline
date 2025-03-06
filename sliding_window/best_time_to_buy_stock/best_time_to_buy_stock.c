#include <stdio.h>
#include <stdlib.h>

int maxProfit(int *price, int priceSize)
{
    int max_profit = 0;
    int right = 1;
    int left = 0;
    int profit;

    while (right < priceSize) {
        if (price[right] < price[left]) {
            left = right;
        } else {
            profit = price[right] - price[left];
            if (profit > max_profit) 
                max_profit = profit;
        }
        right++;
    }
    return max_profit;    
}

int main() 
{
    int prices[] = {10, 1, 5, 6, 7, 1};
    int priceSize = sizeof(prices)/sizeof(prices[0]);
    int res = maxProfit(prices, priceSize);
    printf("max profit: %d\n", res);
    return 0;
}
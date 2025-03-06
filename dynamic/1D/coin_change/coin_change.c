#include <limits.h>

int coinChange(int* coins, int coinsSize, int amount) {
    int dp[amount + 1];

    for (int i = 0; i <= amount; i++)
        dp[i] = INT_MAX;
    
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < coinsSize; j++) {
            int coin = coins[j];
            if (i >= coin && dp[i - coin] != INT_MAX)
                dp[i] = (dp[i] < dp[i - coin] + 1) ? dp[i] : (dp[i - coin] + 1);
        }
    }
    return (dp[amount] == INT_MAX) ? -1 : dp[amount];
}
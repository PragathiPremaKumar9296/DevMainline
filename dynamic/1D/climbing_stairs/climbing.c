int climbStairs(int n) {
    int first = 1;
    int second = 2;
    int temp;

    if (n <= 2)
        return n;

    for (int i = 3; i <= n; i++) {
        temp = first + second;
        first = second;
        second = temp;
    }
    return second;
}
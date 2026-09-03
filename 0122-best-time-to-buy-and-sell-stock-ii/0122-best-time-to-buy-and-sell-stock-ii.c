int maxProfit(int* prices, int size)
{
    int sum = 0;

    for(int i = 1; i < size; i++)
    {
        if(prices[i] > prices[i-1])
        {
            sum += prices[i] - prices[i-1];
        }
    }

    return sum;
}
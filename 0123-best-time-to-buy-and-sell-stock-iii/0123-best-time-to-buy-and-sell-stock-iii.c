int maxProfit(int* prices, int size)
{
    int buy1 = -prices[0];
    int sell1 = 0;
    int buy2 = -prices[0];
    int sell2 = 0;

    for(int i = 1; i < size; i++)
    {
        if(-prices[i] > buy1)
            buy1 = -prices[i];

        if(buy1 + prices[i] > sell1)
            sell1 = buy1 + prices[i];

        if(sell1 - prices[i] > buy2)
            buy2 = sell1 - prices[i];

        if(buy2 + prices[i] > sell2)
            sell2 = buy2 + prices[i];
    }

    return sell2;
}
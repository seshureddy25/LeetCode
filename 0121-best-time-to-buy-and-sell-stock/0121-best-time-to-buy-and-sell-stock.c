int maxProfit(int* prices, int size) {
    int minprice=prices[0];
    int maxprofit=0;
    for(int i=1;i<size;i++)
    {
        int profit = prices[i]-minprice;
        if(profit > maxprofit)
            maxprofit=profit;

        if(prices[i]<minprice)
            minprice=prices[i];
    }
    return maxprofit;
}
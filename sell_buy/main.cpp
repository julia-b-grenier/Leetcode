#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    int total_profit = 0;

    for (int i = 1; i<prices.size(); ++i) {
        if (prices[i-1] < prices[i]) {
            total_profit += prices[i] - prices[i-1];
        }
    }

    return total_profit;
}

int main() {
    vector<int> prices = {7,6,4,3,1};
    vector<int> prices2 = {7,1,5,3,6,4};

    cout << maxProfit(prices) << endl;
    cout << maxProfit(prices2) << endl;
}
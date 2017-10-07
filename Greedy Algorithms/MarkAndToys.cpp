/* Mark and Toys */
//The problem can be found at: https://www.hackerrank.com/challenges/mark-and-toys/problem

#include <bits/stdc++.h>

using namespace std;

int maximumToys(vector <int> prices, int k) {
    //First, we will sort the array of prices in ascending order
    sort(prices.begin(), prices.end());
    //Define variables for the array size, the current money amount spent, and the number of toys.
    int n = prices.size();
    int curTotal = 0;
    int numToys = 0;
    //Loop through the array and check if you can buy each toy. If you can, increment the numToys counter
    //This could be slightly optimized to stop looping once we reach the k dollar amount.
    for (int i = 0; i < n; i++){
        if(curTotal + prices[i] <= k){
            numToys++;
            curTotal += prices[i];
        }
    }
    return numToys;
}

//The entire main function was given
int main() {
    int n;
    int k;
    cin >> n >> k;
    vector<int> prices(n);
    for(int prices_i = 0; prices_i < n; prices_i++){
       cin >> prices[prices_i];
    }
    int result = maximumToys(prices, k);
    cout << result << endl;
    return 0;
}
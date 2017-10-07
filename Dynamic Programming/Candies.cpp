/* Candies */
//The problem can be found at: https://www.hackerrank.com/challenges/candies/problem

#include <bits/stdc++.h>
using namespace std;

long candies(int n, vector <int> arr) {
    //Make the DP array and initilize it to 1 (every kid must get at least 1 candy)
    vector<int> dp(n);
    for(int i = 0; i < n; i++){
        dp[i] = 1;
    }
    //make sure sum is a LONG variable, otherwise it fails on two test cases
    long sum = 0;
    //Pass through array from left->right; if right>left then increment the amount of candies that kid must get
    for(int i = 1; i < n; i++){
        if(arr[i] > arr[i-1])
            dp[i] = dp[i-1] + 1;
        else
            dp[i] = 1;
    }
    //Pass through array from right->left; if left>right then increment the amount of candies that kid must get
    //Also check if dp needs to be incremented since it could be correct from the first pass
    for(int i = n-2; i >= 0; i--){
        if(arr[i] > arr[i+1] && dp[i] <= dp[i+1])
            dp[i] = dp[i+1] + 1;
    }
    //Sum up the total amount of candies needed
    for(int i = 0; i < n; i++){
        sum += dp[i];
    }
    return sum;

}

//Entire main function was given
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    long result = candies(n, arr);
    cout << result << endl;
    return 0;
}
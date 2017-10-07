/* Sherlock and the Cost */
//The problem can be found at: https://www.hackerrank.com/challenges/sherlock-and-cost/problem

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int main() {
    //Get the number of testcases, run while there are still testcases left.
    int s = 0;
    int t; cin >> t;
    while (t--){
        //Get the number of values in the B array
        int n; cin >> n;
        //Create an array for b. Note: All values of B are positive
        vector <int> b(n);
        //Fill array
        for (int b_i = 0; b_i < n; b_i++){
            cin >> b[b_i];
        }
        //Create dynamic array with n rows and 2 columns
        int dp[n][2];
        //Initialize the first 2 positions in the matrix to be 0
        dp[0][0] = 0;
        dp[0][1] = 0;
        //We can maximize S by making Ai switch from being as small as possible to as big as possible in adjacent positions
        for (int i = 1; i < n; i ++){
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + abs(b[i - 1] - 1));
			dp[i][1] = max(dp[i - 1][0] + abs(b[i] - 1), dp[i - 1][1]);
        }
        /* This for loop will print out the values stored in the dp matrix
        for (int i = 0; i < n; i ++){
            cout << dp[i][0] << " ";
            cout << dp[i][1] << " \n";
        } */
        cout << max(dp[n - 1][0], dp[n - 1][1]) << endl;
    }
    return 0;
}

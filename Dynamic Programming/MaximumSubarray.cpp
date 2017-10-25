/* The maximum subarray */
//The problem can be found here: https://www.hackerrank.com/challenges/maxsubarray/problem

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
    //Get the inputs
    long t; cin >> t;
    while (t){
        long n; cin >> n;
        vector<long> v(n);
        for (int v_i = 0; v_i < n; v_i++){
            cin >> v[v_i];
        }
        long contig = 0;
        long noncontig = 0;
        //We need to calculate the maxmimum contiguous subarray sum and maximum non-contiguous sum
        //Non-contiguous is easy as we simply pick all the numbers greater than 0 and add them
        for(int i = 0; i < n; i++){
            if(v[i] > 0)
                noncontig += v[i];
        }
        //if all the elements are 0 or negative, find the largest element
        if(noncontig == 0){
            noncontig = v[0];
            for(int i = 0; i < n; i++){
                if(v[i] > noncontig){
                    noncontig = v[i];
                }
            }
        }
        //For contiguous, we need to use dynamic programming
        vector<long> dp(n);
        //Set the initial sums to be the single elements
        for (int i = 0; i < n; i++){
            dp[i] = v[i];
        }
        //Set contig to be the first element
        contig = dp[0];
        //Check if adding the subarray is greater than 0 and if it is greater than the next subarray sum
        for(int i = 0; i < n-1; i++){
            if(dp[i] + dp[i+1] > 0 && dp[i] + dp[i+1] > dp[i+1])
                dp[i+1] += dp[i];
        }
        //If everything is negative, then set contig to be the largest element
        for(int i = 0; i < n; i++){
            if(dp[i] > contig){
                contig = dp[i];
            }
        }
        cout << contig << " ";
        cout << noncontig << "\n";
        t--;
    }    
    return 0;
}

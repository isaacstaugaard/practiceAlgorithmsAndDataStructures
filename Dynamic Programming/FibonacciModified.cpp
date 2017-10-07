/* Fibonacci Modified */
//The problem can be found at: https://www.hackerrank.com/challenges/fibonacci-modified/problem

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

/****** THIS IMPLEMENTATION DOES NOT WORK FOR BIG NUMBERS ON HACKERRANK, BECAUSE WE CAN'T USE BIGINT LIBRARIES ******/
int main() {
    //Get the inputs
    long long t0; cin >> t0;
    long long t1; cin >> t1;
    int n; cin >> n;
    //Make an array to hold the previous values
    vector <long long> dp(n);
    dp[0] = t0;
    dp[1] = t1;
    for (int i = 2; i < n; i++){
        dp[i] = pow(dp[i-1],2) + dp[i-2];
    }
    cout << dp[n-1];
    return 0;
}

/* The following python 3 code will pass all test cases on hackerrank as python supports bigint */

/* ## Get inputs ##
a,b,n = input().split()
## Make array to hold values ##
arr = [0 for i in range(20)]
arr[0] = int(a)
arr[1] = int(b)
n = int(n)
## Loop through all values ##
for i in range(2,n):
    arr[i] = (arr[i-1]**2) + arr[i-2]
print (arr[n-1])
/*
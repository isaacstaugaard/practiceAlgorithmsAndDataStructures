/* Xor and Sum */
//The problem can be found at: https://www.hackerrank.com/challenges/xor-and-sum/problem

#include<iostream>
#include<string>
using namespace std;

int main()
{
    //Define variables needed
    string aStr, bStr;
    int a[500000], b[500000];
    int dp[500000][2];
    int modulo = 1000000007;
    //Get the inputs and place them into strings
    cin >> aStr;
    cin >> bStr;
    //Get the size of the strings
    int aLength = aStr.size(), bLength = bStr.size();
    //Loop through the strings and fill the arrays in reverse order 
    for (int i = 0; i < aLength; i++) {
        a[aLength - i - 1] = aStr[i] - '0';
    }
    for (int i = 0; i < bLength; i++){
        b[bLength - i - 1] = bStr[i] - '0';
    }
    //Place initial values into dp
    dp[0][0] = (b[0] == 0);
    dp[0][1] = (b[0] == 1);
    //Sum from i = 1 to n = 314159, fill dp arrays
    for (int i = 1; i < bLength + 314159; i++) {
        dp[i][0] = dp[i - 1][0] + (b[i] == 0);
        dp[i][1] = dp[i - 1][1] + (b[i] == 1);
    }
    long long answer = 0, cur = 0;

    for (int i = 0; i < bLength + 314159; i++) {
        int dp0, dp1;
        if (i < 314159) {
            dp0 = dp[i][0] + 314159 - i;
            dp1 = dp[i][1];
        }
        else {
            dp0 = 314159 + dp[bLength - 1][0] - dp[i - 314159 - 1][0];
            dp1 = dp[bLength - 1][1] - dp[i - 314159 - 1][1];
        }
        long long sum0 = a[i] * dp0;
        long long sum1 = (a[i] ^ 1) * dp1;
        long long sum = sum0 + sum1;
        if (i == 0)
            cur = 1;
        else 
            cur = (cur * 2) % modulo;
        
        long long tmp = (cur * sum) % modulo; 
        answer = (answer + tmp) % modulo;
    }
    cout << answer << endl;
    return 0;
}

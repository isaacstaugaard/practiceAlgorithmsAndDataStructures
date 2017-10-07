/* Minimum Absolute Difference in an Array */
//Can be found on hackerrank at https://www.hackerrank.com/challenges/minimum-absolute-difference-in-an-array/problem

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int minimumAbsoluteDifference(int n, vector <int> arr) {
    int answer;
    //Sort the given array
    sort(arr.begin(), arr.end());
    //Set the initial answer to be the absolute value of the first 2 numbers
    answer = abs(arr[0] - arr[1]);
    //Loop through the list and check if there are pairs that have a smaller abs difference than answer
    for (int i = 0; i < n-1; i++){
        if(abs(arr[i] - arr[i+1]) < answer)
            answer = abs(arr[i] - arr[i+1]);
    }
    return answer;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
        cin >> arr[arr_i];
    }
    int result = minimumAbsoluteDifference(n, arr);
    cout << result << endl;
    return 0;
}

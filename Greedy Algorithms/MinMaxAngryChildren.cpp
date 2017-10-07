/* Max Min (aka Angry Children) */
//The problem can be found at: https://www.hackerrank.com/challenges/angry-children/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    //This block of code was given
    int N, K, unfairness = INT_MAX;
    cin >> N >> K;
    int list[N];
    for (int i=0; i<N; i++)
        cin >> list[i];
    
    //We have a list of n integers, need to select the integers with a range of k that minimize the unfairness
    //First, we need to sort the list
    int z = sizeof(list)/sizeof(list[0]);
    sort(list, list+z);
    //Default unfairness is the differnece between the first k elements (k is guaranteed bigger than 1)
    unfairness = list[K-1] - list[0];
    //We then loop through the other values and check if there is a less unfair grouping
    for (int i = 0; i < ((N-K)+1); i++){
        if((list[i+K-1] - list[i] < unfairness)){
            unfairness = list[i+K-1] - list[i];
        }
     }
    cout << unfairness << "\n";
    return 0;
}

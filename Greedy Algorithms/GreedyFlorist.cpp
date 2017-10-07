/* Greedy Florist */
//The problem can be found at: https://www.hackerrank.com/challenges/greedy-florist/problem

#include <bits/stdc++.h>
using namespace std;

int main(){
    //Get the inputs
    int N, K;
    cin >> N >> K;
    //Make 2 arrays: C holds the cost of the flowers; T holds the current number of flowers bought by each customer
    vector<int> C(N), t(K);
    for(int i = 0; i < N; i++){
        cin >> C[i];
    }
    //Initialize all the amounts of flowers bought to be 0
    for(int i = 0; i < K; i++){
        t[i] = 0;
    }
    int result=0, j=0;
    //Sort the costs in descending order
    sort(C.rbegin(), C.rend());
    //The total money recieved comes from the formula below. Increment the amount bought by customer j. Change the customer by using modulo
    for(int i = 0; i <= N-1; i++){
        result += (t[j]+1)*C[i];
        t[j]++;
        j=(j+1)%K;
    }
    cout << result;
    return 0;
}
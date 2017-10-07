/* Priyanka and Toys */
//The problem can be found here: https://www.hackerrank.com/challenges/priyanka-and-toys/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    //Read the input
    int n; cin >> n;
    vector<int> w(n);   
    for(int w_i = 0; w_i < n; w_i++){
        cin >> w[w_i];
    }
    //Sort the array
    sort(w.begin(), w.end());
    //Declare variables
    int amount = 0;
    int weight = 0;
    //The first toy will always have to be bought. If there are toys within w0 + 4, then we don't have to buy those.
    //Therefore, we increment the counter until we get to another one we have to buy.
    for (int i = 0; i < n;){
        weight = w[i];
        amount++;
        i++;
        while(weight+4 >= w[i]){
            i++;
        }      
    }
    cout << amount;
    return 0;
}
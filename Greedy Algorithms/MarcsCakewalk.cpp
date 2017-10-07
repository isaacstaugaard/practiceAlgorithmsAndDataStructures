/* Marc's Cakewalk  */
// The problem can be found at: https://www.hackerrank.com/challenges/marcs-cakewalk/problem

#include <bits/stdc++.h>
using namespace std;

int main(){
    //Code to get the input.
    // n is the size of the input array; calories is the array of calorie values
    int n;
    cin >> n;
    vector<int> calories(n);
    for(int calories_i = 0; calories_i < n; calories_i++){
       cin >> calories[calories_i];
    }
    //Our greedy decision is to eat the cupcake with highest calories first
    //Sort the cupcakes in descending order
    sort(calories.rbegin(), calories.rend());
    //Make an long variable called miles
    long miles = 0;
    //For loop to get the total miles needed
    for(int i = 0; i < calories.size(); i++){
        miles += calories[i] * pow(2,i);
    }
    cout << miles;
    return 0;
}
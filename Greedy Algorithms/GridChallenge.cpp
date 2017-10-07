/* Grid Challenge */
//The problem can be found at: https://www.hackerrank.com/challenges/grid-challenge/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    //Get the input
    int t; cin >> t;
    //We need to check how many testcases are left
    while (t--){
        int n; cin >> n;
        char G[n][n];
        
        //Get each row and sort it
        for(int i = 0; i<n; i++){
            scanf("%s", G[i]);
            sort(G[i], G[i]+n);
        }
        
        //This boolean will allow us to break fromt he function if we find a column out of order
        bool b = false;
        for(int i = 0; i<n; i++){
            if(b){
                break;
            }
            //Only need to check columns because we know the rows are sorted
            for(int j = 0; j < n-1; j++){
                if(G[j+1][i] < G[j][i]){
                    b = true;
                    break;
                }
            }
        }
        //false --> Everything is in order
        if (b == false){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}
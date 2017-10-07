/* Sherlock and the Beast */
//The problem can be found here: https://www.hackerrank.com/challenges/sherlock-and-the-beast/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    //Get the inputs
    int t;
    cin >> t;
    while(t--){
        int decentNum; 
        cin >> decentNum;
        int temp = decentNum;
        int threes = 0;
        int fives = 0;
        while(temp > 0){
            if(temp % 3 == 0){
                fives = temp;
                break;
            }
            temp = temp - 5;
        }
        threes = decentNum - temp;
        if (temp < 0 || threes % 5 != 0)
            cout << -1 << "\n";
        else{
            while(fives--){
                cout << 5;
            }
            while(threes--){
                cout << 3;
            }
            cout << "\n";
        }
    }
    return 0;
}

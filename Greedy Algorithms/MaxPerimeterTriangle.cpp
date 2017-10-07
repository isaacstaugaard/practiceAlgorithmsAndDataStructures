/* Maximum Perimeter Triangle */
//The problem can be found at: https://www.hackerrank.com/challenges/maximum-perimeter-triangle/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//This helper function checks if the triangle is valid or not (degenerate would mean it has to be all on a line)
bool degenerate(int a, int b, int c){
    if(a + b <= c) return true;
    if(a + c <= b) return true;
    if(b + c <= a) return true;
    else return false;
}

int main() {
    //Get the input from stdin
    int n; cin >> n;
    int perim = -1;
    int s;
    bool g = false;
    vector <int> v;
    for (int i = 0; i < n; i++){
        cin >> s;
        v.push_back(s);
    }
    //Sort the array of stick lengths in descending
    sort(v.rbegin(),v.rend());
    //Check if there is a triangle that is not degenerate. Sorted in descending helps find largest perimeter     
    for(int i = 0; i < n-2; i++){
        if(!degenerate(v[i], v[i+1], v[i+2])){
            cout << v[i+2] << " " << v[i+1] << " " << v[i]; 
            g = true;
            break;
        }
    }
    //If the only valid triangle is degenerate, then output '-1'
    if(g == false){
        cout << -1;
    }
    return 0;
}
/* Luck Balance */
//The problem can be found at: https://www.hackerrank.com/challenges/luck-balance/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    //Get all of the inputs
    int N; cin >> N; 
    int K; cin >> K;
    int L, T;
    vector <int> v;
    int answer = 0;
    
    for (int i = 0; i < N; i++){
        cin >> L >> T;
        //If match is unimportant, just lose and add the luck
        if(T==0)
            answer += L;
        else{
            //If match is imporant, add luck factor to the array
            //All of the matches on the array will have importance = 1, so we don't need to specify
            v.push_back(L);
        }
    }
    //Sort the remaining luck array in descending order
    sort(v.rbegin(), v.rend());
    //K is the number of matches we can lose, so we choose to lose the matches worth the most luck
    while(K>0 && v.size() > 0){
        //Add the luck value to the answer, then erase the value from the array. Decrement k
        answer += v[0];
        v.erase(v.begin());
        K--;
    }
    //The remaining matches are all the ones we HAVE to win. Subtract the luck value from the answer.
    for (int i = 0; i<v.size();i++){
        answer -= v[i];
    }
    cout << answer; 
    return 0;
}
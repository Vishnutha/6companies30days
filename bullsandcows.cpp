#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int arr[10] = {0};
        int cows = 0;
        for(int i = 0;i<secret.length();i++)
        {
            if(secret[i] == guess[i])
            bulls++;
            else
            arr[(secret[i]-48)]++;
        }
        for(int i = 0;i<guess.length();i++)
        {
            if(secret[i] != guess[i] && arr[guess[i]-48] > 0)
            {
                
                arr[guess[i]-48]--;
                cows++;
            }

        }
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};
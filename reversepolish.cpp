#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // int ans = 0;
        stack<int> s;
        for(int i  = 0;i<tokens.size();i++)
        {
            if(!(tokens[i].compare("*")) || !(tokens[i].compare("-")) || 
            !(tokens[i].compare("+"))||!(tokens[i].compare("/")) )
            {
                int num1 = s.top();
                s.pop();
                int num2 = s.top();
                s.pop();
                if(!(tokens[i].compare("+")))
                {
                    s.push(num1+num2);
                }
                else if(!(tokens[i].compare("*")))
                {
                    s.push(num1*num2);
                }
                else if(!(tokens[i].compare("-")))
                {
                    s.push(num2-num1);
                }
                else if(!(tokens[i].compare("/")))
                {
                    s.push(num2/num1);
                }
            }
            else
            {
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};
#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
    bool isValid(string s) {
       std::stack<char> brackets;

    for (char ch : s) {
        if (ch == '(' || ch == '{' || ch == '[') {
            brackets.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (brackets.empty() || !((ch == ')' && brackets.top() == '(') ||
                                       (ch == '}' && brackets.top() == '{') ||
                                       (ch == ']' && brackets.top() == '['))) {
                return false;
            }
            brackets.pop();
        }
    }

    return brackets.empty(); 
    }
};
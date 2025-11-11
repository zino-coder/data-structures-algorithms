// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// An input string is valid if:
// 1. Open brackets must be closed by the same type of brackets.
// 2. Open brackets must be closed in the correct order.
// 3. Every close bracket has a corresponding open bracket of the same type.

#include <bits/stdc++.h>

bool isValidParentheses(std::string s) {
    std::stack<char> stack;
    std::unordered_map<char, char> map = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    for (const auto c : s) {
        if (c == '(' || c == '[' || c == '{') {
            // push parenthesis to stack
            stack.push(c);
        } else {
            if (stack.empty() || stack.top() != map[c]) {
                return false;
            }

            stack.pop(); // pop stack
        }
    }

    return stack.empty();
}

int main(int argc, char *argv[]) {
    std::string str;

    std::cout << "Input string: ";
    std::getline(std::cin, str);

    if (isValidParentheses(str)) {
        std::cout << "This string is valid parentheses!!!";
    } else {
        std::cout << "This string is not valid parentheses!!!";
    }
}

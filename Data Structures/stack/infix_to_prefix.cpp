#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

string infixToPrefix(const string& infix) {
    string prefix;
    stack<char> stack;
    string reversedInfix = infix;
    reverse(reversedInfix.begin(), reversedInfix.end());

    for (char ch : reversedInfix) {
        if (isalnum(ch)) {
            prefix += ch;
        } else if (ch == '(') {
            while (!stack.empty() && stack.top() != ')') {
                prefix += stack.top();
                stack.pop();
            }
            if (!stack.empty() && stack.top() == ')') {
                stack.pop();
            }
        } else if (ch == ')') {
            stack.push(ch);
        } else if (isOperator(ch)) {
            while (!stack.empty() && precedence(ch) < precedence(stack.top())) {
                prefix += stack.top();
                stack.pop();
            }
            stack.push(ch);
        }
    }

    while (!stack.empty()) {
        prefix += stack.top();
        stack.pop();
    }

    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    getline(cin, infix);

    string prefix = infixToPrefix(infix);
    cout << "Prefix expression: " << prefix << endl;

    return 0;
}

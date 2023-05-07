#include <iostream>
#include <stack>
#include <string>

using namespace std;

int evaluatePostfix(const string& postfix) {
    stack<int> stack;

    for (char ch : postfix) {
        if (isdigit(ch)) {
            stack.push(ch - '0');
        } else {
            int operand2 = stack.top();
            stack.pop();
            int operand1 = stack.top();
            stack.pop();

            int result;
            switch (ch) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
            }

            stack.push(result);
        }
    }

    return stack.top();
}

int main() {
    string postfix;
    cout << "Enter a postfix expression: ";
    getline(cin, postfix);

    int result = evaluatePostfix(postfix);
    cout << "Result: " << result << endl;

    return 0;
}

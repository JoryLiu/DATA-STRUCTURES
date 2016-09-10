#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool inferior(char a, char b) {
    if (b == '+' || b == '-') {
        if (a == '(') return true;
        return false;
    }
    if (b == '*' || b == '/' || b == '%') {
        if (a == '(' || a == '+' || a == '-') return true;
        return false;
    }
    if (b == '(') return true;
    if (b == ')') {
        if (a == '(') return true;
        return false;
    }
}

int main() {
    stack<char> s;
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
            cout << str[i];
        else {
            if (s.empty()) {
                s.push(str[i]);
                continue;
            }
            while (!inferior(s.top(), str[i])) {
                if (s.top() != '(') cout << s.top();
                s.pop();
                if (s.empty()) break;
            }
            if (str[i] != ')') s.push(str[i]);
            else s.pop();
        }
    }
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    return 0;
}

#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    string str;
    stack<char> s;
    bool flag;
    char temp;
    getline(cin, str);
    while (n--) {
        flag = true;
        getline(cin, str);
        while (!s.empty()) s.pop();
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '[' || str[i] == '{' || str[i] == '(')
                s.push(str[i]);
            if (str[i] == ']') {
                if (s.empty()) {
                    flag = false;
                    break;
                }
                temp = s.top();
                s.pop();
                if (temp != '[') {
                    flag = false;
                    break;
                }
            }
            if (str[i] == '}') {
                if (s.empty()) {
                    flag = false;
                    break;
                }
                temp = s.top();
                s.pop();
                if (temp != '{') {
                    flag = false;
                    break;
                }
            }
            if (str[i] == ')') {
                if (s.empty()) {
                    flag = false;
                    break;
                }
                temp = s.top();
                s.pop();
                if (temp != '(') {
                    flag = false;
                    break;
                }
            }
        }
        if (s.empty() && flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}

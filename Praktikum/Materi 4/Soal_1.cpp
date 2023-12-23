#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack> //pakai library stack 
#include <string>
using namespace std;

int isBalanced(string s) { 
    stack<char> st;

    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if (st.empty()) {
                return false; 
            }

            char top = st.top();
            st.pop();

            if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')) {
                return false; 
            }
        }
    }

    return st.empty(); 
}

int main() {
    string s;
    cin >> s;

    if (isBalanced(s)) {
        cout << "Mark Lee Hebat" << endl;
    } else {
        cout << "Coba lagi sampe dapet" << endl;
    }

    return 0;
}

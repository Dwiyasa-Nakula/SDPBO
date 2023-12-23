#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue> //pakai library queue
#include <string>
using namespace std;

//dibuat seperti ini dikarenakan kena runtime error
int isPalindrome(string str) {
    return equal(str.begin(), str.end(), str.rbegin());
}


int main() {
    string input;
    getline(cin, input);

    //Jika kurang dari constraint maka akan console Kurang gan karakternya(input karakter lebih dari atau sama dengan 3)
    if (input.length() < 3) {
        cout << "Kurang gan karakternya" << endl;
        return 1;
    }

    if (isPalindrome(input)) {
        cout << input << " Palindrom nih cuy" << endl;
    } else {
        cout << input << " Bukan Palindrom" << endl;
    }

    return 0;
}
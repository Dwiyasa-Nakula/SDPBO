#include <cmath>
#include <iostream>
using namespace std;

const int PRIME_CONST = 31;

int hashFunction(string key) {
    int hash = 0;
    int Final_hash = 0;
    const int PRIME_CONST = 11;
    // ASCII
    for (char c : key) {
        hash += static_cast<int>(c) - 97;
    }
    // Polinomial 
    for (int i = 0; i < key.length(); i++)
    {
        Final_hash =+ key[i] * pow(PRIME_CONST, i);
    }
    return Final_hash;
}

int main() {
    cout << hashFunction("abc") << endl;

    return 0;
}

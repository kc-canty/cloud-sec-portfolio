#include <iostream>
#include <cstring>
using namespace std;

void insecure_copy(char *input) {
    char buffer[10];
    strcpy(buffer, input); // insecure: no bounds checking
    cout << "Copied: " << buffer << endl;
}

int main() {
    char userInput[256];
    cout << "Enter input: ";
    cin >> userInput; // no input size validation
    insecure_copy(userInput);
    return 0;
}


#include <iostream>
#include <string>

using namespace std;

// Function to check if the input is numeric
bool isNumber(const string& s) {
    int len = s.length();
    for (int i = 0; i < len; i++) {
        if (s[i] < '0' || s[i] > '9') {
            return false;
        }
    }
    return true;
}

int main() {
    string CCnumber;
    cout << "This application uses the Luhn algorithm to validate your credit card number" << endl;
    cout << "If you wish to leave the app, type 'exit'" << endl;

    while (true) {
        cout << "Please enter your CC number: " << endl;
        cin >> CCnumber;

        if (CCnumber == "exit")
            break;

        if (!isNumber(CCnumber)) {
            cout << "Bad input, please enter a numeric credit card number" << endl;
            continue;
        }

        int len = CCnumber.length();
        int sum = 0;

        // Process each digit according to the Luhn algorithm
        for (int i = 0; i < len; i++) {
            int digit = CCnumber[len - 1 - i] - '0'; // Get the current digit

            if (i % 2 == 1) {
                // Double every second digit from the right
                digit *= 2;
                if (digit > 9) {
                    // If doubling results in a number greater than 9, sum the digits of this result
                    digit = digit / 10 + digit % 10;
                }
            }

            sum += digit;
        }

        // If the total modulo 10 is 0, then the number is valid
        if (sum % 10 == 0) {
            cout << "Valid" << endl;
        }
        else {
            cout << "Invalid" << endl;
        }
    }

    return 0;
}

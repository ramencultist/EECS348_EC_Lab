#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//Kyle Fleming
//Studnet ID: 93089
//Lab time: Friday 1pm


// Extraction function named to rubric
double extractNumeric(const string& input) {
    if (input.empty() || input.length() > 20) return -999999.99; // Checking for empty/ too long input

    bool hasdecimal = false; // check if decimal put
    bool Signed = false; // check to see if signed
    double integerpart = 0.0; // holds integer part
    double decimalpart = 0.0; // holds decimal part
    bool isnegative = false; // for if negative
    int i = 0; // Start from beginning of input

    // Check for sign at start of input
    if (input[0] == '+' || input[0] == '-') {
        Signed = true; // Mark number is signed
        isnegative = (input[0] == '-');  // check if +/-
        i++;
    }

    // Iterate through input
    while (i < input.length()) {
        char c = input[i];
        if (isdigit(c)) {  // check if current char is number
            if (!hasdecimal) {
                // no decimal means integer part
                integerpart = integerpart * 10 + (c - '0'); // converts it to a number by subracting '0' (ASCII 48) i.e. '1' (ascii49) - '0' (ascii48) = 1 (ascii1) <- actual number
            } else {
                // otherwise it is decimal
                decimalpart = decimalpart * 10 + (c - '0');
            }
        } else if (c == '.') {
            // decimal logic
            if (hasdecimal) {
                // repeat decimal -> invalid
                return -999999.99;
            }
            hasdecimal = true;  // note number has decimal
        } else {
            // Invalid character -> error
            return -999999.99;
        }
        i++;  // Move to next character in string
    }

    // Combine integer and decimal parts
    while (decimalpart >= 1) {
        // divide it until actually decimal
        decimalpart /= 10;
    }
    integerpart += decimalpart;
    // Apply negative if required
    return isnegative ? -integerpart : integerpart;
}

int main() {
    string input;
    cout << "Enter a string (type 'END' to quit): " << endl;
    while (true) {
        cout << "> ";
        getline(cin, input);  // Read input
        if (input == "END") break;  // end
        // run function
        double value = extractNumeric(input);
        if (value == -999999.99) {
            // invalid input
            cout << "The input is invalid." << endl;
        } else {
            // output formatted to 4 decimal places
            cout << "The input is: " << fixed << setprecision(4) << value << endl;
        }
    }
    return 0;
}

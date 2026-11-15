#include <iostream>
using namespace std;

int main() {
    char hex[50];

    while (true) {
        cout << "\nEnter a hexadecimal number (or 'q' to quit): ";
        cin >> hex;

        // Check if user wants to quit
        if ((hex[0] == 'q' || hex[0] == 'Q') && hex[1] == '\0') {
            cout << "Program closed." << endl;
            break;
        }

        // 1. Find length of the input manually
        int length = 0;
        while (hex[length] != '\0') {
            length++;
        }

        // 2. Skip "0x" or "0X" if present
        int start = 0;
        if (length >= 2 && hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X')) {
            start = 2;
        }

        // 3. HEXADECIMAL TO DECIMAL
        int decimal = 0;
        int base = 1;
        bool isValid = true;

        for (int i = length - 1; i >= start; i--) {
            char ch = hex[i];
            int digit = 0;

            if (ch >= '0' && ch <= '9') {
                digit = ch - '0';
            } else if (ch >= 'A' && ch <= 'F') {
                digit = ch - 'A' + 10;
            } else if (ch >= 'a' && ch <= 'f') {
                digit = ch - 'a' + 10;
            } else {
                cout << "Invalid hexadecimal character: " << ch << endl;
                isValid = false;
                break; // Stop checking this input and ask again
            }

            decimal = decimal + (digit * base);
            base = base * 16;
        }

        // If input was invalid, skip conversions and ask again
        if (!isValid || length == start) {
            continue;
        }

        cout << "Decimal : " << decimal << endl;

        // 4. DECIMAL TO ASCII
        if (decimal >= 32 && decimal <= 126) {
            cout << "ASCII   : " << (char)decimal << endl;
        } else {
            cout << "ASCII   : Non-printable character" << endl;
        }

        // 5. DECIMAL TO BINARY
        int binary[64];
        int temp = decimal;
        int binIndex = 0;

        if (temp == 0) {
            cout << "Binary  : 0" << endl;
        } else {
            while (temp > 0) {
                binary[binIndex] = temp % 2;
                temp = temp / 2;
                binIndex++;
            }
            cout << "Binary  : ";
            for (int j = binIndex - 1; j >= 0; j--) {
                cout << binary[j];
            }
            cout << endl;
        }

        // 6. DECIMAL TO OCTAL
        int octal[32];
        temp = decimal;
        int octIndex = 0;

        if (temp == 0) {
            cout << "Octal   : 0" << endl;
        } else {
            while (temp > 0) {
                octal[octIndex] = temp % 8;
                temp = temp / 8;
                octIndex++;
            }
            cout << "Octal   : ";
            for (int j = octIndex - 1; j >= 0; j--) {
                cout << octal[j];
            }
            cout << endl;
        }
    }

    return 0;
}

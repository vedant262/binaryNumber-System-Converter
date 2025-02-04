#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Function declarations
void nm(long long val1); // Binary to Decimal
void ac(long long val1); // Decimal to Octal
void nd(long long val1); // Decimal to Hexadecimal
void a12(long long val1); // Decimal to Binary
void king(long long val1); // Binary to Octal
void binaryToHex(long long val1); // Binary to Hexadecimal
void octalToDecimal(string nn); // Octal to Decimal
void octalToBinary(string nn); // Octal to Binary
void octalToHex(string nn); // Octal to Hexadecimal
void hexToDecimal(string nn); // Hexadecimal to Decimal
void hexToBinary(string nn); // Hexadecimal to Binary
void hexToOctal(string nn); // Hexadecimal to Octal

int if1(int n, int b, long long val1, string nn); // Conversion logic
int si(int n, long long val1, string nn); // Input handling

// Binary to Decimal
void nm(long long val1) {
    int b;
    int c = 1;
    long long d = 0;

    while (val1 > 0) {
        b = val1 % 10;
        if (b == 1) {
            d += c;
        }
        c *= 2;
        val1 /= 10;
    }
    cout << "The decimal form of the number is = " << d << endl;
}

// Decimal to Octal
void ac(long long val1) {
    int arr[1000];
    int val = 0;
    while (val1 > 0) {
        arr[val++] = val1 % 8;
        val1 /= 8;
    }
    cout << "The entered number in octal form is: ";
    for (int n = val - 1; n >= 0; n--) {
        cout << arr[n];
    }
    cout << endl;
}

// Decimal to Hexadecimal
void nd(long long val1) {
    int val = 0;
    int arr[32];
    while (val1 > 0) {
        arr[val++] = val1 % 16;
        val1 /= 16;
    }
    cout << "The entered number in hexadecimal form is: ";
    for (int x = val - 1; x >= 0; x--) {
        switch (arr[x]) {
            case 10: cout << "A"; break;
            case 11: cout << "B"; break;
            case 12: cout << "C"; break;
            case 13: cout << "D"; break;
            case 14: cout << "E"; break;
            case 15: cout << "F"; break;
            default: cout << arr[x]; break;
        }
    }
    cout << endl;
}

// Decimal to Binary
void a12(long long val1) {
    long long aa = val1;
    int b, c;
    int n = 64; // Increase size for larger numbers
    int l[n];

    while (aa != 0) {
        b = aa / 2;
        c = aa % 2;
        l[--n] = c; // Store the binary digit and decrement n
        aa = b;

        // Handle the case where the number is zero or one
        if (aa == 0 || aa == 1) {
            l[--n] = aa;
            break;
        }
    }

    // Print the binary digits from the correct start position
    cout << "The entered number in binary form is: ";
    for (int a = n; a < 64; a++) {
        cout << l[a];
    }
    cout << endl;
}

// Binary to Octal
void king(long long val1) {
    // Convert binary to decimal first
    int decimal = 0, base = 1;
    while (val1 > 0) {
        int lastDigit = val1 % 10;
        decimal += lastDigit * base;
        base *= 2;
        val1 /= 10;
    }

    // Convert decimal to octal
    ac(decimal);
}

// Binary to Hexadecimal
void binaryToHex(long long val1) {
    // Convert binary to decimal first
    int decimal = 0, base = 1;
    while (val1 > 0) {
        int lastDigit = val1 % 10;
        decimal += lastDigit * base;
        base *= 2;
        val1 /= 10;
    }

    // Convert decimal to hexadecimal
    nd(decimal);
}

// Octal to Decimal
void octalToDecimal(string nn) {
    long long decimal = 0;
    for (size_t i = 0; i < nn.length(); i++) {
        decimal = decimal * 8 + (nn[i] - '0');
    }
    cout << "The decimal form of the number is = " << decimal << endl;
}

// Octal to Binary
void octalToBinary(string nn) {
    long long decimal = 0;
    for (size_t i = 0; i < nn.length(); i++) {
        decimal = decimal * 8 + (nn[i] - '0');
    }
    a12(decimal);
}

// Octal to Hexadecimal
void octalToHex(string nn) {
    long long decimal = 0;
    for (size_t i = 0; i < nn.length(); i++) {
        decimal = decimal * 8 + (nn[i] - '0');
    }
    nd(decimal);
}

// Hexadecimal to Decimal
void hexToDecimal(string nn) {
    long long decimal = 0;
    for (size_t i = 0; i < nn.length(); i++) {
        char ch = nn[i];
        if (ch >= '0' && ch <= '9') {
            decimal = decimal * 16 + (ch - '0');
        } else if (ch >= 'A' && ch <= 'F') {
            decimal = decimal * 16 + (ch - 'A' + 10);
        } else if (ch >= 'a' && ch <= 'f') {
            decimal = decimal * 16 + (ch - 'a' + 10);
        }
    }
    cout << "The decimal form of the number is = " << decimal << endl;
}

// Hexadecimal to Binary
void hexToBinary(string nn) {
    long long decimal = 0;
    for (size_t i = 0; i < nn.length(); i++) {
        char ch = nn[i];
        if (ch >= '0' && ch <= '9') {
            decimal = decimal * 16 + (ch - '0');
        } else if (ch >= 'A' && ch <= 'F') {
            decimal = decimal * 16 + (ch - 'A' + 10);
        } else if (ch >= 'a' && ch <= 'f') {
            decimal = decimal * 16 + (ch - 'a' + 10);
        }
    }
    a12(decimal);
}

// Hexadecimal to Octal
void hexToOctal(string nn) {
    long long decimal = 0;
    for (size_t i = 0; i < nn.length(); i++) {
        char ch = nn[i];
        if (ch >= '0' && ch <= '9') {
            decimal = decimal * 16 + (ch - '0');
        } else if (ch >= 'A' && ch <= 'F') {
            decimal = decimal * 16 + (ch - 'A' + 10);
        } else if (ch >= 'a' && ch <= 'f') {
            decimal = decimal * 16 + (ch - 'a' + 10);
        }
    }
    ac(decimal);
}

// Conversion logic
int if1(int n, int b, long long val1, string nn) {
    if (n == 1 && b == 2) {
        a12(val1); // Decimal to Binary
    } else if (n == 1 && b == 3) {
        ac(val1); // Decimal to Octal
    } else if (n == 1 && b == 4) {
        nd(val1); // Decimal to Hexadecimal
    } else if (n == 2 && b == 1) {
        nm(val1); // Binary to Decimal
    } else if (n == 2 && b == 3) {
        king(val1); // Binary to Octal
    } else if (n == 2 && b == 4) {
        binaryToHex(val1); // Binary to Hexadecimal
    } else if (n == 3 && b == 1) {
        octalToDecimal(nn); // Octal to Decimal
    } else if (n == 3 && b == 2) {
        octalToBinary(nn); // Octal to Binary
    } else if (n == 3 && b == 4) {
        octalToHex(nn); // Octal to Hexadecimal
    } else if (n == 4 && b == 1) {
        hexToDecimal(nn); // Hexadecimal to Decimal
    } else if (n == 4 && b == 2) {
        hexToBinary(nn); // Hexadecimal to Binary
    } else if (n == 4 && b == 3) {
        hexToOctal(nn); // Hexadecimal to Octal
    } else {
        cout << "Invalid conversion!" << endl;
    }
    return 0;
}

// Input handling
int si(int n, long long val1, string nn) {
    int b;
    cout << "Enter the type you want to convert it into:\n"
         << "1. for Number\n"
         << "2. for Binary\n"
         << "3. for Octal\n"
         << "4. for Hexadecimal\n";
    cin >> b;

    if (n == b) {
        cout << "Your input is wrong. Both are the same, so it can't be changed.\n";
        return 0;
    }

    if1(n, b, val1, nn);
    return 0;
}

int main() {
    string nn;
    long long val1;
    int n;

    cout << "Enter the value type you want to convert (choose the number):\n"
         << "1. for Number\n"
         << "2. for Binary\n"
         << "3. for Octal\n"
         << "4. for Hexadecimal\n";
    cin >> n;

    if (n == 1 || n == 2) {
        cout << "Enter the number you want to convert:\n";
        cin >> val1;
    } else if (n == 3 || n == 4) {
        cout << "Enter the number you want to convert:\n";
        cin >> nn;
    } else {
        cout << "Invalid input!" << endl;
        return 1;
    }

    si(n, val1, nn);
    return 0;
}
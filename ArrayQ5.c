#include <stdio.h>
#include <math.h>
#include <string.h>

int convertBinaryToDecimal(long long binaryNumber);
int convertOctalToDecimal(int octalNumber);
int convertHexToDecimal(char hexNumber[]);

int main() {
    int choice;
    printf("Enter the conversion choice:\n");
    printf("1. Binary to Decimal\n");
    printf("2. Octal to Decimal\n");
    printf("3. Hexadecimal to Decimal\n");
    scanf("%d", &choice);

    if (choice == 1) {
        long long binaryNumber;
        printf("Enter a binary number: ");
        scanf("%lld", &binaryNumber);
        int decimalNumber = convertBinaryToDecimal(binaryNumber);
        printf("Decimal equivalent: %d\n", decimalNumber);
    } else if (choice == 2) {
        int octalNumber;
        printf("Enter an octal number: ");
        scanf("%o", &octalNumber);
        int decimalNumber = convertOctalToDecimal(octalNumber);
        printf("Decimal equivalent: %d\n", decimalNumber);
    } else if (choice == 3) {
        char hexNumber[100];
        printf("Enter a hexadecimal number: ");
        scanf("%s", hexNumber);
        int decimalNumber = convertHexToDecimal(hexNumber);
        printf("Decimal equivalent: %d\n", decimalNumber);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}

int convertBinaryToDecimal(long long binaryNumber) {
    int decimalNumber = 0, i = 0, remainder;
    while (binaryNumber != 0) {
        remainder = binaryNumber % 10;
        binaryNumber /= 10;
        decimalNumber += remainder * pow(2, i);
        ++i;
    }
    return decimalNumber;
}

int convertOctalToDecimal(int octalNumber) {
    int decimalNumber = 0, i = 0, remainder;
    while (octalNumber != 0) {
        remainder = octalNumber % 10;
        octalNumber /= 10;
        decimalNumber += remainder * pow(8, i);
        ++i;
    }
    return decimalNumber;
}

int convertHexToDecimal(char hexNumber[]) {
    int decimalNumber = 0, length = strlen(hexNumber), i = 0;
    for (i = 0; i < length; i++) {
        if (hexNumber[i] >= '0' && hexNumber[i] <= '9') {
            decimalNumber = decimalNumber * 16 + (hexNumber[i] - '0');
        } else if (hexNumber[i] >= 'A' && hexNumber[i] <= 'F') {
            decimalNumber = decimalNumber * 16 + (hexNumber[i] - 'A' + 10);
        } else if (hexNumber[i] >= 'a' && hexNumber[i] <= 'f') {
            decimalNumber = decimalNumber * 16 + (hexNumber[i] - 'a' + 10);
        }
    }
    return decimalNumber;
}

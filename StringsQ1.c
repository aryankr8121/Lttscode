#include <stdio.h>
#include <ctype.h> // for toupper and tolower functions

void toggleCase(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (isupper(str[i]))
            str[i] = tolower(str[i]);
        else if (islower(str[i]))
            str[i] = toupper(str[i]);
    }
}

int main() {
    char str[100];
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    printf("Input String: %s", str);
    
    toggleCase(str);
    
    printf("Output String: %s", str);
    
    return 0;
}

#include <stdio.h>
#include <stdlib.h> // for atoi() function

int main() {
    char str[100];
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove the newline character from the string
    str[strcspn(str, "\n")] = '\0';
    
    printf("Input String: %s\n", str);
    
    int value = atoi(str);
    
    printf("Integer Value: %d\n", value);
    
    return 0;
}

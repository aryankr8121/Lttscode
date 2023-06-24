#include <stdio.h>

int main() {
    int arr[10];
    int len, i;
    int min, max;
    
    printf("Enter the length of the array (up to 10): ");
    scanf("%d", &len);
    
    printf("Enter the elements of the array:\n");
    for (i = 0; i < len; i++) {
        printf("Element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    
    min = arr[0];
    max = arr[0];
    
    for (i = 1; i < len; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    printf("\nMinimum value: %d\n", min);
    printf("Maximum value: %d\n", max);
    
    return 0;
}

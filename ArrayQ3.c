#include <stdio.h>

void reverseArray(int arr[], int len) {
    int start = 0;
    int end = len - 1;
    int temp;
    
    while (start < end) {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        
        start++;
        end--;
    }
}

int main() {
    int arr[100];
    int len, i;
    
    printf("Enter the length of the array: ");
    scanf("%d", &len);
    
    printf("Enter the elements of the array:\n");
    for (i = 0; i < len; i++) {
        printf("Element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    
    printf("\nOriginal Array: ");
    for (i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    
    reverseArray(arr, len);
    
    printf("\nReversed Array: ");
    for (i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\n");
    
    return 0;
}

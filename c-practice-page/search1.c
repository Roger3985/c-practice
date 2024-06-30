#include <stdio.h>
#include <stdlib.h>

int Sequential_Search(int *a, int n, int key) {
    int i;
    for (i = 1; i <= n; i++) {
        if (a[i] == key)
            return i;
    }
    return 0;
}

/* 循序查詢，a為陣列，n為要查詢的陣列個數，key為要查詢的關鍵字 */
int main(int argc, char const *argv[]) {
    // Sample array and key for demonstration
    int a[] = {0, 1, 2, 3, 4, 5}; // Note: a[0] is unused
    int n = 5; // Number of elements to search in (excluding a[0])
    int key = 3;
    
    int result = Sequential_Search(a, n, key);
    if (result != 0) {
        printf("Key found at index %d\n", result);
    } else {
        printf("Key not found\n");
    }

    return 0;
}

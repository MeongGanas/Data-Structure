#include <stdio.h>
#include <stdlib.h> 

int is_prime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n, q;
    
    scanf("%d %d", &n, &q);
    
    int *a = (int *)malloc(n * sizeof(int));       // Memesan memori dinamis untuk n integer
    int *b = (int *)malloc(n * sizeof(int));       // Array dinamis untuk angka yang habis dibagi prima
    int *temp_a = (int *)malloc(n * sizeof(int));  // Array sementara untuk angka yang tidak habis dibagi
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int a_size = n;
    
    int primes[1200];
    int count = 0, num = 2;
    while (count < q) {
        if (is_prime(num)) {
            primes[count++] = num;
        }
        num++;
    }
    printf("\nOUTPUT\n");
    for (int i = 0; i < q; i++) {
        int b_size = 0;
        int temp_a_size = 0;
        
        for (int j = a_size - 1; j >= 0; j--) {
            if (a[j] % primes[i] == 0) {
                b[b_size++] = a[j];
            } else {
                temp_a[temp_a_size++] = a[j];
            }
        }
        
        for (int j = b_size - 1; j >= 0; j--) {
            printf("%d\n", b[j]);
        }
        
        a_size = temp_a_size;
        for (int j = 0; j < a_size; j++) {
            a[j] = temp_a[j];
        }
    }
    
    for (int j = a_size - 1; j >= 0; j--) {
        printf("%d\n", a[j]);
    }

    free(a);       // Membebaskan memori array a dari mallocnya
    free(b);       // Membebaskan memori array b dari mallocnya
    free(temp_a);  // Membebaskan memori array temp_a dari mallocnya

    return 0;
}
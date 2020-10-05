#include<stdio.h>

long long int fibo_index(int n) {

    long long int arr[n];
    for (int i = 0; i < n; i++) {
        int val = 0;                    // C - programming doesn't include vectors
        arr[i] = val;                   // Making an array of size n with 0.
    }

    arr[0] = 0;                       // Setting first element of the array to 0.
    arr[1] = 1;                       // Next element to 1.
    printf("%lld %lld ", arr[0], arr[1]);
    for (int i = 2; i <= n; i++) {
        arr[i] = arr[i-1] + arr[i-2];
        printf("%lld ", arr[i]);
    }
    printf("\n");

    return arr[n];
}

int main() {
    int n;
    printf("Enter the index of Fibonacci Number you want to calculate:  ");
    scanf("%d", &n);
    printf("Fibonacci Series:  ");
   long long int ans =  fibo_index(n);
    printf("Fibonacci number:  ");
    printf("%lld\n",ans);
}


// Printing Fibonacci sequence and fibonacci numbers.

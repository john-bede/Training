#include<stdio.h>
int main() {
    int a, b, sum;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    sum = a + b;
    printf("The sum is: %d\n", sum);
    return 0;
}
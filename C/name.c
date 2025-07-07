#include<stdio.h>
int main() {
    char name[100];
    printf("Enter your full name: ");
    scanf("%99[^\n]", name);
    printf("\nHello, %s!\n", name);
    printf("\n");
    return 0;
}
#include <stdio.h>
int power(int base, int exp);
int isArmstrong(int num, int n);
int countDigits(int num);
int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    int digits = countDigits(num);
    if (num == isArmstrong(num, digits)) {
        printf("%d is an Armstrong number.\n", num);
    } else {
        printf("%d is not an Armstrong number.\n", num);
    }

    return 0;
}
int power(int base, int exp) {
    if (exp == 0)
        return 1;
    return base * power(base, exp - 1);
}
int isArmstrong(int num, int n) {
    if (num == 0)
        return 0;
    int digit = num % 10;
    return power(digit, n) + isArmstrong(num / 10, n);
}
int countDigits(int num) {
    if (num == 0)
        return 0;
    return 1 + countDigits(num / 10);
}



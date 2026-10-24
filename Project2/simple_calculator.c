#include <stdio.h>

int main() {


    char operator;
    double Num1;
    double Num2;
    double result;

    printf("\nSelect operator (+,-,x,/): ");
    scanf("%c", &operator);

    printf("Number 1: ");
    scanf("%lf", &Num1);

    printf("Number 2: ");
    scanf("%lf", &Num2);
    

    switch(operator) {
        case '+':
            result = Num1 + Num2;
            printf("\nresult: %.2lf", result);
            break;
        case '-':
            result = Num1 - Num2;
            printf("\nresult: %.2lf", result);
            break;
        case 'x':
            result = Num1 * Num2;
            printf("\nresult: %.2lf", result);
            break;
        case '/':
            result = Num1 / Num2;
            printf("\nresult: %.2lf", result);
            break;
        default:
            printf("%c Invalied operator\n");
    }

    return 0;
}
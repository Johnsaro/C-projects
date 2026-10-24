#include <stdio.h>

int main(void) {
    char name[30];


    printf("========== POSTPAID BILL CALCULATOR ==========\n");
    printf("Enter customer name: ");
    fgets(name, sizeof(name), stdin);
    printf("Name: %s", name);
    printf("========== TESTING ==========");


    return 0;
}
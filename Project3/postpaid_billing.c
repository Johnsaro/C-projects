#include <stdio.h>

int main(void) {
    char name[30];
    int plan_rate;
    int call_minutes;
    int sms_sent;
    int data_used;

    printf("========== POSTPAID BILL CALCULATOR ==========\n");
    printf("Enter customer name: ");

    // fegets(variable, sizeof(variable), stdin)  without \n
    fgets(name, sizeof(name), stdin);
    printf("Plan rate (PHP): ");
    scanf("%d", plan_rate);
    printf("Call minutes used: ");
    scanf("%d", call_minutes);
    printf("SMS sent: ");
    scanf("%d", sms_sent);
    printf("Data used (GB): ");
    scanf("%d", data_used);

    printf("\n========== BILL SUMMARY ==========\n");
    printf("Customer: %s", name);
    printf("Plan: n/a");
    
    printf("========== TESTING ==========");


    return 0;
}
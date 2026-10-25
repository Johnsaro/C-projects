#include <stdio.h>
#include <string.h>

typedef struct {
    char name[30];
    float plan_rate;
    int call_minutes;
    int sms_sent;
    int data_used;
} Customer;


int main(void) {

    Customer consumer1 = {"John Doe", 999, 250, 180, 18};


    printf("========== POSTPAID BILL CALCULATOR ==========\n");
    printf("Customer: %c\n", consumer1.name);
    printf("Plan PHP %.2f\n", consumer1.plan_rate);
    printf("Call minutes used: %d\n", consumer1.call_minutes);
    printf("SMS sent: %d\n", consumer1.sms_sent);
    printf("Data used (GB): %d\n", consumer1.data_used);

    return 0;
}   
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

    Customer consumer1; // empty

    printf("Enter Customer Name: ");
    fgets(consumer1.name,sizeof(consumer1.name), stdin);
    printf("Plan rate (PHP): ");
    scanf("%f", &consumer1.plan_rate);
    printf("Call minutes used: ");
    scanf("%d", &consumer1.call_minutes);
    printf("SMS sent: ");
    scanf("%d", &consumer1.sms_sent);
    printf("Data used (GB): ");
    scanf("%d", &consumer1.data_used);


    printf("\n\n========== POSTPAID BILL CALCULATOR ==========\n");
    printf("Customer: %s", consumer1.name); // Note: use %s for string 
    printf("Plan PHP %.2f\n", consumer1.plan_rate);
    printf("Call minutes used: %d\n", consumer1.call_minutes);
    printf("SMS sent: %d\n", consumer1.sms_sent);
    printf("Data used (GB): %d\n", consumer1.data_used);

    return 0;
}   
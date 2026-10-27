#include <stdio.h>
#include <string.h>

#include <limits.h> // For INT_MAX
// // Data plan
// #define BASIC 599
// #define STANDARD 999
// #define PREMUIM 1499


// // free plan package
// #define FREE_MINUTES 
// #define FREE_SMS 100
// #define FREE_DATA 15


typedef enum { TYPE_NUM, TYPE_STR} LimitType;

typedef struct {
    LimitType type;
    union {
        int num;
        const char *str;
    } val;
} Limit;

typedef struct {
    char name[30];
    float plan_rate;
    int call_minutes;
    int sms_sent;
    int data_used;
} Customer;



typedef struct {
    const char *name;
    int price;
    Limit calls;
    Limit texts;
    int data_gb;
} Data_Plan;


// 2. Custom printing helper
// check type and prints if either num or string "unli"

void print_limit(Limit limit) {
    if(limit.type == TYPE_STR) {
        printf("%-6s", limit.val.str);
    } else {
        printf("%-6d", limit.val.num);
    }
}


// 3. Custom  Calculation helper

int get_limit_value(Limit limit) {
    if(limit.type == TYPE_STR) {
        return INT_MAX; // Treat "Unli" as infinity value
    }
    return limit.val.num;
}





int main(void) {

    // create an array 
    Data_Plan options[3] = {
        {"Basic", 599, {TYPE_NUM, .val.num = 100}, {TYPE_NUM, .val.num = 100}, 8},
        {"Basic", 999, {TYPE_NUM, .val.num = 200}, {TYPE_NUM, .val.num = 100}, 15}, 
        {"Basic", 1499, {TYPE_STR, .val.str = "Unli"}, {TYPE_STR, .val.str = "Unli"}, 30}
    };

    // Displayiing the plans
    printf("=========================================\n");
    printf("%-10s | %-6s | %-6s | %-6s | %s\n", "Plan", "Price", "Calls", "Texts", "Data");
    printf("=========================================\n");

    for (int i = 0; i < 3; i++) {
        printf("%-10s | P%-5d | ", options[i].name, options[i].price);

        print_limit(options[i].calls);
        printf(" | ");
        print_limit(options[i].texts);

        printf(" | %d GB\n", options[i].data_gb);
    }
      printf("=========================================\n\n");

        


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
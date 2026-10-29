#include <stdio.h>
#include <string.h>

#include <limits.h> // For INT_MAX
// Data plan
#define BASIC 599
#define STANDARD 999
#define PREMUIM 1499

// // free plan package
// #define FREE_MINUTES 
// #define FREE_SMS 100
// #define FREE_DATA 15


typedef enum { TYPE_NUM, TYPE_STR, TYPE_NONE} LimitType;

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
    } else if (limit.type == TYPE_NUM){
        printf("%-6d", limit.val.num);
    } else {
        printf("%-6s", "None");
    }
}


// 3. Custom  Calculation helper
int get_limit_value(Limit limit) {
    if (limit.type == TYPE_STR) {
        return INT_MAX; // Treat "unli" as infinity for logic checks
    } else if (limit.type == TYPE_NONE) {
        return 0;
    }
    return limit.val.num;
}

// same as print_limit but no padding, for the bill summary
void print_limit_plain(Limit limit) {
    if (limit.type == TYPE_STR) {
        printf("%s", limit.val.str);
    } else if (limit.type == TYPE_NUM) {
        printf("%d", limit.val.num);
    } else {
        printf("0");
    }
}

// TODO: options only exists in main - pass it in as a parameter
// void billing_summary(Data_Plan options[], int count) {
//     for(int i = 0; i < count; i++) {
//
//     }
// }
void print_plan(Data_Plan p) {
    printf("%-10s | P%-5d | ", p.name, p.price);
    print_limit(p.calls);
    printf(" | ");
    print_limit(p.texts);
    printf(" | %d GB\n", p.data_gb);
}


int main(void) {
    // create an array 
    Data_Plan options[] = {
        {"Basic", 599, {TYPE_NONE}, {TYPE_NUM, .val.num = 100}, 8},
        {"Standard", 999, {TYPE_NUM, .val.num = 200}, {TYPE_NUM, .val.num = 100}, 15}, 
        {"Premium", 1499, {TYPE_STR, .val.str = "Unli"}, {TYPE_STR, .val.str = "Unli"}, 30}
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


    printf("\n\n========== POSTPAID BILL CALCULATOR ==========\n");

    printf("Enter Customer Name: ");
    fgets(consumer1.name, sizeof(consumer1.name), stdin);

    // fgets(consumer1.name,sizeof(consumer1.name), stdin);
    printf("Plan rate (PHP): ");
    scanf("%f", &consumer1.plan_rate);
    printf("Call minutes used: ");
    scanf("%d", &consumer1.call_minutes);
    printf("SMS sent: ");
    scanf("%d", &consumer1.sms_sent);
    printf("Data used (GB): ");
    scanf("%d", &consumer1.data_used);
  



    // find the plan that matches the entered rate
    Data_Plan xplan;
    int found = 0;
    for (int i = 0; i < 3; i++) {
        if (options[i].price == (int)consumer1.plan_rate) {
            xplan = options[i];
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No plan found for PHP %.0f\n", consumer1.plan_rate);
        return 1;
    }

    printf("\n\n========== BILL SUMMARY ==========\n");
    printf("Customer: %s", consumer1.name); // fgets keeps the \n
    printf("Plan: PHP %-5d  (incl. ", xplan.price);
    print_limit_plain(xplan.calls);
    printf(" min, ");
    print_limit_plain(xplan.texts);
    printf(" sms, %d GB)\n", xplan.data_gb);


    return 0;
}   
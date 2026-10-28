#include <stdio.h>

// 1. Enum
typedef enum { PRICE_NONE, PRICE_FREE, PRICE_FIXED, PRICE_DISCOUNT} PriceType;

// 2. Tagged union
typedef struct {
    PriceType type;
    union {
        int num;
        float discount;
    } val;
} Price;

// 3. Struct Item
typedef struct {
    char name[30];
    Price price_cost;
    Price price_discount;
} Item;

// 5 printprice
void print_price(Price price){
    switch(price.type) {
        case PRICE_FIXED:
            printf("%-6d", price.val.num);
            break;
        case PRICE_FREE:
            printf("%-6s","Free");
            break;
        case PRICE_DISCOUNT:
            printf("%.0f%%", price.val.discount);
            break;
        case PRICE_NONE:
            printf("%-6s", "-");
            break;
        default:
            printf("Invalid Price");
    }
}


int main(void) {

    // 4 Array of Item
    Item options[2] = {
        {"Apple", {PRICE_FREE}},
        {"Milk", {PRICE_FIXED, .val.num = 200}, {PRICE_DISCOUNT, .val.discount = 5}}
    };

    for (int i = 0; i < 2; i++) {
        printf("%-10s |  ", options[i].name);
        print_price(options[i].price_cost);
        printf(" | ");
        print_price(options[i].price_discount);
        printf("\n");
    }   
  

    return 0;
}
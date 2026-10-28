#  Tagged Union Practice
## struct2.c

Today I practiced building an array of structs with a tagged union, from a blank file with no notes.

## What I built
- An enum `PriceType` to list the kinds of price.
- A tagged union `Price`: a `type` tag plus a union `val` that holds the value.
- A struct `Item` with a name and a price.
- An array of 2 items and a `print_price()` function that checks the tag before reading the union.

## Mistakes I made and how I fixed them

### 1. I never called `print_price()`

The program printed nothing, and the compiler warned that `options` was unused.

Error code:
```c
Item options[2] = { ... };

return 0;   // nothing uses options
```

Fix:

I added a `for` loop that goes through the array and calls `print_price()` for each item.

Correct code:
```c
for (int i = 0; i < 2; i++) {
    printf("%-10s | ", options[i].name);
    print_price(options[i].price_cost);
    printf("\n");
}
```

---

### 2. I stored the string `"Free"` inside the union

The tag `PRICE_FREE` already says it's free, so the string was extra.

Error code:
```c
union {
    int num;
    const char *str;
} val;

{"Apple", {PRICE_FREE, .val.str = "Free"}}
```

Fix:

I removed `str` from the union and printed `"Free"` straight from the tag.

Correct code:
```c
union {
    int num;
} val;

{"Apple", {PRICE_FREE}}

case PRICE_FREE:
    printf("%-6s", "Free");
    break;
```

---

### 3. I had an unused `#include <string.h>`

Error code:
```c
#include <stdio.h>
#include <string.h>   // never used
```

Fix:

I deleted it.

Correct code:
```c
#include <stdio.h>
```

---

### 4. The "zero tag" bug

Apple had no discount, but it printed `0`. When I skip a field, C fills it with zeros, so the tag became `0`. In my enum, `0` was `PRICE_FIXED`, which made it read as "a fixed price of 0."

Error code:
```c
typedef enum { PRICE_FIXED, PRICE_FREE, PRICE_DISCOUNT } PriceType;
// output: Apple | Free | 0   <- phantom 0
```

Fix:

I put `PRICE_NONE` first in the enum, so an empty price now means "nothing."

Correct code:
```c
typedef enum { PRICE_NONE, PRICE_FREE, PRICE_FIXED, PRICE_DISCOUNT } PriceType;
// output: Apple | Free | -
```

## Changes I made to improve it

### 1. I replaced `if/else` with `switch`

Before:
```c
if (price.type == PRICE_FREE) {
    printf("%-6s", "Free");
} else {
    printf("%-6d", price.val.num);
}
```

After:
```c
switch (price.type) {
    case PRICE_FIXED:
        printf("%-6d", price.val.num);
        break;
    case PRICE_FREE:
        printf("%-6s", "Free");
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
```

---

### 2. I added `PRICE_DISCOUNT`

I added a new enum value and a `float discount` member to the union to hold the percent.

```c
union {
    int num;
    float discount;
} val;

{"Milk", {PRICE_FIXED, .val.num = 200}, {PRICE_DISCOUNT, .val.discount = 5}}
```

---

### 3. I made `PRICE_NONE` print `-`

This makes the empty column easier to read.

```c
case PRICE_NONE:
    printf("%-6s", "-");
    break;
```

## What I learned
- **struct** = many slots, all used at the same time.
- **union** = one shared slot, only one label is used at a time.
- **tag** = the field that says which union label is active.
- **Rule: always check the tag before reading the union.**
- I only add a new union member when the new type actually needs to store something. A type like `PRICE_FREE` needs nothing.
- If two members are the same type (like two `int`s), I still give them separate names so it's clear what each one means.
- Fields I skip in an initializer become 0, so the first enum value should be the "empty/none" one.
- Having a `default:` in a `switch` stops the compiler from warning me about a missing `case`.
- The `-Wextra` "missing initializer" warnings are harmless when I skip fields on purpose.

## Still to do
- `Item` has two `Price` fields (`price_cost` and `price_discount`). That isn't really how a tagged union is meant to work, because one price should be ONE kind.
- Next: use one `Price` per item, and make `PRICE_DISCOUNT` hold both the original price and the percent (a struct inside the union). Then print the final price (200 with 5% off = 190).
- Align the discount column with `%-5.0f%%`.

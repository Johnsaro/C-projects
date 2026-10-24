#include <stdio.h>

int main(void) {
    char name1[30];
    char name2[30];
    char name3[30];
    char name4[30];

    // ==========================================
    // EXPERIMENT 1: scanf() WITHOUT \n
    // ==========================================
    printf("=== TEST 1: scanf() WITHOUT \\n ===\n");
    printf("Enter a single name (e.g., John): ");
    scanf("%29s", name1);

    printf("Name: %s", name1);
    printf(" <-- STUCK SIDE-BY-SIDE BECAUSE SCANF DROPS THE ENTER KEY!");
    printf("\n\n\n");

    // Clean up input buffer for the next tests
    while (getchar() != '\n'); 


    // ==========================================
    // EXPERIMENT 2: scanf() WITH \n
    // ==========================================
    printf("=== TEST 2: scanf() WITH \\n ===\n");
    printf("Enter a single name (e.g., John): ");
    scanf("%29s", name2);

    printf("Name: %s\n", name2); // We manually added \n here
    printf(" <-- Separated cleanly because we forced a new line in printf.");
    printf("\n\n\n");

    while (getchar() != '\n');


    // ==========================================
    // EXPERIMENT 3: fgets() WITHOUT \n
    // ==========================================
    printf("=== TEST 3: fgets() WITHOUT \\n ===\n");
    printf("Enter a full name (e.g., John Doe): ");
    fgets(name3, sizeof(name3), stdin);

    printf("Name: %s", name3); // No \n here!
    printf(" <-- SEPARATED AUTOMATICALLY BECAUSE FGETS SAVED YOUR ENTER KEY!");
    printf("\n\n\n");


    // ==========================================
    // EXPERIMENT 4: fgets() WITH \n
    // ==========================================
    printf("=== TEST 4: fgets() WITH \\n ===\n");
    printf("Enter a full name (e.g., John Doe): ");
    fgets(name4, sizeof(name4), stdin);

    printf("Name: %s\n", name4); // Accidental extra \n
    printf(" <-- DOUBLE GAP ABOVE! The saved Enter key + our printf \\n created an empty row.");
    printf("\n\n");

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Item {
    char* name;
    double price;
};

const struct Item ITEM_TABLE[] = {
    {"Salad", 9.95},
    {"Soup", 4.55},
    {"Sandwich", 13.25},
    {"Pizza", 22.35},
};

int main(int argc, char* argv[]) {
    if (argc != 3) {
        puts("Please provide tax and tip percentages as arguments.");
        return 1;
    }
    srand(time(NULL));

    struct Item item = ITEM_TABLE[rand() % 4];

    printf("%s: $%.2f\n", item.name, item.price);
    double tax = atof(argv[1]) / 100.0 * item.price;
    printf("Tax: $%.2f\n", tax);
    double tip = atof(argv[2]) / 100.0 * (item.price + tax);
    printf("Tip: $%.2f\n", tip);
    printf("----------\nTotal: $%.2f\n", item.price + tax + tip);

    return 0;
}
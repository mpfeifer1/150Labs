#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <math.h>

void get_part_info(double parts[4]);
double num_to_order(double parts[4]);
void place_order(double parts[][4]);

#define MAX 5

int main() {
    double parts[MAX][4]; // Number, stock, cost, minimum to keep stocked
    int i = 0;

    for(i = 0; i < MAX; i++) {
        get_part_info(parts[i]);
    }

    place_order(parts);
    return 0;
}

void get_part_info(double parts[4]) {
    int part_num;
    float cost;
    int quantity;
    int minimum;

    printf("Part number:         ");
    scanf("%d", &part_num);
    printf("Cost:                ");
    scanf("%f", &cost);
    printf("Quantity on hand:    ");
    scanf("%d", &quantity);
    printf("Minimum stock level: ");
    scanf("%d", &minimum);
    printf("\n");

    parts[0] = part_num;
    parts[1] = cost;
    parts[2] = quantity;
    parts[3] = minimum;
}

double num_to_order(double parts[4]) {
    int i = 0;

    double cost = parts[1];
    int partsNeeded = ceil(parts[3] * 1.1) - parts[2];

    if(partsNeeded > 0) {
        printf("%4d %7.2f %9d %8.2f \n", (int)parts[0], cost, (int)partsNeeded, partsNeeded * cost);
        return partsNeeded * cost;
    }

    return 0;
}

void place_order(double parts[][4]) {
    double total = 0;
    int i = 0;

    printf("Parts to order\n");
    printf("Part    Cost    Number    Total\n");

    for(i = 0; i < MAX; i++) {
        total += num_to_order(parts[i]);
    }

    printf("\nTotal order cost: %.2f \n \nGoodbye!\n", total);
}

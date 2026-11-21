#include <stdio.h>

float calculateDiscount(float amount) {
    if (amount >= 5000) return amount * 0.10;
    if (amount >= 3000) return amount * 0.05;
    return 0;
}

float calculateFinalAmount(float amount, float discount) {
    return amount - discount;
}

void displayReceipt(char name[], float amount, float discount, float final) {
    int percent = 0;
    if (amount >= 5000) percent = 10;
    else if (amount >= 3000) percent = 5;

    printf("------ Receipt ------\n");
    printf("Customer Name : %s\n", name);
    printf("Purchase Amount: Tk %.2f\n", amount);
    printf("Discount (%d%%) : Tk %.2f\n", percent, discount);
    printf("Final Payable : Tk %.2f\n", final);
}

int main() {
    char name[50];
    float amount;

    printf("Enter customer name: ");
    scanf(" %[^\n]", name);
    printf("Enter purchase amount: ");
    scanf("%f", &amount);

    if (amount < 0) {
        printf("Invalid amount! Purchase amount cannot be negative.\n");
        return 0;
    }

    float discount = calculateDiscount(amount);
    float final = calculateFinalAmount(amount, discount);
    displayReceipt(name, amount, discount, final);
    return 0;
}

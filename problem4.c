#include <stdio.h>

int checkBalance(int balance, int amount) {
    return balance >= amount;
}

int validateWithdrawal(int amount) {
    return amount > 0 && amount % 500 == 0;
}

int withdrawMoney(int balance, int amount) {
    return balance - amount;
}

void displayTransaction(int success, int amount, int balance) {
    if (success) {
        printf("Transaction Status : Successful\n");
        printf("Amount Withdrawn : Tk %d\n", amount);
    } else {
        printf("Transaction Status : Failed\n");
        printf("Amount Withdrawn : Tk 0\n");
    }
    printf("Remaining Balance : Tk %d\n", balance);
}

int main() {
    int balance, amount;

    printf("Enter account balance: ");
    scanf("%d", &balance);
    printf("Enter withdrawal amount: ");
    scanf("%d", &amount);

    if (validateWithdrawal(amount) && checkBalance(balance, amount)) {
        balance = withdrawMoney(balance, amount);
        displayTransaction(1, amount, balance);
    } else {
        displayTransaction(0, amount, balance);
    }
    return 0;
}

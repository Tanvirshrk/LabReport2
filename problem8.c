#include <stdio.h>

struct Employee {
    int id;
    char name[50];
    float basic, houseRent, medical, gross;
};

int main() {
    struct Employee e[100];
    int n, i;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Employee %d (ID name basic house-rent medical): ", i + 1);
        scanf("%d %s %f %f %f", &e[i].id, e[i].name, &e[i].basic, &e[i].houseRent, &e[i].medical);
        e[i].gross = e[i].basic + e[i].houseRent + e[i].medical;
    }

    printf("\nID\tName\tBasic\t\tHouseRent\tMedical\t\tGross\n");
    for (i = 0; i < n; i++)
        printf("%d\t%s\t%.2f\t%.2f\t%.2f\t%.2f\n",
               e[i].id, e[i].name, e[i].basic, e[i].houseRent, e[i].medical, e[i].gross);
    return 0;
}

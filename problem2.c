#include <stdio.h>

int calculateTotal(int m[]) {
    int i, total = 0;
    for (i = 0; i < 5; i++) total += m[i];
    return total;
}

float calculateAverage(int total) {
    return total / 5.0;
}

void calculateGrade(float avg, char grade[], float *gpa) {
    if (avg >= 80)      { sprintf(grade, "A+"); *gpa = 4.00; }
    else if (avg >= 70) { sprintf(grade, "A");  *gpa = 3.50; }
    else if (avg >= 60) { sprintf(grade, "A-"); *gpa = 3.00; }
    else if (avg >= 50) { sprintf(grade, "B");  *gpa = 2.50; }
    else if (avg >= 40) { sprintf(grade, "C");  *gpa = 2.00; }
    else                { sprintf(grade, "F");  *gpa = 0.00; }
}

void displayResult(char name[], int id, int total, float avg, char grade[], float gpa, char result[]) {
    printf("------ Student Result ------\n");
    printf("Name : %s\n", name);
    printf("ID : %d\n", id);
    printf("Total : %d\n", total);
    printf("Average : %.2f\n", avg);
    printf("Grade : %s\n", grade);
    printf("GPA : %.2f\n", gpa);
    printf("Result : %s\n", result);
}

int main() {
    char name[50], grade[3], result[5];
    int id, marks[5], i, failed = 0;
    float avg, gpa;

    printf("Enter student name: ");
    scanf(" %[^\n]", name);
    printf("Enter student ID: ");
    scanf("%d", &id);
    printf("Enter marks of 5 subjects: ");
    for (i = 0; i < 5; i++) {
        scanf("%d", &marks[i]);
        if (marks[i] < 0 || marks[i] > 100) {
            printf("Invalid mark! Marks must be between 0 and 100.\n");
            return 0;
        }
        if (marks[i] < 40) failed = 1;
    }

    int total = calculateTotal(marks);
    avg = calculateAverage(total);
    calculateGrade(avg, grade, &gpa);

    if (failed || avg < 40) sprintf(result, "Fail");
    else sprintf(result, "Pass");

    displayResult(name, id, total, avg, grade, gpa, result);
    return 0;
}

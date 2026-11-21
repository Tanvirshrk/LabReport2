#include <stdio.h>

union Data {
    int i;
    float f;
    char c;
};

int main() {
    union Data d;

    printf("Size of union Data = %d bytes\n", (int)sizeof(d));

    d.i = 65;
    printf("Assigned integer : i = %d\n", d.i);

    d.f = 3.5;
    printf("Assigned float : f = %f\n", d.f);

    d.c = 'A';
    printf("Assigned char : c = %c\n", d.c);

    /* All members share the same memory, so the last assignment
       overwrote the earlier values. */
    printf("\nAfter assigning char, reading the others:\n");
    printf("i = %d\n", d.i);
    printf("f = %f\n", d.f);

    /* Explanation:
       A union allocates memory equal to its largest member (4 bytes here),
       and all members use that same memory location. Writing to one member
       changes the bytes that the other members read, so only the most
       recently assigned member holds a meaningful value. */
    return 0;
}

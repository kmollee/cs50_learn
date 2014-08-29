/**
 * pointers.c
 *
 * week 4 section
 * fall 2013
 *
 * pointer practice
 */

#include <stdio.h>

int main(void)
{
    // initialize variables and pointers
    int x = 2, y = 8, z = 12;
    int* ptr_x = &x;
    int* ptr_y = &y;
    int* ptr_z = &z;

    // the basics
    printf("value of x is %i\n", x);
    printf("address of x is %p\n", &x);
    printf("value of ptr_x is %p\n", ptr_x);
    printf("address of ptr_x is %p\n", &ptr_x);
    printf("ptr_x points to the value %i\n", *ptr_x);

    printf("\n");

    // multiplication
    printf("z = x * y;\n");
    z = x * y;
    printf("z = %i\n", z);

    printf("\n");

    // multiplication
    printf("x *= y;\n");
    x *= y;
    printf("x = %i\n", x);

    printf("\n");

    // "go to an address"
    printf("y = *ptr_x;\n");
    y = *ptr_x;
    printf("y = %i\n\n", y);

    // "go to an address" and multiplication
    printf("*ptr_x = y * z;\n");
    *ptr_x = x * y;
    printf("*ptr_x = x = %i\n", *ptr_x);

    printf("\n");
    
    // "go to an address" and multiplication
    printf("ptr_x = ptr_y;\n");
    ptr_x = ptr_y;
    printf("x = (*ptr_y) * (*ptr_z);\n");
    x = (*ptr_y) * (*ptr_z);
    printf("x = %i\n", x);
}

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

//propotype
int factorial(int n);

int main(int argc, char const *argv[])
{
    int factorial_number = 0;
    //get var from user
    //get var larger than 0
    do{
        printf("What is the number you want to use in factorial(> 0)? ");
        factorial_number = GetInt();
    } while (factorial_number < 1);

    // declare the result var
    int result = 0;
    //call factorial function and store
    result = factorial(factorial_number);
    //print out result
    printf("factorial(%d) = %d\n", factorial_number, result);
    return 0;
}

int factorial(int n){
    // base line
    // if n is 1 return 1
    if (n == 1)
    {
        return 1;
    }
    // recursive function
    return n * factorial(n-1);
}

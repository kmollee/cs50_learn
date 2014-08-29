/**
 * trainer.c
 *
 * week 4 section
 * fall 2013
 *
 * train some dolphins!
 */

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

// prototype
int* getAge(void);

int main(int argc, char* argv[])
{
    // ensure user entered one and only one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./trainer dolphins\n");
        return 1;
    }
    
    // convert input to an integer
    int dolphins = atoi(argv[1]);
    
    // ensure number of dolphins is greater than 0
    if (dolphins < 1)
    {
        printf("Please enter a positive number of dolphins.\n");
        return 2;
    }
    
    // initalize a new array
    int* dolphin_ages[dolphins];
    
    // get ages
    for (int i = 0; i < dolphins; i++)
    {
        dolphin_ages[i] = getAge();
    }
    
    // print out oldest dolphin's age
    int oldest = 0;
    for (int i = 0; i < dolphins; i++)
    {
        if (*dolphin_ages[i] > oldest)
        {
            oldest = *dolphin_ages[i];
        }
    }
    printf("The oldest dolphin you are training today is %i years old!\n", oldest);
}

/**
 * get the age of a dolphin
 */
int* getAge(void)
{
    // initialze a variable on the heap
    int* age = malloc(sizeof(int));
    
    // get an age
    do
    {
        printf("How old is the dolphin (> 0)? ");
        *age = GetInt();
    }
    while (*age < 1);
    
    // return the age
    return age;
}

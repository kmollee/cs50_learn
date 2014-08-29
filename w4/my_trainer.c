#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

// remember declare function
int* getAge();

int main(int argc, char const *argv[])
{
    // only accept extra one arg
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
    // this is pointer array
    // only accept pointer
    int* dolphin_ages[dolphins];

    // get ages
    for (int i = 0; i < dolphins; i++)
    {
        dolphin_ages[i] = getAge();
    }

    //get the oldest age
    int oldest = 0;
    for (int i = 0; i < dolphins; i++)
    {
        //if  dolphin_ages[i] older than oldest
        if (*dolphin_ages[i] > oldest)
        {
            oldest = *dolphin_ages[i];
        }
    }
    // print out info
    printf("The oldest dolphin you are training today is %i years old!\n", oldest);
    return 0;
}

int* getAge(){
    /*
    this function return int pointer
    */

    // declare int pointer, and malloc the memory for it
    int *age = malloc(sizeof(int));
    //get the age, must be larger than 0
    do{
        printf("How old is the dolphin (> 0)? ");
        *age = GetInt();
    } while (*age < 1);
    return age;
}

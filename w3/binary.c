/**
 * binary.c
 *
 * week 3 section
 * fall 2013
 *
 * iterative binary search implementation
 */

#include <stdbool.h>

bool binary_search(int value, int values[], int n)
{
    // save bounds of list
    int beginning = 0;
    int end = n - 1;

    // while length of list > 0
    while (beginning <= end)
    {
        // look at middle of list
        int middle = (beginning + end) / 2;
        if (values[middle] == value)
        {
            // if number found, return true
            return true;
        }   
        
        // else if middle higher, search left
        else if (values[middle] > value)
        {
            end = middle - 1;
        }
        
        // else if middle lower, search right
        else
        {
            beginning = middle + 1;
        }
    }
    
    // return false
    return false;
}

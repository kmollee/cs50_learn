#include <stdbool.h>

bool my_binary(int value, int values[], int n){
    // value is target
    // values is array
    // n is array length

    int begging = 0;
    int ending = n-1;
    //divide bettwen begging and ending
    int middle = (ending-begging)/2;
    // if ending > begging keep search
    while( ending > begging ){
        //if the one is equal to value return true
        if(values[middle] == value){
            return true;
        }
        // there is not found yet

        // choice the block to search
        // is left side or right side

        // search right side
        else if(middle > value){
            begging = middle + 1;
        }
        // search left side
        else{
            ending = middle - 1;
        }
    }
    // if loop all and not found any match, return false
    return false;
}

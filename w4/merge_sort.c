#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

//prototype
void merge_sort(int n, int data[]);
void merge_sort_r(int left, int right,int data[]);
void print_out_array(int data[], int n);
void merge(int left_start, int left_end, int right_start,int right_end, int data[]);

int main(int argc, char const *argv[])
{
    //sample array, to sort
    int sample[] = {5, 1, 2, 4, 3};

    //call merge sort
    merge_sort(5, sample);

    // print out array
    print_out_array(sample, 5);

    return 0;
}

void merge_sort(int n, int data[]){
    merge_sort_r(0, n, data);
}

void merge_sort_r(int left, int right,int data[]){
    // if size less or equal to 1 return
    if((right - left) <= 1){
        return;
    }
    // determine the left and right size
    int left_start = left;
    int left_end = (right + left) / 2;

    int right_start = left_end;
    int right_end = right;

    // split left and right
    merge_sort_r(left_start, left_end, data);
    merge_sort_r(right_start, right_end, data);
    merge(left_start, left_end, right_start, right_end, data);
}

void merge(int left_start, int left_end, int right_start,int right_end, int data[]){
    // determine the length
    int left_length = left_end - left_start;
    int right_length = right_end - right_start;

    // left and right half tmp list
    int left_half[left_length];
    int right_half[right_length];

    int r = 0;// right_half index
    int L = 0;// left_half index
    int i = 0;// data index

    // copy left_half from data list
    for (i = left_start, L=0; i < left_end; i++, L++)
    {
        left_half[L] = data[i];
    }

    // copy right_half from data list
    for (i = right_start, r=0; i < right_end; i++, r++)
    {
        right_half[r] = data[i];
    }

    // merge left and right half
    for (i = left_start, L=0, r=0; L < left_length && r < right_length; i++)
    {
        // < smaller -> larger
        // > larger -> smaller
        if (left_half[L] < right_half[r])
        {
            data[i] = left_half[L];
            L++;
        }
        else{
            data[i] = right_half[r];
            r++;
        }
    }
    /* Copy over leftovers of whichever temporary list hasn't finished */
    // copy rest left or right half to data list
    for ( ; L < left_length; i++, L++) {
        data[i] = left_half[L];
    }
    for ( ; r < right_length; i++, r++) {
        data[i] = right_half[r];
    }
}

void print_out_array(int data[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", data[i]);
    }
    printf("\n");
}

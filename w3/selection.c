/**
 * selection.c
 *
 * week 3 section
 * fall 2013
 *
 * selection sort implementation
 */

void selection_sort(int values[], int n)
{
    // run the sort n times
    for (int i = 0; i < n; i++)
    {
        // remember the smallest value
        int smallest_index = i;
        
        // make comparisons throughout the rest of the list
        for (int j = i + 1; j < n; j++)
        {
            // find the smallest number
            if (values[j] < values[smallest_index])
            {
                smallest_index = j;
            }
        }
        
        // put the beginning of the list where the smallest number was
        int tmp = values[smallest_index];
        values[smallest_index] = values[i];

        // place it in the beginning of the list
        values[i] = tmp;
    }
}

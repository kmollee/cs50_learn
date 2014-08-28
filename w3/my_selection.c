void my_selection_sort(int values[], int n){
    // values is list
    // n is list length

    for (int i = 0; i < n; i++)
    {
        //small index
        int index = i;
        //loop others
        for (int j = i+1; j < n; j++)
        {
            // if any small than current value[index]
            // index replace
            if (values[j] < values[index]){
                index = j;
            }
        }
        // there index is the smallest position
        // swap current i and index value
        int tmp = values[index];
        values[index] = values[i];
        values[i] = tmp;
    }
}

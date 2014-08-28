void linear_search(int values[], int n, int key){
    // values is list, need to sort
    // n is list length

    // loop through whole list values
    for (int i = 0; i < n; i++)
    {
        //if values[i] is equal to key, return i
        // i is position in list
        if(values[i] == key){
            return i;
        }
    }
    // not match any
    // return -1
    return -1;
}

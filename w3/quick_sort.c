#include <stdio.h>
int a[] = { 1, 2, 8, 7, 9, 5, 6, 4, 3, 66, 77, 33, 22, 11 };

/* 输出数组前n各元素 */
void prt(int n)
{
    int i;
    for (i = 0; i < n; i++)
   {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

void quick_sort (int data[], size_t left, size_t right) {
    size_t p = (left + right) / 2;
    int pivot = data[p];
    size_t i = left,j = right;
    for ( ; i < j;) {
        while (! (i>= p || pivot < data[i])){
            ++i;
        }
        if (i < p) {
            printf("%s i:%d, p:%d\n", "before", i, p);
            prt(14);
            data[p] = data[i];
            printf("%s i:%d, p:%d\n", "after", i, p);
            prt(14);
            p = i;
        }
        while (! (j <= p || data[j] < pivot)){
            --j;
        }
        if (j > p) {
            data[p] = data[j];
            p = j;
        }
    }
    data[p] = pivot;
    if (p - left > 1){
        quick_sort(data, left, p - 1);
    }
    if (right - p > 1){
        quick_sort(data, p + 1, right);
    }
}

int main(void) {
    /* 排序与输出 */
    quick_sort(a, 0, 13);
    prt(14);
    return 0;
}

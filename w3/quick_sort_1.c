void prt(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
   {
        printf("%d\t", a[i]);
    }
    printf("\n");
}
void quick_sort (int *a, int n) {
    if (n < 2)
        return;
    int p = a[n / 2];
    int *l = a;
    int *r = a + n - 1;
    while (l <= r) {
        if (*l < p) {
            l++;
        }
        else if (*r > p) {
            r--;
        }
        else {
            int t = *l;
            *l = *r;
            *r = t;
            l++;
            r--;
        }
    }
    prt(a, n);
    quick_sort(a, r - a + 1);
    quick_sort(l, a + n - l);
}

int main () {
    //int a[] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1};
    int a[] = {1,3,0,2,4};
    int n = sizeof(a) / sizeof(a[0]);
    quick_sort(a, n);
    prt(a, n);
    return 0;
}


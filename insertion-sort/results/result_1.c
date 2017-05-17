// https://github.com/aydenlin/Algorithms-DataStructures/blob/432ef0966f9d0bd07fc4a94a2321d832149cec9a/Algorithms/InsertionSort/insertion_sort.c

void insertion_sort(int *ptr, int total) {
    int i, j, middle;
    for (j = 1; j < total; j++) {
        middle = ptr[j];
        i = j - 1;
        while (i >= 0 && ptr[i] > middle) {
            ptr[i+1] = ptr[i];
            i--;
        }
        ptr[i+1] = middle;
    }
}
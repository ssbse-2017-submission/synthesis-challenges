// https://github.com/zacharya/algo/blob/2dd36b0fb6049ce8f23e06612b482e87d44cfe4a/insertion.c

void insertion_sort(int array[], int n)
{
    int itr, traverse, temp;
    for(itr=1; itr<=(n-1); itr++)
    {
        traverse=itr;
        while(traverse>0 && array[traverse] < array[traverse-1])
        {
            temp=array[traverse];
            array[traverse]=array[traverse-1];
            array[traverse-1]=temp;
            traverse--;
        }
    }
}
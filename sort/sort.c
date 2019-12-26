void BubbleSort(int A[], int len)
{
    int i, j;
    int temp;
    int sortflag = 1;

    for(i = 0; i < len-1 && sortflag; i++)
    {
        sortflag = 0;
        for(j = 0; j <= len-2-i; j++)
        {
            if(A[j] > A[j+1])
            {
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                sortflag = 1;
            }
        }
    }
}

void SelectSort(int A[], int len)
{
    int i, j, min;
    int temp;

    for(i = 0; i < len-1; i++)
    {
        min = i;
        for(j = i+1; j < len; j++)
        {
            if(A[min] < A[j])
            {
                min = j;
            }
        }
        if(i != min)
        {
            temp = A[min];
            A[min] = A[i];
            A[i] = temp;
        }
    }
}

void InsertionSort(int A[], int len)
{
    int i, j;
    int tmp;

    for (i = 1; i < len; i++)
    {
        tmp = A[i];
        for(j=i; j>0 && A[j-1]>tmp; j--)
        {
            A[j] = A[j-1];
        }
        A[j] = tmp;
    }
}

void ShellSort(int A[], int len)
{
    int i, j, increment;
    int tmp;

    for(increment = len/2; increment > 0; increment /= 2)
    {
        for(i = increment; i < len; i++)
        {
            tmp = A[i];
            for (j = i; j >= increment; j -= increment)
            {
                if (A[j-increment] > tmp)
                {
                    A[j] = A[j-increment];
                }
                else
                {
                    break;
                }
            }
            A[j] = tmp;
        }
    }
}

void HeapAdjust(int A[], int s, int m)
{
    int j;
    int temp = A[s];

    for(j = 2*s+1; j <= m; j = j*2+1)
    {
        if(j < m && A[j] < A[j+1])
        {
            j++;
        }
        if(temp > A[j])
        {
            break;
        }
        A[s] = A[j];
        s = j;
    }

    A[s] = temp;
}

void HeapSort(int A[], int len)
{
    int i, temp;

    for(i = len/2-1; i >= 0; i--)
    {
        HeapAdjust(A, i, len-1);
    }

    for(i = len-1; i > 0; i--)
    {
        temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        HeapAdjust(A, 0, i-1);
    }
}

void swap(int A[], int i, int j)
{
    int temp;

    temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int Partition(int A[], int low, int high)
{
    int pivotkey;

    pivotkey = A[low];

    while(low < high)
    {
        while(low < high && A[high] >= pivotkey)
        {
            high--;
        }
        swap(A, low, high);
        while(low < high && A[low] <= pivotkey)
        {
            low++;
        }
        swap(A, low, high);
    }
    return low;
}

void Qsort(int A[], int low, int high)
{
    int pivot;

    if(low < high)
    {
        pivot = Partition(A, low, high);
        Qsort(A, low, pivot-1);
        Qsort(A, pivot+1, high);
    }
}

void QuickSort(int A[], int len)
{
    Qsort(A, 0, len-1);
}
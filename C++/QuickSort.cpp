#include <iostream>

void quickSort(int list[], int start, int end);
int partition(int list[], int start, int end);

int main()
{
    int arr [9] = {3,5,4,1,6,7,9,8,2};
    int length = 9;

    quickSort(arr, 0, length);
    for(int i = 0; i < length; i++)
    {
        std::cout << arr[i];
    }
    return 0;
}

void quickSort(int list[], int start, int end)
{
    // base case
    if (end <= start)
    {
        return;
    }
    int pivot = partition(list, start, end);
    quickSort(list, start, pivot - 1);
    quickSort(list, pivot + 1, end);
}

int partition(int list[], int start, int end)
{
    int pivot = list[end];
    int i = start - 1;
    int temp;
    
    for(int j = start; j <= end - 1; j++)
    {
        if(list[j] < pivot)
        {
            i++;
            temp = list[i];
            list[i] = list[j];
            list[j] = temp;
        }
    }
    i++;
    temp = list[i];
    list[i] = pivot;
    list[end] = temp;
    return i;
}
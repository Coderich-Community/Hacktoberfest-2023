#include<iostream>
using namespace std;

void printArray(int*A, int n){
    for (int i = 0; i < n; i++)
    {
        cout<<A[i]<<" ";
    }
}

void insertionSort(int* A,int n ){
    for (int i = 1; i < n; i++)
    {
        int key = A[i];
        int j = i-1;
        while (j>= 0 && A[j]>key)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}

int main(){
    int A[] = {12,43,9,65,23,11};
    int n = 6;
    printArray(A,n);
    cout<<endl;
    insertionSort(A,n);
    cout<<"After sorting "<<endl;
    printArray(A,n);
    return 0;

}
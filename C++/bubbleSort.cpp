
#include <iostream>
using namespace std;

void printArray(int*A, int n){
    for (int i = 0; i < n; i++)
    {
        cout<<A[i]<<" ";
    }
}

void bubbleSort(int* A, int n){
    int isSorted = 0;               // for making function adaptive if this step is not done still code works 
    for (int i = 0; i < n-1; i++)       // for number of pass
    {
        // cout<<("Working on pass number %d\n",i+1);
        cout<<"Working on pass no "<<i+1<<endl;
        isSorted = 1;
        for (int j = 0; j < n-1-i; j++)         // for comparison in each pass
        {
            if (A[j]>A[j+1]){
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                isSorted = 0;
            }
        }
        if(isSorted){
            return ;
        }
        
    }
    
}
int main(){
    int A[] = {12,3,45,54,23,21};
    // int A[] = {1,5,6,9,12,34};  // it takes only one pass so fucntion is adaptive 
    int n = 6;          // to give size of A[]
    bubbleSort(A,n);    //function to sort array
    printArray(A,n);    // to print array
    cout<<endl;
    return 0;
}
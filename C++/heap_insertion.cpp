#include <iostream>
using namespace std;

class heap
{
public:
    int arr[100];
    int size ;
    heap(){
        arr[0] = -1;
        size = 0;
    }
    
    void insertion(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;
        int parent;
        while (index > 1)
        {
            parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }

    void print(){
        for (int i = 0; i <= size; i++)
        {
            cout<<arr[i]<<" ";
        }
        
    }

    
};

int main()
{
    heap h;
    h.insertion(10);
    h.insertion(50);
    h.insertion(25);
    h.insertion(21);
    h.insertion(40);

    h.print();
    return 0;
}
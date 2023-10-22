#include <iostream>
#include <vector>

using namespace std;

void sortBinaryArray(vector<int>& arr) {
    int countZeros = 0;

    // Count the number of 0s
    for (int num : arr) {
        if (num == 0) {
            countZeros++;
        }
    }

    // Fill the array with 0s and 1s
    for (int i = 0; i < countZeros; i++) {
        arr[i] = 0; // Fill the first 'countZeros' elements with 0s
    }
    for (int i = countZeros; i < arr.size(); i++) {
        arr[i] = 1; // Fill the remaining elements with 1s
    }
}

int main() {
    vector<int> binaryArray = {1, 0, 1, 0, 1, 1, 0, 0};
    
    cout << "Original Binary Array: ";
    for (int num : binaryArray) {
        cout << num << " ";
    }
    cout << endl;

    sortBinaryArray(binaryArray);

    cout << "Sorted Binary Array: ";
    for (int num : binaryArray) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

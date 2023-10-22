#include <iostream>
#include <vector>

using namespace std;

// Function to sort an array of 0s, 1s, and 2s in a single pass.
void sortColors(vector<int>& nums) {
    int low = 0; // Pointer for 0s
    int mid = 0; // Pointer for 1s
    int high = nums.size() - 1; // Pointer for 2s

    while (mid <= high) {
        if (nums[mid] == 0) {
            // Swap 0 to the left (low)
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        } else if (nums[mid] == 1) {
            // No action needed for 1
            mid++;
        } else {
            // Swap 2 to the right (high)
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main() {
    vector<int> colors = {2, 0, 1, 2, 1, 0, 1};

    cout << "Original Array: ";
    for (int num : colors) {
        cout << num << " ";
    }
    cout << endl;

    sortColors(colors);

    cout << "Sorted Array: ";
    for (int num : colors) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

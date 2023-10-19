#include <iostream>
#include <vector>

// Binary search function
int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // If the target is found, return its index
        if (arr[mid] == target) {
            return mid;
        }

        // If the target is in the left half, update the 'right' pointer
        if (arr[mid] > target) {
            right = mid - 1;
        }

        // If the target is in the right half, update the 'left' pointer
        else {
            left = mid + 1;
        }
    }

    // Return -1 if the target is not found in the array
    return -1;
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 6;

    int result = binarySearch(arr, target);

    if (result != -1) {
        std::cout << "Element " << target << " found at index " << result << std::endl;
    } else {
        std::cout << "Element " << target << " not found in the array." << std::endl;
    }

    return 0;
}

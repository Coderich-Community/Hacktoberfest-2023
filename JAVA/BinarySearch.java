public class BinarySearch {
//Recursive binary search
    public static int binarySearch(int[] arr, int target) {
        return binarySearch(arr, target, 0, arr.length - 1);
    }

   // Helper function for recursive binary search
    private static int binarySearch(int[] arr, int target, int left, int right) {
        if (left > right) {
            return -1; // Target not found
        }

        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Target found at index 'mid'
        } else if (arr[mid] < target) {
            return binarySearch(arr, target, mid + 1, right); // Search the right half
        } else {
            return binarySearch(arr, target, left, mid - 1); // Search the left half
        }
    }

   // Iterative binary search
    public static int binarySearchIterative(int[] arr, int target) {
        int left = 0;
        int right = arr.length - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target) {
                return mid;  // Target found at index 'mid'
            } else if (arr[mid] < target) {
                left = mid + 1; // Search the right half
            } else {
                right = mid - 1; // Search the left half
            }
        }

        return -1; // Target not found
    }

    public static void main(String[] args) {
        int[] sortedArray = {1, 3, 5, 7, 9, 11, 13, 15, 17};
        int target = 9;

        int result = binarySearch(sortedArray, target);
        if (result != -1) {
            System.out.println("Target " + target + " found at index " + result);
        } else {
            System.out.println("Target " + target + " not found in the array.");
        }

        int resultIterative = binarySearchIterative(sortedArray, target);
        if (resultIterative != -1) {
            System.out.println("Iterative Binary Search: Target " + target + " found at index " + resultIterative);
        } else {
            System.out.println("Iterative Binary Search: Target " + target + " not found in the array.");
        }
    }
}

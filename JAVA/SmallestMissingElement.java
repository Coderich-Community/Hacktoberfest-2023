public class SmallestMissingElement {
    public static void main(String[] args) {
        int[] arr = {0, 1, 2, 3, 4, 6, 7, 8};
        int n = arr.length;

        System.out.println("The smallest missing element is: " + findSmallestMissing(arr, 0, n - 1));
    }

    public static int findSmallestMissing(int[] arr, int start, int end) {
        if (start > end) {
            return start;
        }

        int mid = start + (end - start) / 2;
      
        if (arr[mid] == mid) {
            return findSmallestMissing(arr, mid + 1, end);
        } else {
            // Else, it's on the left side.
            return findSmallestMissing(arr, start, mid - 1);
        }
    }
}

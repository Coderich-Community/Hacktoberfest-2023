public class BInarySearch {
    

    public static int binarySearch(int[] nums , int num){
        //Here the nums is the array in which we are trying to finding num number  , if the number is found we will return the index else we will just return -1

        if(nums.length == 0) return -1;

        int low = 0;
        int high = nums.length - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[mid] == num){
                return mid;
            }

            else if(nums[mid] > num){
                //This means the number we are searching for is smaller then the mid element , we have to reduce the search space to the lower end 

                high = mid - 1;
            }

            else{
                //The number num is greater than the mid element hence reduce the search space to larger end 

                low = mid + 1;
            }

        }

        return -1;

    }
    public static void main(String[] args) {
        
        int[] nums = {1,2,3,4,5};

        int num = 5;

        System.out.println("The element is at index " + binarySearch(nums, num));
    }
}

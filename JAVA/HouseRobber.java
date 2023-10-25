
import java.util.Arrays;

public class HouseRobber {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
     int[] arr= {2,7,9,3,1};
//      int[] dp=new int[arr.length];
//
//      Arrays.fill(dp, -1);
     // System.out.println(house(0,arr,dp));
    //  System.out.println(houseTD(arr.length-1,arr,dp));
       System.out.println(houseBU(arr));
       System.out.println(space(arr));
	}
     public static int house(int ind,int[] arr,int[] dp)
	    {
    	 if(ind>=arr.length)
	        {
          return 0;
	        }

	    	if(dp[ind]!=-1)
	    		return dp[ind];
	       	        int rob=arr[ind]+house(ind+2,arr,dp);
	        int dntrob=house(ind+1,arr,dp);
	        dp[ind]= Math.max(rob,dntrob);
	        return dp[ind];
	    }
     public static int houseTD(int ind, int[] arr, int[] dp)
     {
    	     if(ind<0)
    		 return 0;
    	 if(dp[ind]!=-1)
    		 return dp[ind];
    	     int rob=arr[ind]+house(ind-2,arr,dp);
	        int dntrob=house(ind-1,arr,dp);
	        dp[ind]= Math.max(rob,dntrob);
	        return dp[ind];
     }
     public static int houseBU(int[] arr)
     {
    	 int[] dp=new int[arr.length];
    	 dp[0]=arr[0];
    	 dp[1]=Math.max(arr[0], arr[1]);
    	 for(int i=2;i<arr.length;i++)
    	 {
    	    int rob=arr[i]+dp[i-2];
	        int dntrob=dp[i-1];
	        dp[i]= Math.max(rob,dntrob);
     }
    	 return dp[arr.length-1];
 }
     public static int space(int[] arr)
     {
    	 int prev2=arr[0];
    	 int prev=Math.max(arr[0],arr[1]);
    	 for(int i=2;i<arr.length;i++)
    	 {
    		 int rob=arr[i]+prev2;
    		 int dntrob=prev;
    		 int curr=Math.max(rob, dntrob);
    		 prev2=prev;
    		 prev=curr;
    	 }
    	 return prev;
     }
}


class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        // prev greatest element array
        int prev[n];
        prev[0] = -1;
        int max = height[0];
        for(int i = 0;i<n;i++){
            prev[i] = max;
            if(max<height[i]) max = height[i];
        }

        // next greatest element array -> prev as next

        //int next[n];

        prev[n-1] = -1;
         max = height[n-1];
        for(int i = n-1;i>0;i--){
            if(max<prev[i]) prev[i] = max;
            if(max<height[i]) max = height[i];
        }

    //     //minimum array -> prev as minimum
    //    // int mini[n];
    //     for(int i=0;i<n;i++){
    //      prev[i] = min(prev[i],next[i]);


    //     }
        // calculating water
        int water = 0;
        for(int i = 1;i<n-1;i++){
          if(height[i]<prev[i]){
              water += (prev[i]-height[i]);
          }  
        }
        return water;

    }
};

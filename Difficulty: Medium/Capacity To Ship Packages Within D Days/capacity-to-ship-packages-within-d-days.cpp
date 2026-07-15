class Solution {
  public:
    long long leastWeightCapacity(vector<int>& arr, int d) {
        // code here
        long long N = arr.size();
    
        
        long long start=0,end=0,mid,ans;
        for(int i=0 ; i<N ; i++)
        {
            if(start<arr[i])
            start=arr[i];
            end+=arr[i];
        }
        
        while(start<=end)
        {
            mid=start+(end-start)/2;
            int pages=0,count=1;
            for(int i=0;i<N;i++)
            {
               pages+=arr[i];
               if(pages>mid)
               {
                   count++;
                   pages=arr[i];
               }
            }
            if(count<=d)
            {
                ans=mid;
                end=mid-1;
            }
            else
            start=mid+1;
        }
        return ans;
    }
    
};
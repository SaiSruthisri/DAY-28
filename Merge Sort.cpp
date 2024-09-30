class Solution {
public:
   void divide(vector<int> &arr , int low , int high)
   {
    if(low==high)
    {
        return;
    }
     int mid = (low+high)/2;
     divide(arr , low , mid);
     divide(arr , mid+1 , high);
     merge(arr , low , mid , high);
   }
   void merge(vector<int> &arr , int low , int mid , int high)
   {
     vector<int>temp;
     int left=low;
     int right=mid+1;
     while(left<=mid && right<=high )
     {
        if(arr[left]<=arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
     }
     while(left<=mid)
     {
        temp.push_back(arr[left]);
        left++;
     }
      while(right<=high)
     {
        temp.push_back(arr[right]);
        right++;
     }
     for(int i=low ; i<=high ; i++)
     {
        arr[i]=temp[i-low];
     }
   }
    vector<int> sortArray(vector<int>& arr) {
        int n = arr.size();
        divide(arr , 0 , n-1);

        return arr;
    }
};

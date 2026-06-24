class Solution {
private:
    int count = 0;

    void merge(vector<int>& arr, int low, int mid, int high){
        vector<int> temp;

        int left = low;
        int right  = mid + 1;

        while (left <= mid && right <= high){
            if (arr[left] > arr[right]){
                count += mid - left + 1;
                temp.push_back(arr[right]);
                right++;
            } else {
                temp.push_back(arr[left]);
                left++;
            }
        }

        while (left <= mid){
            temp.push_back(arr[left]);
            left++;
        }

        while (right <= high){
            temp.push_back(arr[right]);
            right++;
        }
    }

    void mergesort(vector<int>& arr, int low, int high){
        if (low >= high) return;

        int mid = (low + high) / 2;

        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }

public:
   long long int numberOfInversions(vector<int> nums) {
        int n = nums.size(); 
        mergesort(nums, 0, n - 1);
        return count;
    }
};
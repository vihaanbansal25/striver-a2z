class Solution {
private:
    int count = 0;

    void merge(vector<int>& arr, int low, int mid, int high){
        vector<int> temp;

        int left = low;
        int right  = mid + 1;

        // for (int i = low; i <= mid; i++){
        //     while (right <= high && arr[i] > 2 * arr[right]){
        //         right++;
        //     }
        //     count += right - mid + 1;
        // }

        while (left <= mid && right <= high){
            if (arr[left] > arr[right]){
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

        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    void mergesort(vector<int>& arr, int low, int high){
        if (low >= high) return;

        int mid = (low + high) / 2;

        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);

        int left = low, right = mid + 1;
        while (left <= mid && right <= high){
            if (arr[left] > 2LL * arr[right]){
                count += mid - left + 1;
                right++;
            } else {
                left++;
            }
        }

        merge(arr, low, mid, high);
    }
public:
    int reversePairs(vector<int>& nums) {
        mergesort(nums, 0, nums.size() - 1);
        return count;
    }
};
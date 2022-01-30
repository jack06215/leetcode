class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        merge_sort(nums);
        return nums;
    }
private:
    void merge_sort(vector<int>& nums) {
        _mergeSort(nums, 0, nums.size() - 1);
    }

    void quick_sort(vector<int>& nums) {
        _quickSort(nums, 0, nums.size() - 1);
    }

    void _mergeSort(vector<int>& array, int left, int right) {
        if (left < right) {                             // 表示目前的範圍是有效的
            int mid = left + (right - left) / 2;        // mid即是將array對半分的index
            _mergeSort(array, left, mid);               // 繼續切割前半段subarray
            _mergeSort(array, mid + 1, right);          // 繼續切割後半段subarray
            merge(array, left, mid, right);             // 將兩個subarray做比較, 並合併出排序後的array
        }
    }

    void _quickSort(vector<int>& array, int left, int right) {
        if (left < right) {
            int pivot = partition(array, left, right);
            _quickSort(array, left, pivot - 1);
            _quickSort(array, pivot + 1, right);
        }
    }

    void merge(vector<int>& array, int front, int mid, int end) {
        vector<int> left_arr(begin(array) + front, begin(array) + mid + 1);
        vector<int> right_arr(begin(array) + mid + 1, begin(array) + end + 1);

        left_arr.insert(left_arr.end(), numeric_limits<int>::max());
        right_arr.insert(right_arr.end(), numeric_limits<int>::max());

        int li = 0;
        int ri = 0;
        for (int i = front; i <= end; i++) {
            if (left_arr[li] <= right_arr[ri]) {
                array[i] = left_arr[li];
                li++;
            }
            else {
                array[i] = right_arr[ri];
                ri++;
            }
        }
    }

    int partition(vector<int>& array, int left, int right) {
        int pivot = array[right];
        int i = left - 1;
        for (int j = left; j < right; j++) {
            if (array[j] < pivot) {
                i++;
                swap(array[i], array[j]);
            }
        }
        i++;
        swap(array[i], array[right]);
        return i;
    }
};
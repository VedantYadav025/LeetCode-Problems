class Solution {
private:
    bool is_overlapping(const vector<int>& arr1, const vector<int>& arr2){
        // O(1)
        return (arr2[0] >= arr1[0] && arr2[0] <= arr1[1]) || (arr2[1] >= arr1[0] && arr2[1] <= arr1[1]);
    }

    vector<int> merge_two_overlapping_arrays(const vector<int>& arr1, const vector<int>& arr2){
        // O(1) --> since both arrays will always be of size 2
        vector<int> merged_array;
        int first_element = min(arr1[0], arr2[0]);
        int second_element = max(arr1[1], arr2[1]);
        merged_array.push_back(first_element);
        merged_array.push_back(second_element);
        return merged_array;
    }

public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged_intervals;
        int size = intervals.size();
        if (size == 1){
            return intervals;
        }
        int i = 1;
        vector<int> helper = intervals[0];
        while (i < size){
            if (is_overlapping(helper, intervals[i])){
               helper = merge_two_overlapping_arrays(helper, intervals[i]);
            }
            else{
                merged_intervals.push_back(helper);
                helper = intervals[i];
            }
            if (i == size - 1) merged_intervals.push_back(helper);
            i++;
        }
        return merged_intervals;
    }
};

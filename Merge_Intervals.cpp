class Solution {
private:
    bool is_overlapping(vector<int>& arr1, vector<int>& arr2){
        // O(1)
        int x1 = arr1[0];
        int x2 = arr1[1];
        int y1 = arr2[0];
        int y2 = arr2[1];
        if ((y1 >= x1 && y1 <= x2) || (y2 >= x1 && y2 <= x2) || (x1 >= y1 && x1 <= y2) || (x2 >= y1 && x2 <= y2))
            return true;
        else
            return false;
    }

    vector<int> merge_two_overlapping_arrays(vector<int>& arr1, vector<int>& arr2){
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
        int i = 0;
        vector<int> helper = intervals[0];
        while (i < size - 1){
            if (!(is_overlapping(helper, intervals[i + 1]))){
                merged_intervals.push_back(helper);
                helper = intervals[i + 1];
                if (i + 1 == size - 1){
                    merged_intervals.push_back(intervals[i + 1]);
                }
            }
            else{
                helper = merge_two_overlapping_arrays(helper, intervals[i + 1]);
                if (i + 1 == size - 1){
                    merged_intervals.push_back(helper);
                }
            }
            i++;
        }
        return merged_intervals;
    }
};

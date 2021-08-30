// https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/
class Solution {
public:
    static bool cmp(const string &a,const string&b){
        if(a.size()<b.size()){
            return false;
        }else if(a.size()==b.size()){
            return a>b;
        }
        return true;
    }
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(),nums.end(),cmp);
        return nums[k-1];
    }
};

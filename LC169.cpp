class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }

        int num=INT_MIN, freq=INT_MIN;
        for(auto it:m){
            if(freq<it.second){
                freq= it.second;
                num= it.first;
            }
        }
        return num;
    }
};
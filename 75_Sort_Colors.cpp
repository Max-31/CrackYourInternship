class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int>ans, v(3, 0);

        for(int i=0; i<nums.size(); i++){
            v[nums[i]]++;
        }

        for(int i=0; i<=2; i++){
            int times= v[i];
            while(times--){
                ans.push_back(i);
            }
        }
        nums.clear();
        nums=ans;

        // return ans;
    }
};
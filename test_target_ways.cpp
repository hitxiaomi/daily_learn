//
// Created by xiaomi on 7/20/19.
//

#include<vector>
using namespace std;
class Solution {
private:
    int count_=0;//结果个数
    int size_of_nums_;
    int DFS(const vector<int > &nums,int i,int s){
        //终止条件是
        if(i>size_of_nums_-1){
            //数组遍历完
            if(s==0)
                count_++;
            return true;

        }

        DFS(nums,i+1,s+nums[i]);
        DFS(nums,i+1,s-nums[i]);

        return true;

    }


public:
    int findTargetSumWays(vector<int>& nums, int S) {
        size_of_nums_=nums.size();


        DFS(nums,0,S);//

        return count_;

    }
};

int main(){

    Solution solution;
    vector<int> nums={2,107,109,113,127,131,137,3,2,3,5,7,11,13,17,19,23,29,47,53};
    solution.findTargetSumWays(nums,2147483647);
}
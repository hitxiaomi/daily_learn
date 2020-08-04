//
// Created by xiaomi on 7/14/19.
//

#include <vector>
#include <math.h>
#include <queue>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        //因为题目要求完全平方数的个数最少，所以考虑采用广度优先算法去处理
        //定义返回值

        int res=0;
        //找到所有可能的完全平方数
        int max_i=static_cast<int>(sqrt(n));
        vector<int> possible_nums;
        for(int i=max_i;i>0;i--){
            possible_nums.push_back(i*i);
        }
        //定义广度优先需要的队列
        queue<int> queue_int;
        //按照题意不需要定义visited

        //将n定义为根节点
        queue_int.push(n);

        while (!queue_int.empty()/* condition */)
        {
            int queue_size=queue_int.size();

            //处理第res层数据
            for(int i=0;i<queue_size;i++){
                //取出第一个元素
                int element_in_queue=queue_int.front();


                //首先判断是否找到目标
                if(element_in_queue==0) {
                    return res;
                }
                //将该元素的所有邻居加入队列
                for(int j=0;j<possible_nums.size();j++){
                    int temp_num=element_in_queue-possible_nums[j];
                    if((temp_num>=0)){
                        queue_int.push(temp_num);

                    }
                }

                queue_int.pop();




            }
            res++;


            /* code */
        }
        return -1;

    }
};

int main(){


    Solution solution;
    int res=solution.numSquares(7927);
    return  0;

}
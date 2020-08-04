//
// Created by xiaomi on 7/13/19.
//

#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
#include <iostream>
using namespace std;



class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int res=0; //结果
        const string begin_str="0000";
        queue<string> queue_str; //定义一个队列，用于广度优先搜索
        unordered_set<string > visited;//定义unordered set 用于记录是否元素是否已经被访问
        unordered_set<string > deadends_set;  //死锁 方便查看状态是否满足
        for(int i=0;i<deadends.size();i++){
            deadends_set.insert(deadends[i]);
        }
        if(deadends_set.find(begin_str)==deadends_set.end()){ //初始值不在deadends中才可以加入到队列中
            queue_str.push(begin_str);
            visited.insert(begin_str);

        }


        while (!queue_str.empty()/* condition */)
        {

            int queue_size=queue_str.size();
            for(int i=0;i<queue_size;i++) {

                string queue_front_str = queue_str.front();  //访问队列第一个元素
                if (queue_front_str.compare(target) == 0) {    //跟目标做比较
                    return res;
                }

                //将其关联的所有状态加入到队列中
                for (int i = 0; i < 4; i++) {//四个字符，每次更改一个字符
                    string tem_str1 = queue_front_str;  //用于增加
                    if (tem_str1[i] == '9') {
                        tem_str1[i] = '0';
                    } else {
                        tem_str1[i] += 1;
                    }

                    if (deadends_set.find(tem_str1) == deadends_set.end() && visited.find(tem_str1) == visited.end()) {
                        queue_str.push(tem_str1);
                        visited.insert(tem_str1);
                    }

                    string tem_str2 = queue_front_str;  //用于减小
                    if (tem_str2[i] == '0') {
                        tem_str2[i] = '9';
                    } else {
                        tem_str2[i] -= 1;
                    }

                    if (deadends_set.find(tem_str2) == deadends_set.end() && visited.find(tem_str2) == visited.end()) {
                        queue_str.push(tem_str2);
                        visited.insert(tem_str2);
                    }


                }

                queue_str.pop();

            }



            res++;







            /* code */
        }

        return -1;


    }
};

int main(int argc,char** argv){
    Solution solution;

    vector<string> vec_str={"0201","0101","0102","1212","2002"};
    string target_str("0202");
    std::cout<<solution.openLock(vec_str,target_str);


}
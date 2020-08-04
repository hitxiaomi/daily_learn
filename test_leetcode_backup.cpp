/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 *
 * https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/description/
 *
 * algorithms
 * Medium (44.99%)
 * Likes:    60
 * Dislikes: 0
 * Total Accepted:    11K
 * Total Submissions: 24.4K
 * Testcase Example:  '["2","1","+","3","*"]'
 *
 * 根据逆波兰表示法，求表达式的值。
 *
 * 有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
 *
 * 说明：
 *
 *
 * 整数除法只保留整数部分。
 * 给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
 *
 *
 * 示例 1：
 *
 * 输入: ["2", "1", "+", "3", "*"]
 * 输出: 9
 * 解释: ((2 + 1) * 3) = 9
 *
 *
 * 示例 2：
 *
 * 输入: ["4", "13", "5", "/", "+"]
 * 输出: 6
 * 解释: (4 + (13 / 5)) = 6
 *
 *
 * 示例 3：
 *
 * 输入: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
 * 输出: 22
 * 解释:
 * ⁠ ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
 * = ((10 * (6 / (12 * -11))) + 17) + 5
 * = ((10 * (6 / -132)) + 17) + 5
 * = ((10 * 0) + 17) + 5
 * = (0 + 17) + 5
 * = 17 + 5
 * = 22
 *
 */
//标准的堆栈解决问题
#include <vector>
#include <string>
#include <stack>
#include <iostream>
using namespace std;
class Solution {
private:
    bool DFS(const int x,const int y, const int rows, const int colums,const vector<vector<char> >& grid,vector< vector<bool> >  &visited){
        // if(x<0||x>rows-1||y<0||y>colums-1)
        //     return false;
        // if(grid[x][y]==0)
        //     return false;
        //终止条件？？  //没有终止条件
        int a[4]={-1,1,0,0},b[4]={0,0,-1,1};

        for(int i=0;i<4;i++){  //判断四个邻居
            int cur_x=x+a[i];
            int cur_y=y+b[i];
            if(cur_x<0||cur_x>rows-1||cur_y<0||cur_y>colums-1)
                continue; //数据越界，这个点就不需要考虑了
            if( grid[cur_x][cur_y]== '1' && visited[cur_x][cur_y]==false){ //只有这个条件满足才会进行递归
                visited[cur_x][cur_y]=true;
                DFS(cur_x,cur_y,rows,colums,grid,visited);
            }

        }
        //尾递归？？
        return false;
    }

public:
    int evalRPN(vector<string>& tokens) {
        //定义一个栈
        stack<int> st;//保存string 对应的int数值
        for(auto const & token:tokens){
            if(token=="+"){
                int b=st.top();st.pop();
                int a=st.top();st.pop();
                st.push(a+b);

            }
            else if(token=="-"){
                int b=st.top();st.pop();
                int a=st.top();st.pop();
                st.push(a-b);

            }
            else if(token=="*"){
                int b=st.top();st.pop();
                int a=st.top();st.pop();
                st.push(a*b);

            }
            else if(token=="/"){
                int b=st.top();st.pop();
                int a=st.top();st.pop();
                st.push(a/b);
            }
            else st.push(stoi(token));
        }


        return st.top();

    }
    int numIslands(vector<vector<char> >& grid){

        //判断grid是否满足要求
        if(grid.empty()) return 0;
        if(grid[0].empty()) return 0;
        int rows=grid.size();
        int colums=grid[0].size();

        int num_is_lands=0;

        //定义visited
        vector< vector<bool> > visited(rows,vector<bool>(colums,false));


        //遍历grid
        for(int i=0;i<rows;i++)
            for(int j=0;j<colums;j++){
                if(grid[i][j]=='0' || visited[i][j]==true) //如果当前值为0或者已经访问过 直接跳过
                    continue;
                num_is_lands++;
                visited[i][j]=true;
                DFS(i,j,rows,colums,grid,visited);  //对当前点进行深度搜索，找到所有相连的所有岛屿
            }

        return num_is_lands;
    }
    vector<int> plusOne(vector<int>& digits) {
        int carry=1;//进位
        int size_of_digits=digits.size();

        for (int i=size_of_digits-1;i>-1;i--){
            int tem_num=digits[i]+carry;  //
            digits[i]=tem_num%10;
            carry=tem_num/10;

            if(!carry) break;

        }
        if(carry)
            digits.insert(digits.begin(),carry);

        return digits;

    }

    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int colums=matrix[0].size();
        int size_of_result=rows*colums;

        vector<int > result(size_of_result,0);
        int dir[2][2]={{-1,1},{1,-1}};
        int r=0,c=0,k=0;
        for(int i=0;i<size_of_result;i++){
            result[i]=matrix[r][c];

            int tem_r=r+dir[k][0],tem_c=c+dir[k][1];
            if(tem_r>=0&&tem_r<rows && tem_c>=0&&tem_c<colums){
                r=tem_r;
                c=tem_c;
            }
            else {
                k=1-k;
                if(k==1){
                    if(c<colums-1){
                        r=r;
                        c=c+1;
                    }
                    else {
                        c=c;
                        r=r+1;
                    }

                }
                else {
                    if(r<rows-1){
                        c=c;
                        r=r+1;
                    }
                    else {
                        r=r;
                        c=c+1;
                    }


                }



            }


        }
        return result;



    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()||matrix[0].empty())
            return vector<int >();
        int rows=matrix.size(),colums=matrix[0].size();
        int r=0,c=0,k=0;
        int min_row=0,max_row=rows-1;
        int min_colum=0,max_colum=colums-1;
        int size_result=rows*colums;
        vector<int > result(size_result,0);
        for(int i=0;i<size_result;i++){
            result[i]=matrix[r][c];
            switch (k)
            {
                case 0:{
                    int tem_c=c+1;
                    if(tem_c<=max_colum)
                        c=tem_c;
                    else {
                        c=c;
                        r=r+1;
                        k=1;
                        min_row++;

                    }
                    break;
                }
                case 1:{
                    int tem_r=r+1;
                    if(tem_r<=max_row)
                        r=tem_r;
                    else {
                        r=r;
                        c=c-1;
                        k=2;
                        max_colum--;
                    }

                    break;
                }
                case 2:{
                    int tem_c=c-1;
                    if(tem_c>=min_colum){
                        c=tem_c;

                    }
                    else {
                        c=c;
                        r=r-1;
                        k=3;
                        max_row--;
                    }
                    break;



                }
                case 3:{
                    int tem_r=r-1;
                    if(tem_r>=min_row)
                        r=tem_r;
                    else{
                        r=r;
                        c=c+1;
                        k=0;
                        min_colum++;


                    }
                    break;
                }


                default:
                    break;
            }


        }
        return result;

    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > result(numRows, vector<int>());
        if (numRows == 0)
            return result;

        result[0].push_back(1);

        for (int i = 1; i < numRows; i++) {
            result[i].push_back(1);
            int size_last_row = result[i - 1].size();
            for (int j = 1; j < size_last_row; j++) {
                result[i].push_back(result[i - 1][j] + result[i - 1][j - 1]);

            }
            result[i].push_back(1);

        }

        return result;


    }

    string addBinary(string a, string b) {
        int a_size=a.size();
        int b_size=b.size();
        string res;
        if(a_size>b_size)
            res.resize(a_size);
        else
            res.resize(b_size);
        int i=a_size-1,j=b_size-1,k=res.size()-1;
        int carried=0;
        while (i>=0&&j>=0){
            int num_sum= a[i]-'0'+b[j]-'0'+carried;
            res[k]=(num_sum%2) +'0';
            carried =num_sum/2;
            i--;
            j--;
            k--;

        }
        if(i<0&&j>=0){
            while (j>=0){

                int num_sum= b[j]-'0'+carried;
                res[k]=(num_sum%2) +'0';
                carried =num_sum/2;
                j--;
                k--;

            }
        }
        else if(j<0 &&i>=0){
            while (i>=0){
                int num_sum= a[i]-'0'+carried;
                res[k]=(num_sum%2) +'0';
                carried =num_sum/2;
                i--;
                k--;
            }

        }

        if(carried==1){
            res.insert(0,"1");
        }

        return res;

    }
};

int main(int argc,char** argv){

    Solution solution;
    string res=solution.addBinary("11111","1111");




//    vector <vector<int > > res= solution.generate(10);
//    for (int i=0;i<res.size();i++){
//        for (int j=0;j<res[i].size();j++)
//        {
//        std::cout<< res[i][j]<< "  ";
//        }
//        std::cout<<endl;
//    }



    return  0;





}


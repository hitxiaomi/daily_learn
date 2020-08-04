//
// Created by xiaomi on 7/13/19.
//
#include <iostream>
#include <queue>


#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        if(s.empty()){
            return true;

        }
        int size_string=s.size();
        stack<char> stack_char;
        for(int i=0;i<size_string;i++){
            //step 1  判断当前字符 是否为 ‘（’ ‘【’  ‘’
            if(s[i]=='(' || s[i]=='['|| s[i]=='{'){
                stack_char.push(s[i]);
            }
            else { //为右括号
                if(stack_char.empty())//首先栈中必须是有元素的
                    return false;
                switch ( s[i] )
                {
                    case  ')'/* constant-expression */:
                        if(stack_char.top() != '(' ) {/* code */
                            return false;
                        }
                        else{
                            stack_char.pop();
                        }
                        break;
                    case  ']'/* constant-expression */:
                        if(stack_char.top() != '[' ) {/* code */
                            return false;
                        }
                        else{
                            stack_char.pop();
                        }
                        break;


                    case  '}'/* constant-expression */:
                        if(stack_char.top() != '{' ) {/* code */
                            return false;
                        }
                        else{
                            stack_char.pop();
                        }

                        break;


                    default:
                        break;
                }

            }

        }
        if(stack_char.empty())
            return true;
        else
            return false;




    }
};
int main(int argc ,char** argv){
Solution solution;
solution.isValid("()");

    return 0;






}

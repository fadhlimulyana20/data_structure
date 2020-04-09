#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <list>
using namespace std;

int pop(list<int> num){
    int temp = num.back();
    num.pop_back();
    return temp;
}

int main() {
    string operand;
    getline(cin, operand);
    list<int> num;
    const char* theval;
    string num_temp;

    for (int i = 0; i < operand.size(); i++)
    {
        if(isdigit(operand[i])){
            string sym(1, operand[i]);
            theval = sym.c_str();
            num_temp.append(theval);
            if(isspace(operand[i+1])){
                num.push_back(stoi(num_temp));
                num_temp.clear();
            }
        }else if(operand[i] == '+' || operand[i] == '-'){
            int left, right;
            if(operand[i] == '+'){
                right = num.back();
                num.pop_back();
                left = num.back();
                num.pop_back();
                // cout << "left, right" << left << " " << right << endl;
                num.push_back(right+left);
                // for (int i = 0; i < num.size(); i++)
                // {
                //     cout << num[i] << " ";
                // }
                // cout << endl;
            }else if(operand[i] == '-'){
                right = num.back();
                num.pop_back();
                left = num.back();
                num.pop_back();
                // cout << "left, right" << left << " " << right << endl;
                num.push_back(left-right);
                // for (int i = 0; i < num.size(); i++)
                // {
                //     cout << num[i] << " ";
                // }
                // cout << endl;
            }
        }
        // for (list<int>::iterator it = num.begin(); it != num.end(); it++)
        // {
        //     cout << *it << " ";
        // }
        // cout << endl;
    }

    cout << num.back();

    
}


    

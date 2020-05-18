//
//  main.cpp
//  DynamicProgramming
//
//  Created by 费雄君 on 2020/5/10.
//  Copyright © 2020 WUST. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 *  功能：自顶向下求解最优解问题
 *
 *  输入：
 *      price_list: 价格表
 *      n: 钢条总长度
 *
 *  输出：
 *      max_value: 最优解
 */
int cut_rod(vector<int> price_list, int n)
{
    int max_value = 0;
    // 边界条件
    if (n == 0)
    {
        return 0;
    }
    // 自上到下递归
    for (int i = 1; i < n; i++)
    {
        max_value = max(max_value, price_list[i] + cut_rod(price_list, n - i));
    }
    
    return max_value;
}

/*
 *  功能：带备忘的自顶向下求解最优解问题
 *
 *  输入：
 *      price_list: 价格表
 *      n: 钢条总长度
 *
 *  输出：
 *      max_value: 最优解
 */
int memoized_cut_rod(vector<int> price_list, int n, vector<int> &temp)
{
    // 备忘中存在子问题的解
    if (temp[n-1] != -1) {
        return temp[n-1];
    }
    int max_value = 0;
    // 边界条件
    if (n == 0)
    {
        temp[n-1] = 0;
        return 0;
    }
    // 自上到下递归
    for (int i = 1; i < n; i++)
    {
        max_value = max(max_value, price_list[i] + memoized_cut_rod(price_list, n - i, temp));
    }
    // 保存子问题的解到备忘temp
    temp[n-1] = max_value;
    
    return max_value;
}

/*
 *  功能：自底向上求解最优解问题
 *
 *  输入：
 *      price_list: 价格表
 *      n: 钢条总长度
 *
 *  输出：
 *      max_value: 最优解
 */
int bottom_up_cut_rod(vector<int> price_list, int n, vector<int> &temp)
{
    temp[0] = 0;
    int max_value = 0;
    for (int i = 0; i < n; i++)
    {
        int s = 0;
        for (int j = 0; j <= i; j++)
        {
            max_value = max(s, price_list[j] + temp[i - j]);
        }
        temp[i] = max_value;
    }
    
    return max_value;
}

int main(int argc, const char * argv[]) {
    // 钢条最优切割方案
    vector<int> price_list{0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};  // 价格表
    
    // 自顶向下法递归实现
    int i1 = cut_rod(price_list, price_list.size());
    cout << i1 << endl;
    
    // 带备忘的自顶向下法
    vector<int> temp(price_list.size(), -1);
    int i2 = memoized_cut_rod(price_list, price_list.size() , temp);
    cout << i2 << endl;
    
    // 自底向上法
    int i3 = bottom_up_cut_rod(price_list, price_list.size(), temp);
    cout << i3 << endl;
    
    return 0;
}

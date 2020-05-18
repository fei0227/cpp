//
//  main.cpp
//
//  选择算法
//
//  Created by 费雄君 on 2020/5/2.
//  Copyright © 2020 WUST. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
* 返回vec中的最小值
*
* 参数说明：
*     vec -- 数组
*/
int minmum(vector<int> vec)
{
    int min = vec[0], i;
    for (i = 1; i < vec.size(); i++) {
        // 保存最小值
        if (vec[i] < min)
            min = vec[i];
    }
    return min;
}

/*
* 返回vec中的最大值和最小值
*
* 参数说明：
*     vec -- 数组
*/
vector<int> maxmum_minmun(vector<int> vec)
{
    vector<int> max_min;
    int max, min, i;
    
    // 不同长度下max和min的初始化
    if (vec.size() % 2 == 0) {
        // 偶数
        if (vec[0] > vec[1]) {
            max = vec[0];
            min = vec[1];
        }
        else
        {
            min = vec[0];
            max = vec[1];
        }
        i = 2;
    }
    else
    {
        // 奇数
        max = vec[0];
        min = vec[0];
        i = 1;
    }
    
    // 成对处理剩下元素
    for (; i < vec.size(); i += 2) {
        if (vec[i] < vec[i + 1]) {
            if (vec[i] < min) {
                min = vec[i];
            }
            if (vec[i + 1] > max) {
                max = vec[i + 1];
            }
        }
        else
        {
            if (vec[i + 1] < min) {
                min = vec[i + 1];
            }
            if (vec[i] > max) {
                max = vec[i];
            }
        }
    }
    max_min.push_back(max);
    max_min.push_back(min);
    return max_min;
}

/*
* 返回nums中满足比左边所有数大，比右边所有数小的一个值
*
* 参数说明：
*     nums -- 数组
*     beginPos -- 开始坐标
*     endPos -- 结束坐标
*/
int randomized_patition(vector<int> &nums, int beginPos, int endPos)
{
    // 随机选择nums中的数，交换
    int q = rand() % nums.size();
    swap(nums[q], nums[endPos]);
    
    int i, j;
    i = beginPos - 1;
    // 以endPos值为中间值
    for (j = beginPos; j < endPos; j++) {
        if (nums[j] < nums[endPos]) {
            // 放到左边
            i = i + 1;
            swap(nums[j], nums[i]);
        }
    }
    // 交换中间值
    swap(nums[i+1], nums[endPos]);
    
    return i+1;
}

/*
* 返回nums中第i小的数
*
* 参数说明：
*     nums -- 数组
*     beginPos -- 开始坐标
*     endPos -- 结束坐标
*     i -- 第i小的数
*/
int randomized_select(vector<int> &nums, int beginPos, int endPos, int i)
{
    if (beginPos == endPos)
    {
        return nums[beginPos];
    }
    int midPos = randomized_patition(nums, beginPos, endPos);
    int k = midPos - beginPos + 1;  // midPos为第k小
    if (k == i)
    {
        // 找到第i小
        return nums[midPos];
    }
    else if (k > i)
    {
        // 第i小的值在左边
        return randomized_select(nums, beginPos, midPos - 1, i);
    }
    else if (k < 1)
    {
        // 第i小的值在右边
        return randomized_select(nums, midPos + 1, endPos, i - k);
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    // 获取数组最小值
    int min;
    vector<int> vec1{2, 4, 5, 10, 3, 0};
    min = minmum(vec1);
    cout << "数组vec1的最小值为：" << min << endl;
    
    // 同时获取最大最小值
    vector<int> max_min;
    vector<int> vec2{2, 4, 5, 10, 3, 99};
    max_min = maxmum_minmun(vec2);
    cout << "数组vec2的最大值为：" << max_min[0] << endl;
    cout << "数组vec2的最小值为：" << max_min[1] << endl;
    
    // 获取第i小的值
    int i = 3, min_i;
    vector<int> vec3{2, 4, 5, 10, 3, 99};
    min_i = randomized_select(vec3, 0, vec3.size(), i);
    cout << "数组vec3第3小的值为：" << min_i << endl;
    
    return 0;
}

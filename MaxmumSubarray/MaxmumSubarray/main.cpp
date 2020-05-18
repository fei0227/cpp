//
//  main.cpp
//  MaxmumSubarray
//
//  Created by 费雄君 on 2020/4/28.
//  Copyright © 2020 WUST. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct RElem
{
    int low, high, max_sum;
    RElem(int x, int y, int z) : low(x), high(y), max_sum(z) {}
};
// 函数声明
RElem FindMaxmunSubarray(int low, int high, vector<int> array);
RElem FindMaxCrossingSubarray(int low, int high, int mid, vector<int> array);

int main(int argc, const char * argv[]) {
    // 输入序列
    vector<int> nums{11, -10, 59, 26, 41, 58};
    cout << "原始序列：";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << "   ";
    }
    cout << endl;
    
    // 分治法寻找最大子数组
    RElem maxmum_array(0, 0, 0);
    maxmum_array = FindMaxmunSubarray(0, nums.size() - 1, nums);
    cout << "上界：" << maxmum_array.low << "   下界" << maxmum_array.high << "   最大值" << maxmum_array.max_sum;
    cout << endl;
    return 0;
}

RElem FindMaxmunSubarray(int low, int high, vector<int> array)
{
    if (low == high)
    {
        RElem temp(low, high, array[low]);
        return temp;
    }
    else
    {
        int mid = (low + high) / 2;
        RElem l_max(0, 0, 0), r_max(0, 0, 0), crossing_max(0, 0, 0);
        l_max = FindMaxmunSubarray(low, mid, array);
        r_max = FindMaxmunSubarray(mid + 1, high, array);
        crossing_max = FindMaxCrossingSubarray(low, high, mid, array);
        if (l_max.max_sum > r_max.max_sum && l_max.max_sum > crossing_max.max_sum) {
            return l_max;
        }
        else if (r_max.max_sum > l_max.max_sum && r_max.max_sum > crossing_max.max_sum)
        {
            return r_max;
        }
        else
        {
            return crossing_max;
        }
    }
}

RElem FindMaxCrossingSubarray(int low, int high, int mid, vector<int> array)
{
    int i, j, l_max, r_max, l_sum, r_sum, l_pos=mid, r_pos=mid+1;
    for (i = mid; i >= low; i--) {
        if (i == mid) {
            l_max = array[i];
            l_sum = array[i];
        }
        else
        {
            l_sum += array[i];
        }
        if (l_max < l_sum)
        {
            l_max = l_sum;
            l_pos = i;
        }
    }
    for (j = mid+1; j <= high; j++) {
        if (j == mid+1) {
            r_max = array[j];
            r_sum = array[j];
        }
        else
        {
            r_sum += array[j];
        }
        if (r_max < r_sum)
        {
            r_max = r_sum;
            r_pos = j;
        }
    }
    RElem result(l_pos, r_pos, r_max + l_max);
    return result;
}



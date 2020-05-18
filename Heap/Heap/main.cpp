//
//  main.cpp
//  Heap
//
//  Created by 费雄君 on 2020/4/29.
//  Copyright © 2020 WUST. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

// parent位置
int parent(int i)
{
    return (i - 1) / 2;
}
// left child位置
int left(int i)
{
    return 2*i+1;
}
// right child位置
int right(int i)
{
    return left(i) + 1;
}

// 最大堆函数声明
void max_heapify(vector<int> &vec, int i, int heap_size);
void build_max_heap(vector<int> &vec, int heap_size);
void heap_sort(vector<int> &vec, int heap_size);

int main(int argc, const char * argv[]) {
    vector<int> nums{4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    cout << "原始序列：";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << "   ";
    }
    cout << endl;
    
    vector<int> n1 = nums;
    heap_sort(n1, n1.size() - 1);
    cout << "堆排序结果：";
    for (int i = 0; i < n1.size(); i++) {
        cout << n1[i] << "   ";
    }
    cout << endl;
    
    return 0;
}

// 维护极大堆
void max_heapify(vector<int> &vec, int i, int heap_size)
{
    int l, r, length, largest, temp;
    length = vec.size();
    l = left(i);
    r = right(i);
    if (vec[i] < vec[l] && l <= heap_size) {
        largest = l;
    }
    else
    {
        largest = i;
    }
    if (vec[largest] < vec[r] && r <= heap_size) {
        largest = r;
    }
    if (largest != i)
    {
        temp = vec[largest];
        vec[largest] = vec[i];
        vec[i] = temp;
        max_heapify(vec, largest, heap_size);
    }
}

// 创建极大堆
void build_max_heap(vector<int> &vec, int heap_size)
{
    int length, i;
    length = vec.size() - 1;
    for (i = parent(length); i >= 0; i--) {
        max_heapify(vec, i, heap_size);
    }
}

// 堆排序
void heap_sort(vector<int> &vec, int heap_size)
{
    // 建极大堆
    build_max_heap(vec, heap_size);
    cout << "极大堆：";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << "   ";
    }
    cout << endl;
    
    // 堆排序
    while (heap_size > 0)
    {
        swap(vec[0], vec[heap_size]);
        heap_size -= 1;
        max_heapify(vec, 0, heap_size);
    }
}

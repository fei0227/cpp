//
//  main.cpp
//  MatrixChainOrder
//
//  矩阵链最优括号化
//  Created by 费雄君 on 2020/5/12.
//  Copyright © 2020 WUST. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
    功能：矩阵链最优括号化
 
    输入：
        matrix_chain:矩阵链
        position:最优括号位置信息

 */
void matrix_cahin_order(vector<int> matrix_chain, int position[][6])
{
    int num_matrix = (int)matrix_chain.size() - 1;       // 矩阵数量
    int temp[num_matrix+1][num_matrix+1];                   // 保存对应最优解
    int i, j, k, l, p;
    
    // 只有一个matrix，运算次数为0
    for (i=1; i<=num_matrix; i++)
    {
        temp[i][i] = 0;
    }
    for (l=2; l<=num_matrix; l++)
    {
        // 不同数量矩阵链对应最优解
        for (i=1; i<=num_matrix - l + 1; i++)
        {
            j = l + i -1;
            temp[i][j] = 1000000;      // 初始化为最大值
            // 计算矩阵链i,j最优解
            for (k=i; k<j; k++)
            {
                p = temp[i][k] + temp[k+1][j] + matrix_chain[i-1]*matrix_chain[k]*matrix_chain[j];
                if (p < temp[i][j])
                {
                    // 保存最优解及括号位置
                    temp[i][j] = p;
                    position[i][j] = k;
                }
            }
        }
    }
    // cout << temp[2][5] << endl;
}

/*
   功能：打印矩阵链最优括号化

   输入：
        position:最优括号位置信息
        i:起点
        j:终点
*/
void print_optimal_parens(int position[][6], int i, int j)
{
    // 使用递归
    if (i == j)
    {
        cout << "A" ;
    }
    else
    {
        cout << "(";
        print_optimal_parens(position, i, position[i][j]);
        print_optimal_parens(position, position[i][j] + 1, j);
        cout << ")";
    }
}

int main(int argc, const char * argv[]) {
    // 矩阵链初始化
    vector<int> matrix_chain{30, 35, 15, 5, 10, 20, 25};
    // 矩阵链最优括号化
    int position[6][6];
    matrix_cahin_order(matrix_chain, position);
    print_optimal_parens(position, 1, 6);
    cout << endl;
    return 0;
}

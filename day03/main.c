
#include <stdio.h>

/**
 * @brief 求一个整数数组中连续求和取值最大的值
 * @param nums 整数数组的首地址
 * @param numsSize 数组长度
 * @return 最大子数组和
 */
int maxSubArray(int *nums, int numsSize)
{
    // 如果数组长度小于1，那么直接返回
    if (numsSize < 1)
    {
        return -1;
    }

    // 存储当前最大值
    int max = nums[0];

    // 从外层循环开始
    for (int i = 0; i < numsSize; i++)
    {
        // 记录当前和
        int sum = 0;
        // 从内侧循环开始计算 i -> j 的子数组的元素和
        for (int j = i; j < numsSize; j++)
        {
            // 计算和
            sum += nums[j];
            // 如果和大于当前最大值，那么把最大值易主
            if (sum > max)
            {
                max = sum;
            }
            printf("%d %d %2d (%d)\n", i, j, sum, max);
        }
    }

    // 返回最大值
    return max;
}

int main()
{
    int nums[3] = {-1, 2, -1};
    printf("%d", maxSubArray(nums, 3));
}
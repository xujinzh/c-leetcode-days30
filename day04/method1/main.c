#include <stdio.h>
#include <stdbool.h>

/**
 * @brief 将数组中的所有零移动到末尾，并保持非零元素的相对顺序。
 *
 * @details 该函数采用类似冒泡排序的变体算法。通过不断查找相邻的 "零与非零"
 *          对并进行位置交换，直到数组中不再存在前零后非零的相邻组合为止。
 *
 * @param nums     指向整数数组的指针。
 * @param numsSize 数组中元素的总个数。
 *
 * @note 该实现的时间复杂度最坏情况下为 O(N^2)，空间复杂度为 O(1)。
 *       在实际工程中，通常可以使用更高效的双指针算法将时间复杂度优化至 O(N)。
 */
void moveZeros(int *nums, int numsSize)
{
    if (nums == NULL || numsSize <= 1)
    {
        return;
    }
    // 标识是否要进行循环判断
    bool needExchange = true;
    while (needExchange)
    {
        // 默认认为是已经排序好了
        needExchange = false;
        // 检查当前数组中是否已经达到了要求
        for (int i = 0; i + 1 < numsSize; i++)
        {
            // 如果没有达到要求，那么替换当前有问题的两个元素
            // 同时，标识数组还没有排序好
            // 继续下一次循环检查是否排序好
            if (nums[i] == 0 && nums[i + 1] != 0)
            {
                nums[i] = nums[i + 1];
                nums[i + 1] = 0;
                needExchange = true;
                // break;
            }
        }
    }
    return;
}

int main()
{
    int nums[5] = {3, 0, 12, 0, 1};
    moveZeros(nums, 5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", nums[i]);
    }
}
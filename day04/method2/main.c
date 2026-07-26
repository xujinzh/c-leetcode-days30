#include <stdio.h>

/**
 * @brief 将数组中的所有零移动到末尾，并保持非零元素的相对顺序（高效优化版）。
 *
 * @details 使用快慢双指针算法：
 *          - 慢指针 (slow) 维护下一个非零元素应当存放的位置。
 *          - 快指针 (fast) 用于遍历整个数组。
 *          当快指针指向非零元素时，将其与慢指针处的元素交换，随后慢指针前移。
 *
 * @param nums     指向整数数组的指针。
 * @param numsSize 数组中元素的总个数。
 *
 * @note 时间复杂度：O(N)，仅需遍历一次数组。
 *       空间复杂度：O(1)，直接在原数组上进行就地操作。
 */
void moveZeros(int *nums, int numsSize)
{
    if (nums == NULL || numsSize <= 1)
    {
        return;
    }

    // 记录下一个非零元素要存放的位置信息
    int slow = 0;

    for (int fast = 0; fast < numsSize; fast++)
    {
        // 快指针快速遍历时发现后面有一个非零元素
        // 那么和慢指针（记录当前数组从左开始的第一个0元素位置）的位置上的0元素进行交换
        // 可以想象快指针发现非零元素之前的所有元素都是满足要求的子数组
        // 而慢指针记录的就是这个子数组的第一个0元素位置
        if (nums[fast] != 0)
        {
            // 只有当快慢指针不相等时才进行交换，避免自己和自己交换
            if (fast != slow)
            {
                int temp = nums[fast];
                nums[fast] = nums[slow];
                nums[slow] = temp;
            }
            // 交换后，慢指针也前进一步
            slow++;
        }
    }
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
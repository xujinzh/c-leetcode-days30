#include <stdio.h>

/**
 * 通过对每一个元素与整个数组的每个元素从头到尾计算有几个相等的。
 * 如果发现某个元素与整个数组遍历后发现是单数个与它相等，那么说明它就是单数。
 *
 * 此方法，需要进行 n^2 级别的遍历，速度慢
 */

/**
 * @brief 在数组 nums 中寻找 单数 single number，即数组中某个元素只出现一次
 * @param nums 整数数组，指向数组的首地址
 * @param numsSize 整数数组的元素个数。通过这个元素个数，可以知道数组在内存中的那些元素
 * @return 返回数组中的单数
 */
int singleNumber(int *nums, int numsSize)
{
    // 对每一个元素进行遍历
    for (int i = 0; i < numsSize; i++)
    {
        // 记录当前元素在数组中出现的次数
        int count = 0;
        // 再次遍历整个数组，找与当前元素相等的元素个数
        for (int j = 0; j < numsSize; j++)
        {
            if (nums[j] == nums[i])
            {
                count++;
            }
        }
        // 如果当前元素与整个数组比较发现，只有1个与它相等，说明当前元素就是 single number
        if (count == 1)
        {
            return nums[i];
        }
    }
    // 程序必须要返回一个整数
    return -1;
}

int main()
{
    /**
     * 必须保证元素中只有一个元素是单数，其他元素都是双数
     */
    // 5个元素的数组，单数是4
    int nums1[5] = {4, 1, 2, 1, 2};
    int res1 = singleNumber(nums1, 5);
    printf("single number is %d\n", res1);

    // 3个元素的数组，单数是3
    int nums2[3] = {2, 2, 3};
    int res2 = singleNumber(nums2, 3);
    printf("single number is %d\n", res2);

    // 7个元素的数组，单数是7
    int nums3[7] = {4, 3, 2, 7, 2, 3, 4};
    int res3 = singleNumber(nums3, 7);
    printf("single number is %d\n", res3);

    // 带有负数的数组
    int nums4[3] = {-1, 2, -1};
    int res4 = singleNumber(nums4, 3);
    printf("single number: %d\n", res4);
}
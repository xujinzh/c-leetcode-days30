#include <stdio.h>

/**
 * 利用异或运算的两个规则：
 * 1. 任何整数和0进行异或运算XOR，结果是该数本身：
 *     0 ^ x = x,
 * 2. 异或运算具有交换律：
 *     x ^ y ^ x = x ^ (y ^ x) = x ^ (x ^ y) = (x ^ x) ^ y = 0 ^ y = y
 *
 */

/**
 * @brief 在数组 nums 中寻找 单数 single number，即数组中某个元素只出现一次
 * @param nums 整数数组，指向数组的首地址
 * @param numsSize 整数数组的元素个数。通过这个元素个数，可以知道数组在内存中的那些元素
 * @return 返回数组中的单数
 */
int singleNumber(int *nums, int numsSize)
{
    if (numsSize < 0 || numsSize % 2 == 0)
    {
        return 0;
    }
    // if (numsSize == 1)
    // {
    //     return nums[0];
    // }

    int single = nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        single ^= nums[i];
    }
    return single;
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

    // 带有负数的数组，单数是2
    int nums4[3] = {-1, 2, -1};
    int res4 = singleNumber(nums4, 3);
    printf("single number is %d\n", res4);

    // 单个元素
    int nums5[1] = {1};
    int res5 = singleNumber(nums5, 1);
    printf("single number is %d\n", res5);
}
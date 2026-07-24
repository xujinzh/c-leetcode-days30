#include <stdbool.h>
#include <stdio.h>

/**
 * @brief 输入一个整数，输出整数每位数字平方的和
 * @param n 整数
 * @return 每位元素的平方和。如 n = 19, 返回 1^2 + 9^2
 */
int nextN(int n)
{
    // 存储元素平方和
    int r = 0;
    // 如果整数不为0
    while (n != 0)
    {
        // 先获取整数的个位
        int d = n % 10;
        // 通过整除运算（/= 10）去掉当前的个位数，将整数向右移一位
        n /= 10;
        // 计算当前位数字的平方，并累加到结果变量 r 中
        r += d * d;
    }
    // 返回最终计算出的平方和
    return r;
}

/**
 * @brief 判断一个整数是否为快乐数
 * @param n 输入的整数
 * @return 如果是快乐数返回 true，否则返回 false
 *
 * cycle detection
 * Floyd's Tortoise and Hare
 *                +
 *  + -> + - > +     +
 *                +
 *
 */
bool isHappy(int n)
{
    // 初始化慢指针：走一步
    int slow = nextN(n);
    // 初始化快指针：走两步
    int fast = nextN(nextN(n));
    // 如果快慢指针没有相遇，说明没有检测到循环，继续前进
    while (fast != slow)
    {
        // 慢指针每次走一步
        slow = nextN(slow);
        // 快指针每次走两步
        fast = nextN(nextN(fast));
    }
    // 循环结束意味着快慢指针相遇（破除了死循环）
    // 如果相遇在 1，说明该数最终收敛到 1，是快乐数
    if (fast == 1)
    {
        return true;
    }
    // 如果相遇在其他数字，说明陷入了其他数字的死循环，不是快乐数
    return false;
}

int main()
{
    int n = 19;
    printf("%d is happy number ? %d\n", n, isHappy(n));
}
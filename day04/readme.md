Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

**Example**:
```bash
Input: [0, 1, 0, 3, 12]
Output: [1, 3, 12, 0, 0]
```

**Note**:
1. You must do this in-place without making a copy of the array.
2. Minimize the total number of operations.


**method3**:

[1, 0, 3, 12, 0]

遍历数组，遇到0都放到数组最后面

**method4**:

[1, 0, 3, 12, 0]

定义一个变量，用于指向放非零的元素位置j，从0开始。循环便利数组，如果遇到非0的元素就放到j的位置，然后让j++。便利完数组后，再把j到数组最后一个元素的位置都放0即可。


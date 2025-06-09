#include <iostream>
using namespace std;
//题目：对数组执行操作
//https://leetcode.cn/problems/apply-operations-to-an-array/description/
int *applyOperations(int *nums, int numsSize, int *returnSize)
{
    for (int i = 0; i < numsSize - 1; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            nums[i] *= 2;
            nums[i + 1] = 0;
        }
    }

    int cur = 0, dest = -1;
    while (cur < numsSize) {
        if (nums[cur] == 0) {
            cur++;
        } else {
            int temp = nums[cur];
            nums[cur] = nums[++dest];
            nums[dest] = temp;
            cur++;
        }
    }
    *returnSize = numsSize;
    return nums;
}
int main()
{
    int nums[6] = {1, 0, 2, 0, 0, 1};
    int returnSize;
    applyOperations(nums, 6, &returnSize);
    for(int i = 0; i < 6; i++)
    {
        cout << nums[i] << endl;
    }
    return 0;
}
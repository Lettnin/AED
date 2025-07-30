// Given a zero-based permutation nums (0-indexed), build an array ans of the same length where ans[i] = nums[nums[i]] for each 0 <= i < nums.length and return it.
// A zero-based permutation nums is an array of distinct integers from 0 to nums.length - 1 (inclusive).

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int *buildArray(int *nums, int numsSize, int *returnSize)
{

  *returnSize = numsSize;
  int *array = (int *)malloc(numsSize * sizeof(int));
  for (int i = 0; i < numsSize; i++)
  {
    array[i] = nums[nums[i]];
  }

  return array;
  free(array);
}
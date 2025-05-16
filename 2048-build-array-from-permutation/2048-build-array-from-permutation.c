/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* buildArray(int* nums, int numsSize, int* returnSize) {
    int i;
    int *array = (int*)malloc(numsSize *sizeof(int));
    for(i=0; i < numsSize; i++){
        array[i] = nums[nums[i]];
    }
    *returnSize = numsSize;

    return array;
    free(array);

}
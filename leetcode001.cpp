/*给定一个整数数组 nums?和一个整数目标值 target，请你在该数组中找出 和为目标值 target? 的那?两个?整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。

?

示例 1：

输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
示例 2：

输入：nums = [3,2,4], target = 6
输出：[1,2]
示例 3：

输入：nums = [3,3], target = 6
输出：[0,1]
?

提示：

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
只会存在一个有效答案
进阶：你可以想出一个时间复杂度小于 O(n2) 的算法吗？
*/
#include<stdio.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	//解法1.两层循环遍历  时间复杂度o(n2)
	for(int i=0;i<numsSize;i++){
		if(nums[i]>target){
			continue;
		}else{
			for(int j=i+1;j<numsSize;j++){
				if(nums[j]>target){
					continue;
				}
				if(nums[i]+nums[j]==target){
					*returnSize = i;
					returnSize++;
					*returnSize = j;
					break;
				}
			}
		}
	}
	return returnSize;
}
int main(){

	int arr[100] = {0};
	int i=0,numSize = 0,target = 0;
	int returnArr[2] = {0};
	printf("请输入数组个数：");
	scanf("%d",&numSize);
	printf("请输入元素：");
	for(i=0;i<numSize;i++){
		scanf("%d",&arr[i]);
	}
	printf("请输入结果:");
	scanf("%d",&target);
	twoSum(arr, numSize,target, returnArr);
	for(i=0;i<2;i++){
		printf("%d ",returnArr[i]);
	}
	
return 0;
}


/*����һ���������� nums?��һ������Ŀ��ֵ target�������ڸ��������ҳ� ��ΪĿ��ֵ target? ����?����?���������������ǵ������±ꡣ

����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ�������ͬһ��Ԫ���ڴ��ﲻ���ظ����֡�

����԰�����˳�򷵻ش𰸡�

?

ʾ�� 1��

���룺nums = [2,7,11,15], target = 9
�����[0,1]
���ͣ���Ϊ nums[0] + nums[1] == 9 ������ [0, 1] ��
ʾ�� 2��

���룺nums = [3,2,4], target = 6
�����[1,2]
ʾ�� 3��

���룺nums = [3,3], target = 6
�����[0,1]
?

��ʾ��

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
ֻ�����һ����Ч��
���ף���������һ��ʱ�临�Ӷ�С�� O(n2) ���㷨��
*/
#include<stdio.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	//�ⷨ1.����ѭ������  ʱ�临�Ӷ�o(n2)
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
	printf("���������������");
	scanf("%d",&numSize);
	printf("������Ԫ�أ�");
	for(i=0;i<numSize;i++){
		scanf("%d",&arr[i]);
	}
	printf("��������:");
	scanf("%d",&target);
	twoSum(arr, numSize,target, returnArr);
	for(i=0;i<2;i++){
		printf("%d ",returnArr[i]);
	}
	
return 0;
}


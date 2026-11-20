class Solution:
    def moveZeroes(self, nums: list[int]) -> None:
        n=len(nums)
        i=0
        for j in range(0, n):
            if nums[j]!=0:
                nums[i], nums[j]=nums[j], nums[i]
                i+=1

        """
        Do not return anything, modify nums in-place instead.
        """
        
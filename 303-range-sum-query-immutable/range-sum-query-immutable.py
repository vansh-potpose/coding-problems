class NumArray(object):

    def __init__(self, nums):
      
        self.nums = []
        self.nums.append(nums[0])
        for i in range(1, len(nums)):
            self.nums.append(self.nums[i-1] + nums[i])

    def sumRange(self, left, right):
        if left == 0:
            return self.nums[right]
        return self.nums[right] - self.nums[left-1] # remember left is inclusive, hence left -1



# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)
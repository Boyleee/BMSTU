class Solution {
    fun rob(nums: IntArray): Int {
        tailrec fun looprob(nums: IntArray, index: Int, last: Boolean, babka: Int): Int{
            var babki = babka
            when {
                (index >= nums.size - 1) -> return when {
                    (index == nums.size - 1) -> babki + nums[index]
                    else -> babki
                }
                else -> {
                    babki += nums[index]
                    return when (last) {
                        true -> looprob(nums, index + 2, false, babki)
                        false -> max(looprob(nums, index + 1, true, babki), looprob(nums, index + 2, false, babki))
                    }
                }
            }
        }
        return max(looprob(nums, 0, false, 0), looprob(nums, 1, false, 0))
    }
}
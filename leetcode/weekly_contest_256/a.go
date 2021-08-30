// https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/
func min(a,b int)int{
    if a<b {
        return a
    }else{
        return b
    }
}
func minimumDifference(nums []int, k int) int {
    const INF = int(1e9+7)
    sort.Ints(nums)
    res:=INF
    for i:=k-1;i<len(nums);i++{
        res=min(nums[i]-nums[i-k+1],res)
    }
    return res
}

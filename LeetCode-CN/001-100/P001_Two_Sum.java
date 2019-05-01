/*
https://leetcode-cn.com/classic/problems/two-sum/description/
在遍历的过程中, 查找另一个数是否出现过

*/

import java.util.Map;
import java.util.HashMap;

class Solution{
	public int[] twoSum(int[] nums, int target) {
		Map<Integer, Integer> map = new HashMap<>();
		for( int i = 0; i < nums.length; i++ ){
			int val1 = nums[i];
			int val2 = target - val1;
			if( map.containsKey(val2) == true ){
				int idx1 = i;
				int idx2 = map.get(val2);
				return new int[] {idx1, idx2};
			}
			else{
				map.put(val1, i);
			}
		}
		return new int[]{0, 1};
	}
}

// 假设源文件名是 Main.java
public class Main{
	public static void main(String args[]) {
		int[] nums = {2, 7, 11, 15};
		int target = 9;
		Solution s = new Solution();
		int[] ans = s.twoSum(nums, target);
		System.out.println(ans[0] + " " + ans[1]);
	}
}
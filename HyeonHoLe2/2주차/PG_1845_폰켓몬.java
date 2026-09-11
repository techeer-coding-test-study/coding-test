import java.util.*;

class Solution {
    public int solution(int[] nums) {
        int max = 0;
        max = nums.length/2; 
        Set<Integer> set = new HashSet<>();
        
        for(int i : nums){
            set.add(i);
        }
        if(set.size() >= max){
            return max;
        }
        else{
            return set.size();
        }   
    }
}
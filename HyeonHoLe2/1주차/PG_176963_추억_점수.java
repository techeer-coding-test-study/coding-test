import java.util.HashMap;
import java.util.Map;

class Solution {
    public int[] solution(String[] name, int[] yearning, String[][] photo) {
        Map<String, Integer> answer = new HashMap<>();
        
        for (int i = 0; i < name.length; i++) {
            answer.put(name[i], yearning[i]);
        }
        
        int[] result = new int[photo.length];
        
        for (int i = 0; i < photo.length; i++) {
            int total = 0;    
            for (int j = 0; j < photo[i].length; j++) {
                if (answer.containsKey(photo[i][j])) {
                    total += answer.get(photo[i][j]);
                }
            }
            result[i] = total;
        }
        
        return result;
    }
    
}
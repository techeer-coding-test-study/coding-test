import java.util.Arrays;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int i = 0;
        int j = 0;
        int k = 0;
        int[] answer = {};
        int[] result = new int[commands.length];
        
        for(int x = 0; x < commands.length; x++){
            i = commands[x][0];
            j = commands[x][1];
            k = commands[x][2];
            
            answer = new int[j - i + 1];
            for(int z = 0; z < j - i + 1; z++){
                answer[z] = array[z + (i - 1)]; 
            }
            Arrays.sort(answer);
            result[x] = answer[k - 1];
        }
        return result;
    }
}
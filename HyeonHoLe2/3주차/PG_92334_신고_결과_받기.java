import java.util.*;

class Solution {
    public int[] solution(String[] id_list, String[] report, int k) {
  
        Set<String> uniqueReports = new HashSet<>(Arrays.asList(report));
        
        Map<String, Set<String>> map = new HashMap<>(); 
        Map<String, Integer> map2 = new HashMap<>();    
        
        for(String r : uniqueReports){
            String[] parts = r.split(" ");
            String reporter = parts[0];
            String reported = parts[1];
            
           
            map2.put(reported, map2.getOrDefault(reported, 0) + 1);
            
         
            map.putIfAbsent(reporter, new HashSet<>());
            map.get(reporter).add(reported);
        }
        
        int[] answer = new int[id_list.length];
        
       
        for(int i = 0; i < id_list.length; i++){
            String user = id_list[i];
 
            Set<String> reportedList = map.getOrDefault(user, new HashSet<>());
            
            int mailCount = 0;
            for(String target : reportedList) {
          
                if(map2.getOrDefault(target, 0) >= k) {
                    mailCount++;
                }
            }
            answer[i] = mailCount;
        }
        
        return answer;
    }
}
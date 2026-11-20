from itertools import combinations
from collections import Counter

def solution(orders, course):
    answer = []
    
    for n in course:
        counter=Counter()
        
        #각 주문에서 조합 뽑고 개수 세기
        for order in orders:
            for combo in combinations(sorted(order), n):
                counter["".join(combo)] +=1
                
        #조합이 하나도 없으면 건너뛰기        
        if not counter:
            continue
            
            
        #가장 많이 나온 횟수    
        max_cnt=max(counter.values())
        if max_cnt <2:
            continue
            
        max_cnt=max(counter.values())
        if max_cnt <2:
            continue
            
        for menu,cnt in counter.items():
            if cnt==max_cnt:
                answer.append(menu)
        
    
    return sorted(answer)

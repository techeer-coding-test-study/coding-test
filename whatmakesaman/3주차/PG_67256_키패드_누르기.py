position={
    '1': (0,0), '2': (1,0), '3': (2,0),
    '4': (0,1), '5': (1,1), '6': (2,1),
    '7': (0,2), '8': (1,2), '9': (2,2),
    '*': (0,3), '0': (1,3), '#': (2,3),
}

def distance(a,b):
    x1, y1=position[a]
    x2,y2=position[b]
    
    return abs(x1-x2)+abs(y1-y2)

def solution(numbers, hand):
    answer = ''
    left, right='*','#'
        
    for n in numbers:
        s=str(n)      
        
        if s in ('1','4','7'):
            answer+='L'
            left=s
            
        elif s in ('3','6','9'):
            answer+='R'
            right=s
            
        else:
            dl=distance(s,left)
            dr=distance(s, right)
            
            if dl < dr:
                answer+='L'
                left=s
            elif dl > dr:
                answer+='R'
                right=s
            else:
                if hand=='left':
                    answer+='L'
                    left=s
                else:
                    answer+='R'
                    right=s
    return answer
def solution(places):
    

    return [check(place) for place in places]

def check(place):
    d1=[(-1,0), (1,0), (0,-1), (0,1)]
    d2_st=[(-2,0), (2,0),(0,-2),(0,2)]
    d2_a=[(-1,-1), (-1,1), (1,-1), (1,1)]
    
    for r in range(5):
        for c in range(5):
            if place[r][c] != 'P':
                continue
                
            # 거리=1, P
            for dr, dc in d1:
                nr, nc=r+dr, c+dc
                if 0<= nr < 5 and 0 <= nc < 5 and place[nr][nc] =='P':
                    return 0
            
            # 직선 거리 2: 사이 칸이 x가 아니면 
            for dr, dc in d2_st:
                nr, nc = r+dr, c+dc
                if 0<= nr <5 and 0<= nc <5 and place[nr][nc] == 'P':
                    if place[r +dr //2][c + dc //2] != 'X':
                        return 0
                
            # 대각선, 두 사이가 모두 X여야
            for dr, dc in d2_a:
                nr,nc = r +dr, c+dc
                if 0<= nr < 5 and 0<= nc <5 and place[nr][nc] =='P':
                    if place[r+dr][c] != 'X' or place[r][c+dc] != 'X':
                            return 0
    
    return 1







from collections import deque

def bfs(start, target, maps):
    n, m = len(maps), len(maps[0])          # 행 개수, 열 개수

    # 출발점에서 각 칸까지의 거리를 적는 표
    # -1 = 아직 안 가 본 칸
    dist = [[-1] * m for _ in range(n)]

    q = deque([start])                       # 큐에는 처음에 출발점 하나만 넣음
    dist[start[0]][start[1]] = 0             # 출발점의 거리는 0 (방문 표시도 겸함)

    while q:                                 # 큐가 빌 때까지 반복
        x, y = q.popleft()                   # 먼저 들어온 칸부터 꺼냄 = 현재 위치

        if (x, y) == target:                 # 현재 위치가 목적지면
            return dist[x][y]                # 그 칸까지의 거리가 곧 최단 거리

        # 상, 하, 좌, 우 네 방향 확인
        for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            nx, ny = x + dx, y + dy          # 옆 칸 좌표

            # 1) 맵 밖이면 패스
            if not (0 <= nx < n and 0 <= ny < m):
                continue
            # 2) 벽(X)이면 패스
            if maps[nx][ny] == 'X':
                continue
            # 3) 이미 가 본 칸이면 패스
            if dist[nx][ny] != -1:
                continue

            # 세 조건을 다 통과한 칸 = 새로 갈 수 있는 칸
            dist[nx][ny] = dist[x][y] + 1    # 현재 칸 거리 + 1
            q.append((nx, ny))               # 나중에 이 칸에서도 퍼져 나가도록 큐에 추가

    return -1                                # 큐가 비었는데 목적지에 못 갔으면 도달 불가


def solution(maps):
    n, m = len(maps), len(maps[0])

    # S, L, E 위치 찾기
    for i in range(n):
        for j in range(m):
            if maps[i][j] == 'S':
                start = (i, j)
            elif maps[i][j] == 'L':
                lever = (i, j)
            elif maps[i][j] == 'E':
                end = (i, j)

    # 1단계: S → L
    to_lever = bfs(start, lever, maps)
    if to_lever == -1:                       # 레버까지 못 가면 탈출 불가
        return -1

    # 2단계: L → E
    to_end = bfs(lever, end, maps)
    if to_end == -1:                         # 레버에서 출구까지 못 가면 탈출 불가
        return -1

    return to_lever + to_end                 # 두 구간 거리의 합이 답

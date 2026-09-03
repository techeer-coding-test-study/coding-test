#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> viurse(int n, vector<int> map, vector<vector<int>> edges) {
    int z = edges.size();
    
    for (int step = 0; step < z; step++) {
        for (int i = 0; i < z; i++) {
            if (edges[i][2] == n) {
                int u = edges[i][0] - 1;
                int v = edges[i][1] - 1;

                // 둘 중 하나라도 감염되어 있다면 둘 다 감염 
                if (map[u] == 1 || map[v] == 1) {
                    map[u] = 1;
                    map[v] = 1;
                }
            }
        }
    }
    return map;
}

int DFS(int k,int ABC,vector<vector<int>> edges, vector<int> map){
    if(k == 0){
        //맵에서 바이러스에 감염된 숫자를 세
        int count = 0;
        for(int i =0;i<map.size();i ++){
            if(map[i] == 1){
                count++;
            }
        }
        return count;
    }
    int Max = 0;
    for(int i = 1;i<=ABC;i++){
        int a = DFS(k - 1, 3, edges, viurse(i, map, edges));
        if(Max < a)
            Max = a;
    }
    return Max;
}

int solution(int n, int infection, vector<vector<int>> edges, int k) {
    vector<int> map;
    for (int i=0; i< n;i++){
        map.push_back(0);
    }
    map[infection-1] = 1;
    
    return DFS(k,3,edges,map);
    
}
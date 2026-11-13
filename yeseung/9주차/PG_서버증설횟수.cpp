#include <string>
#include <vector>

using namespace std;

int solution(vector<int> players, int m, int k) {
    vector<int> server;
    int answer = 0;
    int server_add;
    for(int i = 0; i<24;i++){
        for(int& j : server)
            j++;
        
        erase(server,k);
        server_add = (players[i] / m) - server.size();
        if(server_add > 0){
            server.insert(server.end(),server_add,0);
            answer += server_add;
        }
        
    }
    return answer;
}

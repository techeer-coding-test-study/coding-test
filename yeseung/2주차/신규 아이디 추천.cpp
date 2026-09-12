#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    for(int i = 0; i< new_id.size();i++){
        if ('A'<=new_id[i] && new_id[i]<= 'Z')
            new_id[i] += 'a' -'A';
    }
    
    for(int i = 0;i<new_id.size();i++)
        if(!((  new_id[i] >= 'a' && new_id[i] <= 'z') ||
             (  new_id[i] >= '0' && new_id[i] <= '9') ||
                new_id[i] == '-' ||
                new_id[i] == '_' ||
                new_id[i] == '.')   ){
            new_id.erase(i, 1);
            i--;
        }


    int index = 0;
    while((index = new_id.find("..")) != -1)
        new_id.erase(index,1);
    
    if(new_id[0] == '.')
        new_id.erase(0,1);
    if(new_id.back() == '.')
        new_id.pop_back();
    
    
    if(new_id.size() == 0)
        new_id += "a";
    
    if(new_id.size()>=16)
        new_id = new_id.substr(0,15);
    
    if(new_id.back() == '.')
        new_id.pop_back();

    
    for(int i = new_id.size();i<3;i++)
        new_id += new_id.back();
    return new_id;
}

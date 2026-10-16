class Solution {

    int dfs(vector<vector<int>>& s, int k, int depth, int past, int cur) {
        if (depth > k)
            return 0;
        int count = 1;
        for (int i : s[cur]) {
            if (i != past) {
                count += dfs(s, k, depth + 1, cur ,i);
            }
        }
        return count;
    }

public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1,vector<vector<int>>& edges2, int k) {
        vector<vector<int>> s1(edges1.size()+1);
        vector<vector<int>> s2(edges2.size()+1);
        vector<int> answer;
        for (vector<int>& i : edges1) {
            s1[i[0]].push_back(i[1]);
            s1[i[1]].push_back(i[0]);
        }
        for (vector<int>& i : edges2) {
            s2[i[0]].push_back(i[1]);
            s2[i[1]].push_back(i[0]);
        }

        int count_s2 = 0;
        int max_count = 0;

        if (k == 0) {
            count_s2 = 0;
        } else

            for (int i = 0; i<s2.size(); i++) {
                count_s2 = dfs(s2, k-1, 0, -1,i);
                if (count_s2 > max_count) {
                    max_count = count_s2;
                }
            }

        for (int i = 0; i < edges1.size() + 1; i++) {
                answer.push_back(dfs(s1, k, 0, -1, i) + max_count);
            
        }
        return answer;
    }
};

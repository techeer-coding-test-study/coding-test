class Solution {
public:
    string smallestNumber(string pattern) {
        int len = pattern.size();
        string s;
        int d_len = 1;
        int d_start;
        for(int i = 0; i<= len; i++){
            s += ((i+1) + '0');
        }
        for(int i = 0; i < len; i++){
            if(pattern[i] == 'D'){
                if(d_len == 1){
                    d_start = i;
                    d_len++;
                }
                else
                    d_len++;
            }
            else
                if(d_len > 1){
                    reverse(s.begin()+d_start, s.begin()+d_start+d_len);
                    d_len = 1;
                }
        }

        if(d_len > 1)
            reverse(s.begin()+d_start, s.begin()+d_start+d_len);

        return s;
    }
};

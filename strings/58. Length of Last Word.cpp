// 58. Length of Last Word


class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt=0;
        int i;
        
        for(i=s.size()-1;i>=0;i--)
        {
            if(s[i]!=' ')
            {
                cnt++;
                if(i==0 || s[i-1]==' ')
                {
                    break;
                }
            }
        }
        return cnt;
        
    }
};
class Solution {
public:
    int compress(vector<char>& chars) {
        int size = chars.size();
        int begin = 0; int end = 0; int idx = 0;
        while(end<size && begin<size)
        {
            char c = chars[begin];
            end = begin+1;
            chars[idx++] = c;
            while(end<size && chars[end]==c)
            {
                end++;
            }
            int length = end-begin;
            if(length == 1)
            begin = end;
            else
            {
                int idx2 = 0;
                string cnt = to_string(length);
                while(idx2<cnt.size())
                {
                    chars[idx++] = cnt[idx2++];
                }
                begin = end;
            }
        }
        return idx;
    }
};
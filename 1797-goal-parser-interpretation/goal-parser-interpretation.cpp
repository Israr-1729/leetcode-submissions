class Solution {
public:
    string interpret(string command) {
        int i = 0; int size = command.size();
        string ans = "";
        while(i < size)
        {
            if(i < size && command[i] == '(')
            {
                if(command[i+1] == ')')
                {
                    ans += 'o';
                    i += 2;
                }

                else 
                {
                    ans += "al";
                    i += 4;
                }
            }

            else
            {
                ans += 'G';
                i++;
            }
        }
        return ans;
    }
};
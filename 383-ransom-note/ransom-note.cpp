class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> frqRansom(26);
        vector<int> frqMagazine(26);
        int sizeRansom = ransomNote.size();
        int sizeMagazine = magazine.size();

        if(sizeMagazine<sizeRansom)
        return false;

        for(int i = 0; i<sizeRansom; i++)
        {
            frqRansom[ransomNote[i]-'a']++;
        }

        for(int i = 0; i<sizeMagazine; i++)
        {
            frqMagazine[magazine[i]-'a']++;
        }

        for(int i = 0; i<26; i++)
        {
            if(frqRansom[i]>frqMagazine[i])
            return false;
        }
        return true;
    }
};
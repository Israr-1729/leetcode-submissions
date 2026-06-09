class Solution {
public:

    bool isSorted(const vector<int> &arr)
    {
        int size = arr.size();
        for(int i = 0; i<size-1; i++)
        {
            if(arr[i+1]<arr[i])
            return false;
        }
        return true;
    }

    vector<int> sortRecursively(vector<int> friends, map<int, int> rank)
    {
        int size = friends.size();
        vector<int> friendsRank(size);
        for(int i = 0; i<size; i++)
        {
            friendsRank[i] = rank[friends[i]];
        }
        if(isSorted(friendsRank))
        return friends;

        else
        {
            for(int i = 0; i<friends.size()-1; i++)
            {
                if(rank[friends[i+1]]<rank[friends[i]])
                {
                    swap(friends[i+1], friends[i]);
                }
            }
        }
        return sortRecursively(friends, rank);
    }

    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        map<int, int> rank;
        int size = order.size();
        for(int i = 0; i<size; i++)
        {
            rank[order[i]] = i;
        }

        return sortRecursively(friends, rank);
    }
};
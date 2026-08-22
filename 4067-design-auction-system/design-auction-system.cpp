class AuctionSystem {
public:

    unordered_map<int, set<int>> itemIdtoUserIds;
    unordered_map<int, set<int>> itemIdtoBidAmounts;
    unordered_map<int, unordered_map<int, int>> itemToUserIdToBidAmount;
    unordered_map<int, unordered_map<int, set<int>>> itemToBidAmountToUserId;

    AuctionSystem() {
        
    }
    
    void addBid(int userId, int itemId, int bidAmount) {

        if(itemToUserIdToBidAmount[itemId].contains(userId))
        {
            int oldAmount = itemToUserIdToBidAmount[itemId][userId];

            itemToBidAmountToUserId[itemId][oldAmount].erase(userId);

            if(itemToBidAmountToUserId[itemId][oldAmount].empty())
            {
                itemIdtoBidAmounts[itemId].erase(oldAmount);
            }
        }

        itemIdtoUserIds[itemId].insert(userId);
        itemIdtoBidAmounts[itemId].insert(bidAmount);
        itemToUserIdToBidAmount[itemId][userId] = bidAmount;
        itemToBidAmountToUserId[itemId][bidAmount].insert(userId);
    }
    
    void updateBid(int userId, int itemId, int newAmount) {
        int oldAmount = itemToUserIdToBidAmount[itemId][userId];

        itemToBidAmountToUserId[itemId][oldAmount].erase(userId);

        if(itemToBidAmountToUserId[itemId][oldAmount].empty())
        {
            itemIdtoBidAmounts[itemId].erase(oldAmount);
        }

        itemIdtoBidAmounts[itemId].insert(newAmount);

        itemToUserIdToBidAmount[itemId][userId] = newAmount;
        itemToBidAmountToUserId[itemId][newAmount].insert(userId);
    }
    
    void removeBid(int userId, int itemId) {
        int oldAmount = itemToUserIdToBidAmount[itemId][userId];

        itemIdtoUserIds[itemId].erase(userId);

        itemToBidAmountToUserId[itemId][oldAmount].erase(userId);

        if(itemToBidAmountToUserId[itemId][oldAmount].empty())
        {
            itemIdtoBidAmounts[itemId].erase(oldAmount);
        }

        itemToUserIdToBidAmount[itemId].erase(userId);
    }
    
    int getHighestBidder(int itemId) {

        if(itemIdtoBidAmounts[itemId].empty())
            return -1;

        int highestAmount = *itemIdtoBidAmounts[itemId].rbegin();

        return *itemToBidAmountToUserId[itemId][highestAmount].rbegin();
    }
};
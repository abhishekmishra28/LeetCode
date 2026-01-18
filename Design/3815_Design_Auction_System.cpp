/*
 * Problem: 3815. Design Auction System
 *
 * Statement:
 * You are asked to design an auction system that manages bids
 * from multiple users in real time.
 *
 * Each bid has:
 * - userId
 * - itemId
 * - bidAmount
 *
 * You must support the following operations efficiently:
 *
 * 1) addBid(userId, itemId, bidAmount)
 *    - Add a new bid
 *    - If the same user already bid on the same item,
 *      replace the old bid
 *
 * 2) updateBid(userId, itemId, newAmount)
 *    - Update an existing bid (guaranteed to exist)
 *
 * 3) removeBid(userId, itemId)
 *    - Remove an existing bid (guaranteed to exist)
 *
 * 4) getHighestBidder(itemId)
 *    - Return userId with highest bidAmount
 *    - If tie in bidAmount, return the HIGHEST userId
 *    - If no bids exist, return -1
 *
 * ------------------------------------------------------------
 * APPROACH: Hash Maps + Ordered Set (Your Approach)
 *
 * Core Idea:
 *
 * We need to efficiently support:
 * - Fast updates/removals of bids
 * - Fast retrieval of highest bid per item
 *
 * So we maintain TWO data structures:
 *
 * ------------------------------------------------------------
 * Data Structures Used:
 *
 * 1) bid:
 *    unordered_map<itemId, unordered_map<userId, bidAmount>>
 *
 *    Purpose:
 *    - Direct access to a user's bid for an item
 *    - Needed for update/remove operations
 *
 * 2) rank:
 *    unordered_map<itemId, set<pair<bidAmount, userId>>>
 *
 *    Purpose:
 *    - Maintains bids SORTED by:
 *         (bidAmount ASC, userId ASC)
 *    - The highest bid is at the END of the set
 *    - Automatically handles tie-breaking by userId
 *
 * ------------------------------------------------------------
 * Why set<pair<int,int>> works perfectly:
 *
 * - set keeps elements ordered
 * - pair sorting rule:
 *      first  → bidAmount
 *      second → userId
 *
 * So:
 * - Highest bidAmount comes last
 * - If bidAmount ties, higher userId comes last
 *
 * Exactly matches the problem requirement.
 *
 * ------------------------------------------------------------
 * addBid(userId, itemId, bidAmount)
 *
 * Logic:
 * 1) If user already has a bid on this item:
 *      - Remove the old (amount, userId) from rank[itemId]
 *
 * 2) Update bid[itemId][userId] = bidAmount
 *
 * 3) Insert (bidAmount, userId) into rank[itemId]
 *
 * Time Complexity:
 * - O(log N) due to set insert/erase
 *
 * ------------------------------------------------------------
 * updateBid(userId, itemId, newAmount)
 *
 * Logic:
 * 1) Get old bid amount from bid map
 * 2) Remove (oldAmount, userId) from rank[itemId]
 * 3) Update bid map with newAmount
 * 4) Insert (newAmount, userId) into rank[itemId]
 *
 * Guaranteed that bid exists → no extra checks needed
 *
 * Time Complexity:
 * - O(log N)
 *
 * ------------------------------------------------------------
 * removeBid(userId, itemId)
 *
 * Logic:
 * 1) Get old bid amount
 * 2) Erase userId from bid[itemId]
 * 3) Erase (oldAmount, userId) from rank[itemId]
 *
 * Time Complexity:
 * - O(log N)
 *
 * ------------------------------------------------------------
 * getHighestBidder(itemId)
 *
 * Logic:
 * 1) If itemId has no bids → return -1
 * 2) The highest bid is:
 *      rank[itemId].rbegin()
 *
 * 3) Return:
 *      rbegin()->second (userId)
 *
 * Time Complexity:
 * - O(1)
 *
 * ------------------------------------------------------------
 * Example:
 *
 * Bids for itemId = 10:
 *
 * rank[10] = {
 *   (100, 2),
 *   (100, 5),
 *   (120, 3)
 * }
 *
 * Highest = (120, 3) → return userId = 3
 *
 * If instead:
 *   (120, 3),
 *   (120, 7)
 *
 * Highest = (120, 7) → return userId = 7
 *
 * ------------------------------------------------------------
 * Edge Cases Handled:
 *
 * - Same user re-bids on same item
 * - Multiple users with same bidAmount
 * - Removing bids cleanly
 * - Querying empty items
 *
 * ------------------------------------------------------------
 * Time Complexity Summary:
 *
 * | Operation          | Complexity |
 * |-------------------|------------|
 * | addBid            | O(log N)   |
 * | updateBid         | O(log N)   |
 * | removeBid         | O(log N)   |
 * | getHighestBidder  | O(1)       |
 *
 * N = number of bids per item
 *
 * ------------------------------------------------------------
 * Space Complexity:
 *
 * - O(total number of bids)
 *
 * ------------------------------------------------------------
 * Pattern Recognition:
 *
 * This is a classic:
 *   "Design Data Structure with Ordering + Fast Updates"
 *
 * Common in:
 * - Leaderboards
 * - Ranking systems
 * - Real-time bidding systems
 */

#include <bits/stdc++.h>
using namespace std;

class AuctionSystem {
    // itemId -> (userId -> bidAmount)
    unordered_map<int, unordered_map<int,int>> bid;

    // itemId -> sorted set of (bidAmount, userId)
    unordered_map<int, set<pair<int,int>>> rank;

public:
    AuctionSystem() {}

    void addBid(int userId, int itemId, int bidAmount) {
        if (bid[itemId].count(userId)) {
            int oldAmt = bid[itemId][userId];
            rank[itemId].erase({oldAmt, userId});
        }
        bid[itemId][userId] = bidAmount;
        rank[itemId].insert({bidAmount, userId});
    }

    void updateBid(int userId, int itemId, int newAmount) {
        int oldAmt = bid[itemId][userId];
        rank[itemId].erase({oldAmt, userId});

        bid[itemId][userId] = newAmount;
        rank[itemId].insert({newAmount, userId});
    }

    void removeBid(int userId, int itemId) {
        int oldAmt = bid[itemId][userId];
        bid[itemId].erase(userId);
        rank[itemId].erase({oldAmt, userId});
    }

    int getHighestBidder(int itemId) {
        if (!rank.count(itemId) || rank[itemId].empty())
            return -1;
        return rank[itemId].rbegin()->second;
    }
};

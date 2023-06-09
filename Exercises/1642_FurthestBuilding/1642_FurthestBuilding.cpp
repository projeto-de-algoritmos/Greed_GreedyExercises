#include <bits/stdc++.h>
#define ll long long

using namespace std;
using ii = pair<int, int>;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int heightDiff, totalBuildings = heights.size();
        priority_queue<int, vector<int>, greater<int>> gaps;
        
        for (int i = 1; i < totalBuildings; ++i) {
            heightDiff = heights[i] - heights[i-1];

            if (heightDiff > 0) {
                if (ladders > 0) {
                    gaps.push(heightDiff);
                    --ladders;
                } else {
                    if (gaps.empty()) {
                        if (heightDiff > bricks) return --i;
                        else {
                            gaps.push(heightDiff);
                            bricks -= heightDiff;
                        }
                    } else {
                        if (heightDiff <= gaps.top()) {
                            if (heightDiff > bricks) return --i;
                            else bricks -= heightDiff;
                        } else {
                            if (gaps.top() > bricks) return --i;
                            else {
                                bricks -= gaps.top();
                                gaps.pop();
                                gaps.push(heightDiff);
                            }
                        }
                    }
                }
            }     
        }

        return --totalBuildings;
    }
};
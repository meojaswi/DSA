//17Jan26
//3047. Find the Largest Area of Square Inside Two Rectangles
/*https://leetcode.com/problems/find-the-largest-area-of-square-inside-two-rectangles/description/?envType=daily-question&envId=2026-01-17
*/

using ll = long long;

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft,
                                vector<vector<int>>& topRight) {
        ll area = 0;
        int n = bottomLeft.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                ll minX = max(bottomLeft[i][0], bottomLeft[j][0]);
                ll maxX = min(topRight[i][0],  topRight[j][0]);

                ll minY = max(bottomLeft[i][1], bottomLeft[j][1]);
                ll maxY = min(topRight[i][1],  topRight[j][1]);

                if (minX < maxX && minY < maxY) {
                    ll side = min(maxX - minX, maxY - minY);
                    area = max(area, side * side);
                }
            }
        }
        return area;
    }
};

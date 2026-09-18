#include <iostream>
#include <vector>

class Solution {
public:
    bool isRectangleOverlap(std::vector<int>& rec1, std::vector<int>& rec2) {
        int x1 = rec1[0];
        int y1 = rec1[1];
        int x2 = rec1[2];
        int y2 = rec1[3];
        std::pair<int, int> point1 = {x1, y1};
        std::pair<int, int> point2 = {x2, y2};
        std::pair<int, int> point3 = {x1, y2};
        std::pair<int, int> point4 = {x2, y1};
        std::vector<std::pair<int, int>> points = {point1, point2, point3, point4};
        for(std::pair<int, int> i : points){
            if(i.first > rec2[0] and i.second > rec2[1] and i.first < rec2[2] and i.second < rec2[3]){
                return true;
            }
        }
        if(x1 <= rec2[0] and x2 >= rec2[2] and ((y1 <= rec2[1] and y2 > rec2[1]) or (y1 >= rec2[1] and y1 < rec2[3]))){
            return true;
            }
        if(y1 <= rec2[1] and y2 >= rec2[3] and ((x1 <= rec2[0] and x2 > rec2[0]) or (x1 >= rec2[0] and x1 < rec2[2]))){
            return true;
        }
        return false;
    }
};
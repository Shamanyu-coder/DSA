class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // Find the point inside/on the rectangle closest to the circle center
        int nearestX = std::max(x1, std::min(xCenter, x2));
        int nearestY = std::max(y1, std::min(yCenter, y2));
        
        // Calculate the squared distance from circle center to closest point
        int deltaX = xCenter - nearestX;
        int deltaY = yCenter - nearestY;
        
        // Return true if distance <= radius
        return (deltaX * deltaX + deltaY * deltaY) <= (radius * radius);
    }
};
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1_1=rec1[0],y1_1=rec1[1];
        int x2_1=rec1[2],y2_1=rec1[3];
        int x1_2= rec2[0],y1_2=rec2[1];
        int x2_2=rec2[2],y2_2= rec2[3];
        if(x1_2>=x2_1)return false ;
        if(x2_2<=x1_1) return false ;
        if(y1_2>=y2_1)
        return false ;
        if(y2_2<=y1_1)
        return false ;

        return true;
    }
};
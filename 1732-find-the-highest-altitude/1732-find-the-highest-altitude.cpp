class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int max_altitude = 0;
        int altitude = 0;
        for(int i=0;i<gain.size();i++){
            altitude+=gain[i];
            if(altitude>max_altitude){
                max_altitude =altitude;
            }
        }
        return max_altitude;
    }
};
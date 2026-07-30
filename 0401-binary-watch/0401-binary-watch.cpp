class Solution {
public:
   int countBits(int n){
    int count =0;
    while(n>0){
        if(n%2 ==1)
        count++;
        n=n/2;
    }
    return count;
   }
   vector<string>readBinaryWatch(int turnedOn){
    vector<string> ans;
    for(int hour =0; hour<12; hour++){
        for(int minute=0; minute<60;minute++){
            int total =countBits(hour)+ countBits(minute);
            if(total == turnedOn){
                string time =to_string(hour)+ ":";
                if(minute<10)
                time+="0";
                time+=to_string(minute);
                ans.push_back(time);
            }
        }
    }
    return ans;
   }
};
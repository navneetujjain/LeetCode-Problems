class Solution {
public:
    int countTestedDevices(vector<int>& battery) {
        int tested = 0, reducer = 0;

        for(int i = 0; i < battery.size(); i++){
            battery[i] = max(0, battery[i] - reducer);

            if(battery[i] > 0){
                reducer++;
                tested++;
            }
        }

        return tested;
    }
};
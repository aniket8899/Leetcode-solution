class Solution {
public:
    bool isPossible(vector<int>& nums) {

        unordered_map<int,int> mp;

        for(auto n : nums) {
            mp[n]++;
        }

        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto n : nums) {
            pq.push(n);
        }

        unordered_map<int,int> end;

        while(!pq.empty()) {

            int top = pq.top();
            pq.pop();

            if(mp[top] == 0)
                continue;

            // Case 1: Extend an existing sequence
            if(end[top - 1] > 0) {

                end[top - 1]--;
                end[top]++;

                mp[top]--;
            }

            // Case 2: Start a new sequence
            else if(mp[top + 1] > 0 && mp[top + 2] > 0) {

                mp[top]--;
                mp[top + 1]--;
                mp[top + 2]--;

                end[top + 2]++;
            }

            // Cannot use this number
            else {
                return false;
            }
        }

        return true;
    }
};
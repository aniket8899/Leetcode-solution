class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqmap;
        for (auto num : nums) {
            freqmap[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        for (auto it : freqmap) {
            pq.push({it.second, it.first});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> ans;

        while (!pq.empty()) {
            // auto top = pq.top();
            pair<int,int>top=pq.top();
            pq.pop();
            ans.push_back(top.second);
        }
        return ans;
    }
};
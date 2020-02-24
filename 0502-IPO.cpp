// max/min heap

class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        
        auto lessCost = [](pair<int, int> p1, pair<int, int> p2) {
            return p1.second > p2.second;
        };

        auto moreProf = [](pair<int, int> p1, pair<int, int> p2) {
            return p1.first < p2.first;
        };
        
        priority_queue< pair<int, int>, vector< pair<int, int> >, decltype(moreProf) > maxProf(moreProf);
        priority_queue< pair<int, int>, vector< pair<int, int> >, decltype(lessCost) > minCost(lessCost);
        
        size_t len = Profits.size();
        
        for (int i = 0; i < len; i++) {
            minCost.push(make_pair(Profits[i], Capital[i]));;
        }
        
        for (int i = 0; i < k; i++) {
            while (!minCost.empty() && minCost.top().second <= W) {
                maxProf.push(minCost.top());
                minCost.pop();
            }
            if (maxProf.empty()) {
                break;
            }
            W += maxProf.top().first;
            maxProf.pop();
        }
        return W;
    }
};

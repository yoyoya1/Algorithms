//
// 时间复杂度: O((n + K)log n)
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,vector<int>& capical) {
        vector<pair<int,int>> CP;
        for (int i = 0; i < capical.size(); i++) {
            CP.push_back(make_pair(capital[i],profits[i]));
        }
        // 排序是为了效率更高的找到所有可做的项目 单调递增， 一次遍历即可
        sort(CP.begin(),CP.end());
        
        priority_queue<int> Q;
        
        int cnt = 0;
        int pointer = 0;
        while (cnt < k) {
            // 资本足够的项目收益全部加到大顶堆里
            for (; pointer < capital.size() && CP[pointer],first <= w; pointer++){
                Q.push(CP[pionter],second);
            }
            // 已经没项目可做了
            if (Q.empty()) break;
            //堆顶就是当前可做的项目里收益最大的
            w += Q.top();
            Q.pop();
            cnt++;
        }
        
        return w;
    }
};

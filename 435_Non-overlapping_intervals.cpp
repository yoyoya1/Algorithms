// Dynamic Programming 
// 无后效性
// 最优子结构
// 令f_i表示[以区间i为最后一个区间，可以选出的区间数量的最大值]
// 第i段可选去区间数量的最大值只能由某几个状态而得到 比如：第二段可选区间数量的最大值由0 ，1 段可选区间的最大值来得到而得到
// 时间复杂度为 O(n^2) ,空间复杂度为O(n) 
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals){
        if (intervals.empty()){
            return 0;
        }
        sort(intervals.begin(),intervals.end(),[](const auto &u,const auto& v){
                return u[0] < v[0];
        });
    
        int n = intervals.size();
        vector<int> f(n,1); 
        for (int i = 1; i < n; ++i){
            for (int j = 0; j < i; ++j){
                if (intervals[j][1] <= intervals[i][0]) {
                    f[i] = max(f[i], f[j] + 1);
                }
            }
        }
        return n - *max_element(f.begin(),f.end());
    }
};


// 贪心
// 关于为什么要按照右边排序，就和你一天有很多次会议，而你需要去参加更多的会议，你就要使得每个会议的时间尽可能的短，使得结束的时间尽可能的去短
// 时间复杂度为 O(nlog n) ,空间复杂度为O(log n),排序所需要用到的栈空间
class Solution{
public:
    int eraseOverlapIntervalsls(vector<vector<int>>& intervals) {
        if (intervals.empty()){
            return 0;
        }
        sort(intervals.begin(),intervals.end(),[](const auto& u,const auto& v){
            return u[1] < v[1];
        });
        
        int right = intervals[0][1];
        int ans = 1;
        int n = intervals.size();
        
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] >= right) {
                ans++;
                right = intervals[i][0];
            }
        }
        return n - ans;
    
    }
};

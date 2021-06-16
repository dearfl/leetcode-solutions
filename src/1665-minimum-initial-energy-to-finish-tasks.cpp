// You are given an array tasks where tasks[i] = [actuali, minimumi]:
//
// - actual_i is the actual amount of energy you spend to finish the ith task.
// - minimum_i is the minimum amount of energy you require to begin the ith
// task.
// For example, if the task is [10, 12] and your current energy is 11, you
// cannot start this task. However, if your current energy is 13, you can
// complete this task, and your energy will be 3 after finishing it.
//
// You can finish the tasks in any order you like.
//
// Return the minimum initial amount of energy you will need to finish all the
// tasks.
//

// 被这题整麻了，猜出了要根据minimum - actual排序，
// 然而使用sort一直超时，看了数据之后发现全都是[1,10000]
// 猜测是因为这样影响了排序算法的效率
// 改成stable_sort之后才勉强通过
// 然而还是没证明为什么这样做是充分的 
class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        stable_sort(tasks.begin(), tasks.end(), [](auto v1, auto v2) { return v1[1] - v1[0] < v2[1] - v2[0]; });
        int res = 0;
        for (const auto &vec : tasks) {
            res = max(res + vec[0], vec[1]);
        }
        return res;
    }
};

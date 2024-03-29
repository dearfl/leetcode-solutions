// A new online video game has been released, and in this video game, there are 15-minute rounds scheduled every quarter-hour period. This means that at HH:00, HH:15, HH:30 and HH:45, a new round starts, where HH represents an integer number from 00 to 23. A 24-hour clock is used, so the earliest time in the day is 00:00 and the latest is 23:59.
//
// Given two strings startTime and finishTime in the format "HH:MM" representing the exact time you started and finished playing the game, respectively, calculate the number of full rounds that you played during your game session.
//
// For example, if startTime = "05:20" and finishTime = "05:59" this means you played only one full round from 05:30 to 05:45. You did not play the full round from 05:15 to 05:30 because you started after the round began, and you did not play the full round from 05:45 to 06:00 because you stopped before the round ended.
// If finishTime is earlier than startTime, this means you have played overnight (from startTime to the midnight and from midnight to finishTime).
//
// Return the number of full rounds that you have played if you had started playing at startTime and finished at finishTime.
//

class Solution {
public:
    int numberOfRounds(string startTime, string finishTime) {
        int sh = atoi(startTime.substr(0, 2).c_str()), sm = atoi(startTime.substr(3).c_str());
        int fh = atoi(finishTime.substr(0, 2).c_str()), fm = atoi(finishTime.substr(3).c_str());
        if (sh > fh || (sh == fh && sm > fm)) {
            fh += 24;
        }
        return (fh - sh) * 4 + max(0, fm / 15 - (sm + 14) / 15);
    }
};

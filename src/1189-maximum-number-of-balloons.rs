/*
Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

You can use each character in text at most once. Return the maximum number of instances that can be formed.

Example 1:
    Input: text = "nlaebolko"
    Output: 1
Example 2:
    Input: text = "loonbalxballpoon"
    Output: 2
Example 3:
    Input: text = "leetcode"
    Output: 0

Constraints:
    1 <= text.length <= 10^4
    text consists of lower case English letters only.
*/

impl Solution {
    pub fn max_number_of_balloons(text: String) -> i32 {
        let mut bc = 0;
        let mut ac = 0;
        let mut lc = 0;
        let mut oc = 0;
        let mut nc = 0;
        for c in text.chars() {
            match c {
                'b' => bc += 1,
                'a' => ac += 1,
                'l' => lc += 1,
                'o' => oc += 1,
                'n' => nc += 1,
                _ => {}
            }
        }
        *[bc, ac, lc / 2, oc / 2, nc].into_iter().min().unwrap()
    }
}

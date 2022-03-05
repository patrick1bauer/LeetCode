/**
 * Patrick Bauer
 * Leetcode
 * 2160. Minimum Sum Of Four Digit Number After Splitting Digits
 * https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/
 */

/*
You are given a positive integer num consisting of exactly four digits. Split num into two new
integers new1 and new2 by using the digits found in num. Leading zeros are allowed in new1 and
new2, and all the digits found in num must be used.

    For example, given num = 2932, you have the following digits: two 2's, one 9 and one 3. Some of
    the possible pairs [new1, new2] are [22, 93], [23, 92], [223, 9] and [2, 329].

Return the minimum possible sum of new1 and new2.

Example 1:
    Input: num = 2932
    Output: 52
    Explanation: Some possible pairs [new1, new2] are [29, 23], [223, 9], etc.
        The minimum sum can be obtained by the pair [29, 23]: 29 + 23 = 52.

Example 2:
    Input: num = 4009
    Output: 13
    Explanation: Some possible pairs [new1, new2] are [0, 49], [490, 0], etc. 
        The minimum sum can be obtained by the pair [4, 9]: 4 + 9 = 13.
*/

class Solution
{
public:
    int minimumSum(int num)
    {
        // Create a list to hold our digits.
        std::vector<int> digit_list;

        // Add our digits to the list.
        for (int i = 0; i < 4; i++)
        {
            digit_list.push_back(num % 10);
            num = num / 10;
        }

        // Sort the list from smallest to largest.
        std::sort(digit_list.begin(), digit_list.end());

        // First two smallest numbers are the ten's place of our two numbers to sum.
        int num1 = digit_list[0] * 10;
        int num2 = digit_list[1] * 10;

        // Second two numbers are the one's place of our numbers to sum.
        num1 += digit_list[2];
        num2 += digit_list[3];

        // Return the sum of the new numbers.
        return num1 + num2;
    }
};
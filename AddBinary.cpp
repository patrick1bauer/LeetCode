/**
 * Patrick Bauer
 * Leetcode
 * 67. Add Binary
 * https://leetcode.com/problems/add-binary/
 */

/*
 * Given two binary strings a and b, return their sum as a binary string.
 * 
 * Example 1:
 *    Input: a = "11", b = "1"
 *    Output: "100"
 *
 * Example 2:
 *    Input: a = "1010", b = "1011"
 *    Output: "10101"
 *
 * Constraints:
 *     1 <= a.length, b.length <= 10^4
 *     a and b consist only of '0' or '1' characters.
 *     Each string does not contain leading zeros except for the zero itself.
 */

class Solution
{
public:
    string addBinary(string a, string b)
    {
        // Get lengths of each string.
        int aLength = a.length() - 1;
        int bLength = b.length() - 1;

        // Create a string to hold our answer.
        std::string answer;

        // Create an int to hold our carry.
        int carry = 0;

        // While there are still digits in either a or b, or there is a carry value, continue.
        while (aLength >= 0 || bLength >= 0 || carry)
        {
            // If there are still digits in a, then add the least significant digit value to the carry and decriment the length of a.
            if (aLength >= 0)
            {
                carry += a[aLength] - '0'; 
                aLength--;
            }

            // If there are still digits in b, then add the least significant digit value to the carry and decriment the length of b.
            if (bLength >= 0)
            {
                carry += b[bLength] - '0';
                bLength--;
            }

            // Append the gathered sum thus far moded by 2 to the end of our answer.
            answer += (carry%2 + '0');

            // Calculate new carry.
            carry = carry / 2;
        }

        // Since we added digits to the end of our answer, we need to reverse our answer.
        reverse(answer.begin(), answer.end());

        // SEND IT.
        return answer;
    }
};
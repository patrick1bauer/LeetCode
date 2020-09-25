/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

class ListTwoNumbers
{
    public ListNode addTwoNumbers(ListNode l1, ListNode l2)
    {
        int num1 = 0;
        int num2 = 0;
        
        ListNode temp = l1;
        
        int exp = 0;
        
        while(temp != null)
        {
            num1 += temp.val * (Math.pow(10, exp));
            exp++;
            temp = temp.next;
        }
        
        temp = l2;
        exp = 0;
        
        while(temp != null)
        {
            num2 += temp.val * (Math.pow(10, exp));
            exp++;
            temp = temp.next;
        }
        
        int answer = num1 + num2;
        
        exp = -1;
        int number = answer;
        
        while(number > 1)
        {
            number = number / 10;
            exp++;
        }
        
        ListNode head = new ListNode();
        temp = head;
        
        while(exp != -1)
        {
            int digit = answer / (int)(Math.pow(10, exp));
            answer = answer - (digit * (int)Math.pow(10, exp));
            ListNode newNode = new ListNode(digit);
            newNode.next = head.next;
            head.next = newNode;
            exp--;
        }
        
        return head.next;
    }
}

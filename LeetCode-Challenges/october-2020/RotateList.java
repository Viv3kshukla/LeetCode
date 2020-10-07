import java.util.*;
import java.util.function.Consumer;
import java.util.function.Function;
import java.util.stream.Collectors;
import java.io.*;

class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }
}

public class RotateList {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();
        Function<String, Integer> toInt = (x) -> {
            try {
                return Integer.valueOf(x);
            } catch (NumberFormatException e) {
                return null;
            }
        };
        List<Integer> values = Arrays.asList(input.split(",")).stream().map(toInt).collect(Collectors.toList());
        Collections.reverse(values);
        ListNode head = null;
        for (Integer i : values) {
            head = appendNode(head, i.intValue());
        }
        printList(head);
        input = br.readLine();
        int k = Integer.parseInt(input);
        head = rotateRight(head, k);
        printList(head);
    }

    public static ListNode rotateRight(ListNode head, int k) {
        if (head == null)
            return head;
        int llen = llength(head);
        k = k % llen;
        ListNode temp1 = head;
        ListNode temp2 = head;
        for (int i = 0; i < k; i++) {
            temp1 = temp1.next;
        }
        while (temp1.next != null) {
            temp1 = temp1.next;
            temp2 = temp2.next;
        }
        temp1.next = head;
        head = temp2.next;
        temp2.next = null;
        return head;
    }

    public static int llength(ListNode head) {
        ListNode temp = head;
        int counter = 0;
        while (temp != null) {
            temp = temp.next;
            counter++;
        }
        return counter;
    }

    public static ListNode appendNode(ListNode head, int x) {
        if (head == null)
            return new ListNode(x);
        else {
            ListNode node = new ListNode(x);
            node.next = head;
            return node;
        }
    }

    public static void printList(ListNode head) {
        ListNode temp = head;
        while (temp != null) {
            System.out.print(temp.val + " ");
            temp = temp.next;
        }
        System.out.println();
    }
}
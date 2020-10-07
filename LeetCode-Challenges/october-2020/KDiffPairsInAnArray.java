import java.util.*;
import java.io.*;

public class KDiffPairsInAnArray {
    public static void main(String args[]) {
        int[] nums = new int[] { -1, -2, -3 };
        int k = 1;
        int answer = findPairs(nums, k);
        System.out.println(answer);
    }

    public static int findPairs(int[] nums, int k) {
        int count = 0, i = 0, j = 1;
        Arrays.sort(nums);
        while (j < nums.length) {
            if (nums[j] - nums[i] == k) {
                count++;
                while (j < nums.length && (nums[j] - nums[i] == k))
                    j++;
            } else if (nums[j] - nums[i] < k)
                j++;
            else {
                i++;
                while (i >= j)
                    j++;
            }
        }
        return count;
    }
}
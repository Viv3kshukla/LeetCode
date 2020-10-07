import java.util.*;
import java.io.*;

public class CombinationSum {
    public static void main(String args[]) {
        int[] candidates = new int[] { 2, 3, 5 };
        int target = 8;
        List<List<Integer>> answer = combinationSum(candidates, target);
        System.out.println(answer);
    }

    public static List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(candidates);
        backtrack(res, new ArrayList<Integer>(), candidates, 0, target);
        return res;
    }

    public static void backtrack(List<List<Integer>> llist, List<Integer> list, int[] candidates, int start,
            int target) {
        if (target == 0) {
            llist.add(new ArrayList<Integer>(list));
            return;
        }
        for (int i = start; i < candidates.length; i++) {
            if (target - candidates[i] >= 0) {
                list.add(candidates[i]);
                backtrack(llist, list, candidates, i, target - candidates[i]);
                list.remove(list.size() - 1);
            } else {
                break;
            }
        }
    }

}
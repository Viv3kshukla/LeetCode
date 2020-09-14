import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.function.*;
import java.util.*;
import java.util.stream.Collectors;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int val) {
        this.val = val;
    }
}

public class DeepestLeavesSum {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();
        Function<String, TreeNode> toTreeNode = (x) -> {
            try {
                int nval = Integer.parseInt(x);
                return new TreeNode(nval);
            } catch (NumberFormatException e) {
                return null;
            }
        };
        List<TreeNode> tree = Arrays.asList(input.split(",")).stream().map(toTreeNode).collect(Collectors.toList());
        TreeNode root = tree.get(0);
        for (int i = 0; 2 * i + 2 < tree.size(); i++) {
            if (tree.get(i) == null)
                continue;
            tree.get(i).left = tree.get(2 * i + 1);
            tree.get(i).right = tree.get(2 * i + 2);
        }
        System.out.println(deepestLeavesSum(root));
    }

    public static int deepestLeavesSum(TreeNode root) {
        if (root == null)
            return 0;
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        q.add(root);
        int answer = 0;
        while (!q.isEmpty()) {
            int sum = 0;
            int size = q.size();
            TreeNode node;
            for (int i = 0; i < size; i++) {
                node = q.poll();
                if (node.left != null) {
                    q.add(node.left);
                }
                if (node.right != null) {
                    q.add((node.right));
                }
                sum += node.val;
            }
            answer = Math.max(answer, sum);
        }
        return answer;
    }
}
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
        this.left = null;
        this.right = null;
    }

    @Override
    public String toString() {
        return "TestClass [val=" + val + ", left=" + this.left + ", right=" + this.right + "]";
    }

}

public class SumOfNodesWithEvenValuedGrandparent {

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
        System.out.println(sumEvenGrandparent(root));
    }

    public static int sumEvenGrandparent(TreeNode root) {
        return findSum(root, null);
    }

    public static int findSum(TreeNode parent, TreeNode grandparent) {
        if (parent == null)
            return 0;
        int sum = 0;
        if (grandparent != null && grandparent.val % 2 == 0) {
            if (parent.left != null)
                sum += parent.left.val;
            if (parent.right != null)
                sum += parent.right.val;
        }
        sum += findSum(parent.right, parent) + findSum(parent.left, parent);
        return sum;
    }

}
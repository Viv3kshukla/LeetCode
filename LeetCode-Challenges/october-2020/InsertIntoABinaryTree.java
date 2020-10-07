import java.util.*;
import java.util.function.Function;
import java.util.stream.Collectors;
import java.io.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }
}

public class InsertIntoABinaryTree {
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
            tree.get(i).left = tree.get(2 * i + 1);
            tree.get(i).right = tree.get(2 * i + 2);
        }
        System.out.println(insertIntoBST(root, 5));
    }

    public static TreeNode insertIntoBST(TreeNode root, int val) {
        if (root == null)
            return new TreeNode(val);
        if (val < root.val) {
            root.left = insertIntoBST(root.left, val);
        } else {
            root.right = insertIntoBST(root.right, val);
        }
        return root;
    }

}
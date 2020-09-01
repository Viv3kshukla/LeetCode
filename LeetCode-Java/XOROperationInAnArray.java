import java.util.*;
import java.io.*;

public class XOROperationInAnArray {

    public static void main(String args[]) {
        int n = 2;
        int start = 4;
        System.out.println(xorOperation(n, start));
    }

    public static int xorOperation(int n, int start) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = ans ^ (start + 2 * i);
        }
        return ans;
    }
}
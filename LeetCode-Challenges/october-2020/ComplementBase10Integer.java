import java.util.*;
import java.io.*;

public class ComplementBase10Integer {
    public static void main(String args[]) {
        int N = 0;
        System.out.println(bitwiseComplement(N));
    }

    public static int bitwiseComplement(int N) {
        String binary = Integer.toBinaryString(N);
        int ans = 0;
        for (int i = 0; i < binary.length(); i++) {
            if (binary.charAt(i) == '0') {
                ans = 2 * ans + 1;
            } else {
                ans = ans * 2;
            }
        }
        return ans;
    }
}
import java.util.*;
import java.io.*;

public class RemoveCoveredIntervals {
    public static void main(String args[]) {
        int[][] intervals = { { 3, 10 }, { 4, 10 }, { 5, 12 } };
        int answer = removeCoveredIntervals(intervals);
        Arrays.asList(intervals).forEach((int[] x) -> {
            for (int u : x) {
                System.out.print(u + " ");
            }
            System.out.println();
        });
        System.out.println("answer : " + answer);
    }

    public static int removeCoveredIntervals(int[][] intervals) {
        Arrays.sort(intervals, (int[] x, int[] y) -> {
            return x[0] == y[0] ? (y[1] - x[1]) : (x[0] - y[0]);
        });
        int k = 0, i = 0, count = 1;
        while (i < intervals.length) {
            if (i < intervals.length && intervals[k][1] < intervals[i][1]) {
                count++;
                k = i;
            }
            i++;
        }
        return count;
    }
}
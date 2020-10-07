import java.util.*;
import java.io.*;

class RecentCounter {

    List<Integer> list;

    public RecentCounter() {
        list = new ArrayList<Integer>();
    }

    public int ping(int t) {
        list.add(t);
        int l = binarySearch(t - 3000);
        int r = list.size();
        return (r - l);
    }

    private int binarySearch(int x) {
        int low = 0;
        int high = list.size();
        int result = 0;
        int mid;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (list.get(mid) == x)
                return mid;
            else if (list.get(mid) < x) {
                low = mid + 1;
                result = mid + 1;
            } else {
                high = mid - 1;
                result = mid;
            }
        }
        return result;
    }
}

public class NumberOfRecentCalls {
    public static void main(String args[]) {
        RecentCounter res = new RecentCounter();

    }
}
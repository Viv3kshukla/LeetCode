import java.util.*;
import java.io.*;

public class DistanceBetweenBusStops {

    public int distanceBetweenBusStops(int[] distance, int start, int destination) {
        int clk[] = new int[distance.length];
        clk[0] = 0;
        for (int i = 1; i < distance.length; i++) {
            clk[i] = clk[i - 1] + distance[i - 1];
        }
        sum = clk[distance.length - 1] + distance[distance.length - 1];
        int temp = Math.abs(clk[start] - clk[destination]);
        int ans = Math.min(temp, Math.abs(sum - temp));
    }
}
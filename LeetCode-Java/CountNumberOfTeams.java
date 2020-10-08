import java.util.*;
import java.io.*;

public class CountNumberOfTeams {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] rating = Arrays.stream(br.readLine().trim().split(",")).mapToInt(x -> Integer.valueOf(x)).toArray();
        int answer = numTeams(rating);
        System.out.println(answer);
    }

    public static int numTeams(int[] rating) {
        int[] lesser = new int[rating.length];
        int[] greater = new int[rating.length];
        Arrays.fill(lesser, 0);
        Arrays.fill(lesser, 0);
        int answer = 0;
        for (int i = 0; i < rating.length; i++) {
            for (int j = i + 1; j < rating.length; j++) {
                if (rating[i] > rating[j])
                    lesser[i]++;
                else
                    greater[i]++;
            }
        }

        for (int i = 0; i < rating.length; i++) {
            for (int j = i + 1; j < rating.length; j++) {
                if (rating[i] < rating[j]) {
                    answer += greater[j];
                }
            }
        }

        for (int i = 0; i < rating.length; i++) {
            for (int j = i + 1; j < rating.length; j++) {
                if (rating[i] > rating[j]) {
                    answer += lesser[j];
                }
            }
        }
        return answer;
    }
}
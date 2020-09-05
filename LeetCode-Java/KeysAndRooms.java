import java.util.*;
import java.io.*;

public class KeysAndRooms {

    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        boolean[] visited = new boolean[rooms.size()];
        dfs(rooms, 0, visited);
        for (int i = 0; i < rooms.size(); i++) {
            if (visited[i] == false) {
                return false;
            }
        }
        return true;
    }

    public void dfs(List<List<Integer>> rooms, Integer s, boolean[] visited) {
        visited[s] = true;
        for (Integer i : rooms.get(s)) {
            if (visited[i] == false) {
                dfs(rooms, i, visited);
            }
        }
    }
}
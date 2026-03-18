import java.util.*;
import java.io.*;

public class Main {
    static int[] parent;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int[][] edges = new int[M + 1][3]; // {u, v, type}

        for (int i = 0; i <= M; i++) {
            st = new StringTokenizer(br.readLine());
            edges[i][0] = Integer.parseInt(st.nextToken());
            edges[i][1] = Integer.parseInt(st.nextToken());
            edges[i][2] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(edges, (a, b) -> Integer.compare(a[2], b[2]));
        long worstK = kruskal(N, edges);

        Arrays.sort(edges, (a, b) -> Integer.compare(b[2], a[2]));
        long bestK = kruskal(N, edges);

        System.out.println((worstK * worstK) - (bestK * bestK));
    }

    private static int kruskal(int n, int[][] edges) {
        parent = new int[n + 1];
        for (int i = 0; i <= n; i++) parent[i] = i;

        int uphillCount = 0;
        int edgesUsed = 0;

        for (int[] edge : edges) {
            if (union(edge[0], edge[1])) {
                if (edge[2] == 0) {
                    uphillCount++;
                }
                edgesUsed++;
                if (edgesUsed == n) break;
            }
        }
        return uphillCount;
    }

    private static int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    private static boolean union(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            parent[y] = x;
            return true;
        }
        return false;
    }
}
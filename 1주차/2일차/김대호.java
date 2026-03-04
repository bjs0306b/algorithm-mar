import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
    static int[] parent;
    static boolean[] hasPlant;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int M = sc.nextInt();
        int K = sc.nextInt();

        parent = new int[N + 1];
        hasPlant = new boolean[N + 1];

        for (int i = 1; i <= N; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < K; i++) {
            hasPlant[sc.nextInt()] = true;
        }

        int[][] edges = new int[M][3];
        for (int i = 0; i < M; i++) {
            edges[i][0] = sc.nextInt();
            edges[i][1] = sc.nextInt();
            edges[i][2] = sc.nextInt();
        }

        Arrays.sort(edges, Comparator.comparingInt(a -> a[2]));

        long minCost = 0;

        // 크루스칼 알고리즘
        for (int i = 0; i < M; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            if (union(u, v)) {
                minCost += w;
            }
        }

        System.out.println(minCost);
    }

    public static int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    public static boolean union(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);

        if (rootA == rootB) return false;

        if (hasPlant[rootA] && hasPlant[rootB]) return false;

        parent[rootB] = rootA;
        if (hasPlant[rootB]) {
            hasPlant[rootA] = true;
        }

        return true;
    }
}
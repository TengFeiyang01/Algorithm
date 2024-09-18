import java.util.*;

class Info {
    int val, id;

    Info(int val, int id) {
        this.val = val;
        this.id = id;
    }

    // Custom comparator to sort Info objects
    static class InfoComparator implements Comparator<Info> {
        @Override
        public int compare(Info a, Info b) {
            if (a.val == b.val) return a.id - b.id;
            return b.val - a.val;
        }
    }
}

public class Main {
    static final int INF = 0x3f3f3f3f; // A large number to simulate infinity

    public static void solve() {
        Scanner scanner = new Scanner(System.in);
        int m = scanner.nextInt();
        int id = scanner.nextInt();
        int n = scanner.nextInt();
        int k = scanner.nextInt();

        int[][] g = new int[m][m];
        int[][] d = new int[m][m];

        // Initialize the distance matrix with INF and graph matrix with 0
        for (int[] row : d) Arrays.fill(row, INF);
        for (int i = 0; i < m; i++) {
            d[i][i] = 0; // Distance to self is zero
        }

        // Read the edges
        for (int i = 0; i < k; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            int w = scanner.nextInt();
            g[u][v] = g[v][u] = w;
            d[u][v] = d[v][u] = 1; // Direct connection implies a distance of 1
        }

        // Floyd-Warshall algorithm to find shortest paths and sum of familiarity scores
        for (int p = 0; p < m; p++) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < m; j++) {
                    if (g[i][p] > 0 && g[p][j] > 0 && d[i][j] > d[i][p] + d[p][j]) {
                        d[i][j] = d[i][p] + d[p][j];
                        g[i][j] = g[i][p] + g[p][j];
                    }
                }
            }
        }

        ArrayList<Info> results = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            if (d[id][i] == n) {
                results.add(new Info(g[id][i], i));
            }
        }

        Collections.sort(results, new Info.InfoComparator());
        if (results.isEmpty()) {
            System.out.println(-1);
            return;
        }
        for (Info result : results) {
            System.out.print(result.id + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while (t-- > 0) {
            solve();
        }
        scanner.close();
    }
}

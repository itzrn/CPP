public class DataConsistency {
    
    public static int solve(int N, int K, int[] arr) {

        int oddCount = 0;
        int evenCount = 0;
        int maxSeparations = 0;
        int totalCost = 0;

        for (int i = 0; i < N; i++) {
            if (arr[i] % 2 == 0) {
                evenCount++;
            } else {
                oddCount++;
            }

            if (oddCount == evenCount && i < N - 1) {
                int cost = Math.abs(arr[i] - arr[i + 1]);
                if (totalCost + cost <= K) {
                    totalCost += cost;
                    maxSeparations++;
                }
            }
        }

        return maxSeparations;
    }

    public static void main(String[] args) {
        int N = 4;
        int K = 10;
        int[] arr = {1, 3, 2, 4};

        int result = solve(N, K, arr);
        System.out.println("Maximum number of separations: " + result);  // Output should match the requirement
    }
}
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the first line and split it into a list of strings
        String[] s = scanner.nextLine().split(" ");
        
        // Read the second line and split it into a list of strings
        String[] t = scanner.nextLine().split(" ");
        
        // Create a map to store the words and their indices
        Map<String, Integer> id = new HashMap<>();
        for (int i = 0; i < t.length; i++) {
            id.put(t[i], i);
        }
        
        // Create a list to store the result
        List<Object> ans = new ArrayList<>();
        for (String word : s) {
            if (id.containsKey(word)) {
                ans.add(id.get(word));
            } else {
                ans.add(word);
            }
        }
        
        // Print the result
        for (Object element : ans) {
            System.out.print(element + " ");
        }
    }
}

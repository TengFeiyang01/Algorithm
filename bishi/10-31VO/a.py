import java.util.Arrays;

public class Main {
    // 荷兰国旗问题的实现：将数组分为 1、2、3 三部分
    public static void dutchNationalFlag(int[] arr) {
        int low = 0;  // 指向小于 2 的区域
        int mid = 0;  // 当前遍历元素
        int high = arr.length - 1;  // 指向大于 2 的区域

        // 遍历数组进行分区
        while (mid <= high) {
            if (arr[mid] == 1) {
                // 交换 arr[low] 和 arr[mid]
                int temp = arr[low];
                arr[low] = arr[mid];
                arr[mid] = temp;
                low++;
                mid++;
            } else if (arr[mid] == 2) {
                // 等于 2 的元素保持不变，继续移动 mid
                mid++;
            } else if (arr[mid] == 3) {
                // 交换 arr[mid] 和 arr[high]
                int temp = arr[mid];
                arr[mid] = arr[high];
                arr[high] = temp;
                high--;
            }
        }
    }

    public static void main(String[] args) {
        int[] arr = {2, 1, 3, 2, 1, 3, 2, 1};

        System.out.println("原数组: " + Arrays.toString(arr));

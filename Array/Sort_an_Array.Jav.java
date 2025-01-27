class Solution {
    static public int[] sortArray(int[] nums) {
        int arr[] = new int[nums.length];
        arr = mergeSort(nums, 0, nums.length - 1);
        return arr;
    }

    static int[] merge(int[] left, int[] right) {
        int arr[] = new int[left.length + right.length];
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < left.length && j < right.length) {
            if (left[i] <= right[j]) {
                arr[k] = left[i];
                i++;
            } else {
                arr[k] = right[j];
                j++;
            }
            k++;
        }

        while (i < left.length) {
            arr[k] = left[i];
            i++;
            k++;
        }

        while (j < right.length) {
            arr[k] = right[j];
            j++;
            k++;
        }
        return arr;
    }

    static int[] mergeSort(int arr[], int start, int end) {
        if (start >= end) {
            return new int[] { arr[end] };
        }
        int mid = start + (end - start) / 2;
        int[] left = mergeSort(arr, start, mid);
        int[] right = mergeSort(arr, mid + 1, end);

        return merge(left, right);
    }
}

// Solution for Combination Sum in Java 
// This file contains the code for the problem: Combination Sum 
// Topic: Array 
// Language: Java 
 
// Your code here... 
class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        Arrays.sort(candidates);
        return combinationSumHelper(candidates, target, 0);
    }

    private List<List<Integer>> combinationSumHelper(int[] candidates, int target, int start) {
        List<List<Integer>> result = new ArrayList<>();

        for (int i = start; i < candidates.length; i++) {
            if (candidates[i] == target) {
                List<Integer> list = new ArrayList<>();
                list.add(candidates[i]);
                result.add(list);
            } else if (candidates[i] < target) {
                List<List<Integer>> combinations = combinationSumHelper(candidates, target - candidates[i], i);
                for (List<Integer> combination : combinations) {
                    List<Integer> list = new ArrayList<>();
                    list.add(candidates[i]);
                    list.addAll(combination);
                    result.add(list);
                }
            } else {
                break;
            }

            while (i < candidates.length - 1 && candidates[i] == candidates[i + 1]) {
                i++;
            }
        }

        return result;
    }
}
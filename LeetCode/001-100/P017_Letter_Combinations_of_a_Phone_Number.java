/*
https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/?goto=old

同类题目 P17

按下九宫格的数字，求所有可能的输出
*/

import java.util.List;
import java.util.ArrayList;

class Solution {
    private List<String> combinations = new ArrayList<>();
    private List<String> keyboard = new ArrayList<>();

    private void init(char firstChar) {
        keyboard.add(" ");
        keyboard.add("");
        keyboard.add("abc");
        keyboard.add("def");
        keyboard.add("ghi");
        keyboard.add("jkl");
        keyboard.add("mno");
        keyboard.add("pqrs");
        keyboard.add("tuv");
        keyboard.add("wxyz");

        int firstDigit = firstChar - '0';
        String keyList = keyboard.get(firstDigit);
        for ( int i = 0; i < keyList.length(); i++ ) {
            combinations.add(String.valueOf(keyList.charAt(i)));
        }
    }

    public List<String> letterCombinations (String digits) {
        int length = digits.length();
        if ( length < 1 ) {
            return combinations;
        }

        int i = 0;
        init(digits.charAt(i));

        for ( i = 1; i < digits.length(); i++ ) {
            int digit = digits.charAt(i) - '0';
            String keyList = keyboard.get(digit);
            List<String> newCombinations = new ArrayList<>();
            for ( String prevStr : combinations ) {
                for ( int j = 0; j < keyList.length(); j++ ) {
                    String newStr = prevStr + keyList.charAt(j);
                    newCombinations.add(newStr);
                }
            }
            combinations = newCombinations;
        }
        return combinations;
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        s.letterCombinations("");
        s.letterCombinations("2");
        s.letterCombinations("23");
    }
}
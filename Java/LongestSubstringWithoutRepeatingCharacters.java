import java.util.HashSet;

public class LongestSubstringWithoutRepeatingCharacters {
    public static void main(String[] args) {

        String s = "abdfca";
        HashSet<Character> hashSet = new HashSet();
        int length = s.length();
        int max = 0;
        char tempChar;

        for (int i = 0; i < length; i++) {

            for (int j = i; j < length; j++) {

                tempChar = s.charAt(j);

                if (!(hashSet.contains(tempChar))) {
                    hashSet.add(tempChar);
                    max = Math.max(max, hashSet.size());
                } else {
                    break;
                }
            }
            hashSet.clear();
        }
        System.out.println("Length of Longest Substring Without Repeating Characters is: " + max);
    }
}
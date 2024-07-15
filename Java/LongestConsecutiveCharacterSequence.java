public class LongestConsecutiveCharacterSequence {
    public static void main(String[] args) {
        int maxLength = 0, currentLength = 0;
        String s = "";
        char previous = ' ';
        char current;

        for (int i = 0; i < s.length(); i++) {
            current = s.charAt(i);
            if(previous == current){
                currentLength++;
                maxLength = Math.max(maxLength, currentLength);
            }
            else{
                previous = current;
                currentLength = 1;
            }
        }
        System.out.println(maxLength);
    }

}
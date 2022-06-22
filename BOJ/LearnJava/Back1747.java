package BOJ.LearnJava;

public class Back1747 {
    final int MAX = 1004000;

    public boolean isPalindrom(int inputData){
        String str = Integer.toString(inputData);
        for(int i = 0 ; i < str.length(); i++){
            if(str.charAt(i) != str.charAt(str.length() - i - 1)){
                return false; 
            }
        }
        return true;
    }
    public static void main(String[] args){
        int arr[];
        for
    }
}

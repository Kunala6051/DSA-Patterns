class Solution {
    public long helper(String s, int i, long ans, int sign){
        if(i==s.length() || !Character.isDigit(s.charAt(i))) return sign * ans;

        char c = s.charAt(i);
        int t = c - '0';

        ans = (ans*10) + t;
        i++;

        if (sign * ans >= Integer.MAX_VALUE) return Integer.MAX_VALUE;
        if (sign * ans <= Integer.MIN_VALUE) return sign * Integer.MIN_VALUE;
        
        return helper(s, i, ans, sign);
        
    }
    public int myAtoi(String s) {
        int n = s.length();
        int i=0;
        int sign = 1;

        for(int j=0; j<n; j++){
            if(s.charAt(j)!=' ') {
                break;
            }
            i++;
        }

        if(i<n && s.charAt(i)=='-'){ 
            sign = -1;
            i++;
        } else if(i<n && s.charAt(i)=='+'){ 
            i++;
        }

        for(int j=i; j<n; j++){
            if(s.charAt(j)!='0') break;
            i++;
        }

        return (int) helper(s, i, 0, sign);
        
    }
}
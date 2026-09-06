import java.util.*;

class Solution {
    public static void insert(Stack<Integer> st, int t){
        if(st.isEmpty()){
            st.push(t);
            return;
        }
        int v = st.peek();
        st.pop();
        insert(st, t);
        st.push(v);
    }
    public static void reverseStack(Stack<Integer> st) {
        // code here
        if(st.empty()) return;
        int t = st.peek();
        st.pop();
        reverseStack(st);
        insert(st, t);
    }
}
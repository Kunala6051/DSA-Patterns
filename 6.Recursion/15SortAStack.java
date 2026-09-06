import java.util.*;


// Implement a Stack Sorting Algorithm using Recursion
class Solution {
    public void insert (Stack<Integer> st, int t){
        if(st.isEmpty() || st.peek()<=t){
            st.push(t);
            return;
        }
        int v = st.peek();
        st.pop();
        insert(st, t);
        st.push(v);
    }
    public void sortStack(Stack<Integer> st) {
        // code here
        if(st.isEmpty()) return;
        int t = st.peek();
        st.pop();
        sortStack(st);
        insert(st, t);
    }
}
class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        int i = 0, j = 0;
        vector<int> arr;

        while(i < a.size() && j < b.size()){
            int val;

            if(a[i] <= b[j]){
                val = a[i];
                i++;
            } else {
                val = b[j];
                j++;
            }

            // avoid duplicates
            if(arr.empty() || arr.back() != val){
                arr.push_back(val);
            }
        }

        while(i < a.size()){
            if(arr.empty() || arr.back() != a[i]){
                arr.push_back(a[i]);
            }
            i++;
        }

        while(j < b.size()){
            if(arr.empty() || arr.back() != b[j]){
                arr.push_back(b[j]);
            }
            j++;
        }

        return arr;
    }
};
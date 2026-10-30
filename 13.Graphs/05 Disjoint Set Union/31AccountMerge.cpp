/*
APPROACH: DISJOINT SET UNION (DSU)

// Leetcode 721. Accounts Merge

1. Treat each account as a node in DSU.
   If two accounts share an email, they belong to the same person.

2. Use an unordered_map<string, int> to map each email to the
   index of the first account in which it appears.
   - If an email appears for the first time, store its account index.
   - If it has appeared before, union the current account with
     the account index stored for that email.

3. After processing all accounts, accounts belonging to the same
   person will have the same DSU representative.

4. Traverse the email map and group emails by their DSU representative
   using unordered_map<int, vector<string>>.

5. For each group:
   - Sort the emails alphabetically.
   - Insert the account holder's name at the beginning.
   - Add the merged account to the answer.

6. Return the answer.

TIME COMPLEXITY:
Let N be the number of accounts and E be the total number of email
entries. DSU operations take nearly O(1) amortized time.
Sorting the emails dominates the overall complexity.

SPACE COMPLEXITY:
O(E + N) for the maps, DSU arrays, and answer.
*/

class Solution {
    vector<int> par, rank;

    // Finds the representative of x and compresses the path
    // so future find operations become faster.
    int find(int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    // Combines two sets using rank to keep the DSU tree shallow.
    void unionByRank(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        // Already in the same set.
        if (pa == pb) return;

        // Attach the shorter-rank tree under the higher-rank tree.
        if (rank[pa] > rank[pb]) {
            par[pb] = pa;
        }
        else if (rank[pa] < rank[pb]) {
            par[pa] = pb;
        }
        else {
            // Equal ranks: choose pa as the representative
            // and increase its rank.
            rank[pa]++;
            par[pb] = pa;
        }
    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        // Initially, every account belongs to its own set.
        par.resize(n);
        rank.assign(n, 0);
        iota(par.begin(), par.end(), 0);

        // Maps each email to the account index where it was first seen.
        unordered_map<string, int> m;

        // Step 1: Find accounts that share emails and union them.
        for (int i = 0; i < n; i++) {
            // Index 0 contains the name; emails start at index 1.
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];

                if (m.find(mail) == m.end()) {
                    // First time seeing this email.
                    m[mail] = i;
                }
                else {
                    // Email already exists, so both accounts
                    // belong to the same person.
                    unionByRank(i, m[mail]);
                }
            }
        }

        // Step 2: Group every email by its final DSU representative.
        unordered_map<int, vector<string>> groups;

        for (pair<string, int> p : m) {
            string mail = p.first;
            int account = p.second;

            // Find the final representative after all unions.
            int root = find(account);

            // Store this email in that person's group.
            groups[root].push_back(mail);
        }

        vector<vector<string>> ans;

        // Step 3: Sort each person's emails and build the final account.
        for (pair<int, vector<string>> p : groups) {
            int root = p.first;
            vector<string> emails = p.second;

            // The problem guarantees that merged accounts have
            // the same name, so the representative's name is valid.
            sort(emails.begin(), emails.end());

            // Put the person's name before the sorted emails.
            emails.insert(emails.begin(), accounts[root][0]);

            // Add the completed account to the answer.
            ans.push_back(emails);
        }

        return ans;
    }
};
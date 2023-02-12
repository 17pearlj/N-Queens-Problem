class Solution {
    public:
    vector<bool> rs;
    vector<bool> cs;
    unordered_map<int, bool> diags;
    unordered_map<int, bool> antidiags;
    vector<vector<string>> sol;
    vector<string> build;
    void buildSol(int r) {
        if (r == rs.size()) {
            sol.push_back(build);
            return;
        }
        rs[r] = true;
        for (int c = 0; c < cs.size(); c++) {
           
            
            if (!cs[c] && !diags[r-c] && !antidiags[r + c]) {
                build[r][c] = 'Q';
                cs[c] = true;
                diags[r-c] = true;
                antidiags[r + c] = true;
                // diags and antidiags are true
                buildSol(r + 1);
                build[r][c] = '.';
                diags[r-c] = false;
                cs[c] = false;
                antidiags[r+c] = false;
                // diags and antidiags are false

            }
        }
        rs[r] = false;
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        rs.resize(n);
        cs.resize(n);
        string b;
        b.resize(n, '.');

        build.resize(n, b);
        buildSol(0);
        return sol;
    }

};

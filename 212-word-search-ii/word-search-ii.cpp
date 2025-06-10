class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    string word = ""; // if not empty, this node marks end of a word
};

class Solution {
public:
    vector<string> result;

    void insertWord(TrieNode* root, const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children.count(c))
                node->children[c] = new TrieNode();
            node = node->children[c];
        }
        node->word = word;
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node) {
        char c = board[i][j];
        if (!node->children.count(c)) return;
        
        node = node->children[c];
        if (!node->word.empty()) {
            result.push_back(node->word);
            node->word = ""; // avoid duplicates
        }

        board[i][j] = '#'; // mark visited

        vector<pair<int, int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
        for (auto [dx, dy] : directions) {
            int x = i + dx, y = j + dy;
            if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && board[x][y] != '#') {
                dfs(board, x, y, node);
            }
        }

        board[i][j] = c; // backtrack
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();

        for (const string& word : words)
            insertWord(root, word);

        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j)
                dfs(board, i, j, root);

        return result;
    }
};

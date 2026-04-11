class WordDictionary {

    struct tnode {
        bool word_present = false;
        tnode* children[26];
    };

    tnode* head;

public:
    WordDictionary() {
        head = new tnode();
    }
    
    void addWord(string word) {
        tnode* cur = head;

        for (char c : word) {
            if (!cur->children[c-'a']) {
                cur->children[c-'a'] = new tnode();
            }

            cur = cur->children[c-'a'];
        }
        cur->word_present = true;
    }
    
    bool search(string word) {
        return search_helper(word, 0, head);
    }

    bool search_helper(string& word, int idx, tnode* node_ptr) {

        //cout << "search " << word << endl;

        if (idx == word.size()) return node_ptr->word_present;

        char cur = word[idx];

        if (cur == '.') {
            // use all posibilities that's not nullptr

            for (char c = 'a'; c <= 'z'; c++) {
                tnode* cand = node_ptr->children[c-'a'];
                if (!cand) continue;

                if (search_helper(word, idx+1, cand)) return true;
            }
            return false;

        } else {
            // normal letter

            tnode* cand = node_ptr->children[cur-'a'];

            if (cand) return search_helper(word, idx+1, cand);
            else return false;
        }
    }
};

// this is just a dfs in the node

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
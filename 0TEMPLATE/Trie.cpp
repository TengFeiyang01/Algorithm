class Trie {
    class TrieNode {
    public:    
        bool end;
        TrieNode* son[26]{};    
    };
    TrieNode* root; 

public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* p = root;
        for (char&c : word) {
            c -= 'a';
            if (!p->son[c]) p->son[c] = new TrieNode();
            p = p->son[c];
        }
        p->end = true;
    }
    
    bool search(string word) {
        TrieNode* p = root;
        for (auto&c : word) {
            c -= 'a';
            if (!p->son[c]) return false;
            p = p->son[c];
        }
        return p->end;
    }
    
    bool startsWith(string prefix) {
        TrieNode* p = root;
        for (auto&c : prefix) {
            c -= 'a';
            if (!p->son[c]) return false;
            p = p->son[c];
        }
        return true;
    }
};

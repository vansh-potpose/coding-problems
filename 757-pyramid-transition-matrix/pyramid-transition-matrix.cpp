// This version has a pruning Check
using u8=unsigned char;

u8 pattern[36];
const int N=117649; // 7^6
bitset<N> BAD[7];   // memo per row length

class Solution {
public:
    static inline unsigned encode(const string& s) {
        unsigned ans=0;
        for (char c : s) {
            ans=ans*7+(c-'A');
        }
        return ans;
    }
    static inline bool Check(const string& cur, int sz) {
        for (int i=0; i<sz-1; i++) {
            if (cur[i]=='G') return 0;
            u8 key=(cur[i]-'A')*6+(cur[i+1]-'A');
            if (!pattern[key]) return 0;
        }
        return 1;
    }

    static inline void addPattern(const vector<string>& allowed) {
        for (const auto& s : allowed) {
            u8 idx=(s[0]-'A')*6+(s[1]-'A');
            pattern[idx]|=1<<(s[2]-'A');
        }
    }

    static bool dfs(const string& cur, string& next, int i, int sz) {
        if (i==sz-1) {
            if (sz==2) return 1;
            // pruning check
            if (!Check(next, sz-1)) return 0;
            unsigned idx=encode(next);
            if (BAD[sz-1][idx]) return 0;

            string up(sz-1, 'G');
            if (!dfs(next, up, 0, sz-1)) {
                BAD[sz-1][idx]=1;
                return 0;
            }
            return 1;
        }

        u8 key=(cur[i]-'A')*6+(cur[i+1]-'A');
        unsigned mask=pattern[key];

        while (mask) {
            unsigned bit=mask & -mask;
            mask-=bit;

            int c=countr_zero(bit);
            next[i]='A'+c;

            if (dfs(cur, next, i+1, sz))
                return 1;
        }
        return 0;
    }

    static bool pyramidTransition(string bottom, vector<string>& allowed) {
        memset(pattern, 0, sizeof(pattern));
        for (int i=1; i<=6; i++) BAD[i].reset();

        addPattern(allowed);

        string next(bottom.size()-1, 'G');
        return dfs(bottom, next, 0, bottom.size());
    }
};

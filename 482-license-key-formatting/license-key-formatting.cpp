class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        
        // Eliminate all dashes
        s = std::regex_replace(s, std::regex("\-"), "");
        
        int head = s.length() % k;
        
        vector<string> grouping;
        
        // Special handle for first group
        if( head ){
            grouping.emplace_back( s.substr(0, head) );
        }
        
        // General cases
        for( int i = head ; i < s.length() ; i += k ){
             grouping.emplace_back( s.substr(i, k) );
        }
        
        // Link each group togetger and separated by dash '-'
        s = join(grouping, "-");
        
        // to uppercase
        transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ return std::toupper(c); } );
        return s;
    }
    
private:
    string join(const std::vector<string> &lst, const string &delim)
    {
        std::string ret;
        for(const auto &s : lst) {
            if(!ret.empty())
                ret += delim;
            ret += s;
        }
        return ret;
    }
    
};
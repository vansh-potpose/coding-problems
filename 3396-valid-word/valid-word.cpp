class Solution {
public:
    bool isValid(string word) {
        bool vowels=false,consonant=false;
        if(word.size()<3)return false;
        for(auto c : word){
            if(!isalnum(c)){
                return false;
            }

            if(isalpha(c)){
                char ch=tolower(c);
                    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
                    {
                        vowels=true;
                    }
                    else
                    {
                        consonant=true;
                    }
            }

        }
        return (vowels && consonant);
    }
};
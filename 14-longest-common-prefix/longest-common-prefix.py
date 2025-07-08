class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        
        if len(strs) == 1:
            if(strs[0] == ''):
                return ''
            else:
                return strs[0]
        
        smallestLen = len(min(strs, key=len))

        for i in range(smallestLen):
            for j in range(len(strs)):
                if(strs[0][i] != strs[j][i]):
                    return strs[0][:i]
        return strs[0][:smallestLen]
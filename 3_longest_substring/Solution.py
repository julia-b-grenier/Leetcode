
def lengthOfLongestSubstring(s):
    """
    :type s: str
    :rtype: int
    """
    longest_unique = ""
    unique = ""

    for i, char in enumerate(s):
        if char not in unique:
            unique += char

            if i == len(s)-1:
                if len(unique) > len(longest_unique):
                    longest_unique = unique
        else:
            if len(unique) > len(longest_unique):
                longest_unique = unique
                
            unique = unique[unique.find(char)+1:]
            unique += char

    return len(longest_unique)

a = "abcabcbb"
b = "bbbbb"
c = "pwwkew"
d = " "
e = "au"
f = "dvdf"
g = "nfpdmpi"

print(lengthOfLongestSubstring(a)) # 3
print(lengthOfLongestSubstring(b)) # 1
print(lengthOfLongestSubstring(c)) # 3
print(lengthOfLongestSubstring(d)) # 1
print(lengthOfLongestSubstring(e)) # 2
print(lengthOfLongestSubstring(f)) # 3
print(lengthOfLongestSubstring(g)) # 5

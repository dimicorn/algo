class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        hash_map = {}
        for ch1, ch2 in zip(s, t):
            if ch1 not in hash_map:
                hash_map[ch1] = ch2
            elif hash_map[ch1] != ch2:
                return False
        hash_map = {}
        for ch1, ch2 in zip(s, t):
            if ch2 not in hash_map:
                hash_map[ch2] = ch1
            elif hash_map[ch2] != ch1:
                return False
        return True

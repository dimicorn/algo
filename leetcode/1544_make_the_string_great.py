class Solution:
    def makeGood(self, s: str) -> str:
        st = []
        for ch in s:
            if not st:
                st.append(ch)
            elif ((st[-1].upper() == ch or
                st[-1] == ch.upper()) and
                st[-1] != ch) :
                st.pop()
            else:
                st.append(ch)
        return ''.join(st)

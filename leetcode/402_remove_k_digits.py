class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        st = []
        count = 0
        for ch in num:
            if not st:
                st.append(ch)
            else:
                if count < k:
                    if st[-1] <= ch:
                        st.append(ch)
                    else:
                        while st and count < k and st[-1] > ch:
                            st.pop()
                            count += 1
                        st.append(ch)
                else:
                    st.append(ch)
        while count < k:
            st.pop()
            count += 1
        
        res = ''.join(st)
        res = res.lstrip('0')
        if res == '':
            return '0'
        return res

class Solution:
    def timeRequiredToBuy(self, tickets: List[int], k: int) -> int:
        n = len(tickets)
        time = 0
        i = 0
        while tickets[k] > 0:
            i %= n
            if tickets[i] > 0:
                tickets[i] -= 1
                time +=1 
            i += 1
        return time

class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        deck = sorted(deck, reverse=True)
        res = collections.deque()
        for card in deck:
            if not res:
                res.append(card)
            else:
                res.appendleft(res.pop())
                res.appendleft(card)
        return res

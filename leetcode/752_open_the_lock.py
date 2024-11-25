from collections import deque
from typing import List

class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        # Function to generate the next possible combinations from current state
        def get_next_states(state):
            next_states = []
            state_digits = list(state)
            for i in range(4):
                original_digit = state_digits[i]
                # Decrement the digit (with wrap-around)
                state_digits[i] = '9' if original_digit == '0' else str(int(original_digit) - 1)
                next_states.append(''.join(state_digits))
                # Increment the digit (with wrap-around)
                state_digits[i] = '0' if original_digit == '9' else str(int(original_digit) + 1)
                next_states.append(''.join(state_digits))
                # Restore original digit for the next iteration
                state_digits[i] = original_digit
            return next_states

        # Function to perform one step of bidirectional BFS
        def extend(frontier, opposite_frontier, queue):
            for _ in range(len(queue)):
                current_state = queue.popleft()
                current_step = frontier[current_state]
                for next_state in get_next_states(current_state):
                    if next_state in deadend_set or next_state in frontier:
                        continue
                    if next_state in opposite_frontier:
                        return current_step + 1 + opposite_frontier[next_state]
                    frontier[next_state] = current_step + 1
                    queue.append(next_state)
            return -1

        # Main BFS function used for bidirectional search
        def bidirectional_bfs():
            start_frontier = {"0000": 0}  # Map of seen combinations starting from "0000"
            target_frontier = {target: 0}  # Map of seen combinations starting from the target
            start_queue = deque(['0000'])   # Queue for the BFS from "0000"
            target_queue = deque([target])  # Queue for the BFS from the target

            while start_queue and target_queue:
                # Alternate between expanding from the start and target
                result = extend(start_frontier, target_frontier, start_queue) if len(start_queue) <= len(target_queue) else extend(target_frontier, start_frontier, target_queue)
                if result != -1:
                    return result
            return -1  # No solution found

        # If the target is "0000", it's already unlocked
        if target == '0000':
            return 0
        # Initialize dead end states in a set for quick lookup
        deadend_set = set(deadends)
        # If "0000" is in dead ends, we cannot start
        if '0000' in deadend_set:
            return -1
        # Perform bidirectional BFS
        return bidirectional_bfs()
        

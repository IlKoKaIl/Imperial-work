"""
test2.py

This file contains two coding problems (transcribed) and working Python 3
solutions for each. Each problem includes the question body (as given), the
example(s), the solution function, and brief comments explaining the main
steps.

Problems included:
1) Maximum length subsequence with even sum of sorted consecutive differences
   - function: findLongestSubsequence(arr)

2) Designing building heights to maximize total height under constraints
   - function: max_total_height(maxHeight)

You can import this file or run the functions directly from a REPL.
"""

# -------------------------
# Problem 1 (transcription)
# -------------------------
# You are given an integer array arr.
# Your task is to find the maximum length subsequence such that:
#  - After sorting the chosen subsequence in increasing order,
#  - The sum of the absolute differences between consecutive elements is even.
# Note: A subsequence is formed by removing zero or more elements from the
# array while keeping the relative order of the remaining elements.
# Return the maximum possible length of such a subsequence.
#
# Example (as provided):
# Suppose arr = [2, 4, 1, 7]
# Output: 4
# Explanation: one can choose the subsequence [2,4,1,7] itself. After sorting
# it becomes [1,2,4,7]. The consecutive absolute differences are |2-1|=1,
# |4-2|=2, |7-4|=3, sum = 1+2+3 = 6 which is even. So length is 4.
#
# Key observation used in solution:
# For any sorted subsequence, the sum of absolute differences between consecutive
# elements equals (max - min). Therefore the sum is even iff (max - min) is even.
# Thus to get a valid subsequence its min and max must have the same parity
# (both even or both odd). For a chosen parity, we can take any elements whose
# values lie between that parity's min and max (inclusive) while preserving order.
# The maximum possible length for that parity is the count of array elements
# whose values are between that parity's min and max (inclusive). Answer is the
# larger of the two parity counts.

def findLongestSubsequence(arr):
	"""Return maximum length of a subsequence satisfying the problem.

	- arr: list[int]
	- returns: int
	"""
	if not arr:
		return 0

	# Track min and max values separately for even (p=0) and odd (p=1)
	min_p = {0: None, 1: None}
	max_p = {0: None, 1: None}

	for x in arr:
		p = x & 1  # parity: 0 for even, 1 for odd
		if min_p[p] is None or x < min_p[p]:
			min_p[p] = x
		if max_p[p] is None or x > max_p[p]:
			max_p[p] = x

	best = 0
	# For each parity that exists, count elements whose values are within [min,max]
	for p in (0, 1):
		if min_p[p] is None:
			continue
		lo, hi = min_p[p], max_p[p]
		# Count all elements in the original array whose value is between lo and hi
		cnt = sum(1 for x in arr if lo <= x <= hi)
		if cnt > best:
			best = cnt

	return best


# -------------------------
# Problem 2 (transcription)
# -------------------------
# You are designing the heights of n new buildings in a row.
# Each building must follow these rules:
#  - The maximum allowed height of building i is maxHeight[i] (for 0 <= i < n).
#  - Let height[i] be the chosen height of building i.
#    For every index i, there must not exist indices j and k such that:
#      0 <= j < i < k < n and height[j] > height[i] and height[k] > height[i].
#    In other words, no building can be strictly lower than both some building on
#    its left and some building on its right.
#
# Your goal is to choose height[i] for each building (0 <= height[i] <= maxHeight[i])
# so that the sum of all heights is as large as possible while satisfying the
# condition above.
#
# Return the maximum possible total height.
#
# Example (as provided):
# Suppose n = 5, and maxHeight = [5, 10, 5, 10, 5]
# Output: 30
# One optimal construction is height = [5, 10, 5, 5, 5]
# (sum = 30). This arrangement ensures there is no index i with greater values
# on both its left and right sides.
#
# Simple (clear) solution approach used here:
# Try each position i as the 'peak' (the position that is not strictly lower
# than both sides), then greedily choose heights leftwards and rightwards such
# that heights never increase beyond the previous chosen height and never exceed
# the allowed maxHeight. Sum the chosen heights and keep the best total.
# This is O(n^2) but fine for n up to ~1000.

def max_total_height(maxHeight):
	"""Return maximum total height given per-position maximums.

	- maxHeight: list[int]
	- returns: int total maximum achievable sum
	"""
	n = len(maxHeight)
	if n == 0:
		return 0

	best = 0
	# try each index i as the 'peak'
	for i in range(n):
		total = maxHeight[i]
		# expand to the left
		curr = maxHeight[i]
		for j in range(i - 1, -1, -1):
			curr = min(curr, maxHeight[j])
			total += curr
		# expand to the right
		curr = maxHeight[i]
		for j in range(i + 1, n):
			curr = min(curr, maxHeight[j])
			total += curr
		if total > best:
			best = total

	return best


# -------------------------
# Quick demo helpers / small explanations
# -------------------------

def _demo():
	# Problem 1 demo
	arr = [2, 4, 1, 7]
	print("Problem 1 example arr:", arr)
	print("Expected output: 4")
	print("findLongestSubsequence ->", findLongestSubsequence(arr))
	print()

	# Problem 2 demo
	mh = [5, 10, 5, 10, 5]
	print("Problem 2 example maxHeight:", mh)
	print("Expected output: 30")
	print("max_total_height ->", max_total_height(mh))


if __name__ == '__main__':
	_demo()


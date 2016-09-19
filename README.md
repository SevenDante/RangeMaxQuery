# RangeMaxQuery
Famous range query algorithm. Querying is done on a binary tree & the time complexity for same is O(log n). Doin' brute force will result in O(n)
which may exceed the time limit. Binary Tree is constructed in O(n) time.
Therefore total Querying time complexity will be O(qlog n), given total number of queries q which is much better than O(qn). 
In this particular example we'll return the maximum of a given range(l,r) where(1<= (l,r) <= n).

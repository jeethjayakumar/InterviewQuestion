Algorand Interview Questions

1. Break A Palindrome:
   A Palindrome reads the same from left to right, mom for example. There is a palindrome which must be modified, if possible.
   Change exactly one character of the string to another character in the range ascii[a-z] so that the string meets the 
   following 3 conditions:
	. The new string is the lowest alphabetically than the initial string.
	. The new string is the lowest value string alphabetically that can be created from the original palindrome after
	  making only one change.
	. The new string is not a palindrome.
   Return the new string or if it not possible to create a string meeting the criteria, return the string IMPOSSIBLE.
   Example:
	palindromeStr = 'bab'
	output = aab
	palindromeStr = 'aaa'
	output = IMPOSSIBLE
	palindromeStr = 'acca'
	output = 'aaca'

2. The Cost of a Tree: 
   Given an array of integers, construct a tree. Each node of the tree has either two children or none, in which case 
   it is a leaf node. A leaf node costs 0 to construct. The cost to build a parent node is the product of the maximum leaf values
   in its left and right sub-trees. Partition the array to minimize the cost of building the entire tree.
   Complete function calculateCost which accepts array of integers and returns minimum cost to construct the tree.
   Example:
	arr = [2,1]
	output = 2
	arr = [5,3,1]
	output = 18
	arr = [1,5,3]
	output = 20

3. Social Media Connections:
   Social media connections can serve as a means of recognizing relationships among a group of people. These relationships
   can be represented as an undirected graph where edges join related people. A group of n social media friends is uniquely 
   numbered from 1 to friends_nodes. The group of friends is expressed as a graph with friends_edges undirected edges, where
   each pair of best friends is directly connected by an edge. A trio is defined as a group of three best friends. The friendship
   score for a person in trio is defined as the number of best friends theat person has outside of the trio. The friendship
   sum for a trio is the sum of the trio's friendship score.
   Given friendship connection data, create an undirected graph and determine the minimum friendship sum for all trios of 
   best friends in the group. If no such trio exists,return -1.
   Example: 
	friends_from=[1,1,2,2,3,4] friends_to=[2,3,3,4,4,5]
	output = 2
	friends_from=[2,3,5,1] friends_to=[1,6,1,7]
	output = -1

03/08/2022:
4. Rate Limiter: Design and implement a rate limiter where a server is allowed to accept only 3 request per client per second at
   any given time. Execute and write the test-case for this.

5. Implement a Linked-List that has following function:
	a. push(string x) void - Insert the string in the front of the linked list
	b. pop() string - Returns the front of the data and removes that data from Linked List
	c. empty() bool - Check if the bool is empty or not
	d. valid() bool - Check if the linked list is tampered or not. If tampered, returns false.
	e. tamper(int pos, string x) void - Update the data in a certain index in a list.
   Condition : DO NOT USE ANY EXISTING DATA STRUCTURE.
	Example: LinkedList l;
	l.push("100") : 100->null
	l.push("200") : 200->100->null
	l.push("300") : 300->200->100->null
	l.pop() : Output = 300
	l.empty() : false
	l.valid() : true
	l.tamper(2,"100") 
	l.valid() : true
	l.tamper(2,"300")
	l.valid() : false

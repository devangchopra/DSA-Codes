//Brute Force TLE

// class Solution {
// public:
// 	int findMaximumXOR(vector<int>& nums) {
// 		int n = nums.size(), ans = INT_MIN;
// 		for (int i = 0; i < n; i++) {
// 			for (int j = 0; j < n; j++) {
// 				ans = max(ans, (nums[i] xor nums[j]));
// 			}
// 		}
// 		return ans;
// 	}
// };


//Question
/*Given an array find the maximum XOR between two numbers in the array
XOR : a xor a = 0
      a xor b = 1

For Maximum Number
We should get the most significant bit , second most significant bit,...so
on from left to right == 1
So we will do that

Binary Representation = 32 bit
Therefore a Trie of 32 units height

For each element in the array we will search this trie
Time Cmplexity = O(n*32)

Trie : Space Optimization and Easy Searching

			Root
		   /	\
		  0		 1
Left -> 0
Right -> 1

*/

/*
Why to use Pointer
Because of the dynamic Memory Allocation
When the allocation is static and any program runs
it pre allocates some memory in the stack section
so growing that is not recommended and if grows more may
cause buffer overflow

Therefore in the address table we store the address of the pointer
which is of 8 byte and actual memory is in pool which is heap*/

//Pointer is a data type to hold addresses


#include <bits/stdc++.h>
using namespace std;

class TrieNode {

public:

	TrieNode* left;
	TrieNode* right;

	TrieNode() {
		left = NULL;
		right = NULL;
	}
};

//No values
//Only object of that class

void insert(TrieNode* head, int n) {

	//Inserting in trie via help of Binary Representation of number
	//32 bit

	//Temporary Pointer
	//Not working on the head itself
	TrieNode* curr = head;

	for (int i = 31; i >= 0; i--) {
		int b = (n >> i) & 1;

		//Left shifting i times and taking and with 1
		//Gives us the MSB >> 2nd MSB and so on
		if (b == 0) {
			//Insert in left
			//if already exists
			if (curr->left) {
				//do nothing
			}
			else {
				TrieNode* node = new TrieNode();
				curr->left = node;

				//when dealing with pointers
				//to access class members we use -> not .
			}
			curr = curr->left;
		}
		else {
			if (curr->right) {
				//do nothing
			}
			else {
				TrieNode* node = new TrieNode();
				curr->right = node;
			}
			curr = curr->right;
		}

	}
}

//n->no.of elements in array

int findMaximum(TrieNode* head, int n, int* arr) {

	//Elements in arr are inserted in trie in binary format
	//I check for each number that its maximum xor would be
	//Now rather than O(n**2)
	//I am using bit manipulation and Trie

	int ans = INT_MIN;
	for (int i = 0; i < n; i++) {

		int value = arr[i];

		TrieNode * curr = head;

		int temp_xor = 0;

		for (int j = 31; j >= 0; j--) {

			int b = (value >> j) & 1;

			if (b == 0) {
				//We have to search for 1
				if (curr->right) {

					temp_xor += pow(2, j);
					//Xor with arbitrary number would give me 1
					//So adding it in decimal form
					curr = curr->right;
				} else {
					//No choice but to move left
					curr = curr->left;
				}


			}
			else {
				//Search for 0
				if (curr->left) {
					temp_xor += pow(2, j);
					curr = curr->left;
				}
				else {
					curr = curr->right;
				}
			}
		}

		if (temp_xor > ans) {
			ans = temp_xor;
		}
	}

	return ans;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int arr[] = {3, 10, 5, 25, 2, 8};
	int n = 6;

	//Step 1 : Insert

	TrieNode* head = new TrieNode();

	for (auto& i : arr) {
		insert(head, i);
	}

	//Step 2 : ans

	int ans = findMaximum(head, n, arr);

	//Array names behaves as an pointer to the first element

	cout << ans << endl;
}


//Leetcode Way

class Solution {
public:
	class TrieNode {

	public:

		TrieNode* left;
		TrieNode* right;

		TrieNode() {
			left = NULL;
			right = NULL;
		}
	};

	void insert(TrieNode* head, int n) {
		TrieNode* curr = head;
		for (int i = 31; i >= 0; i--) {
			int b = (n >> i) & 1;
			if (b == 0) {
				if (curr->left) {
				}
				else {
					TrieNode* node = new TrieNode();
					curr->left = node;
				}
				curr = curr->left;
			}
			else {
				if (curr->right) {
				}
				else {
					TrieNode* node = new TrieNode();
					curr->right = node;
				}
				curr = curr->right;
			}

		}
	}

	int fun(TrieNode* head, int n, vector<int>& arr) {

		int ans = INT_MIN;
		for (int i = 0; i < n; i++) {

			int value = arr[i];

			TrieNode * curr = head;

			int temp_xor = 0;

			for (int j = 31; j >= 0; j--) {

				int b = (value >> j) & 1;

				if (b == 0) {
					if (curr->right) {
						temp_xor += pow(2, j);
						curr = curr->right;
					} else {
						curr = curr->left;
					}
				}
				else {
					if (curr->left) {
						temp_xor += pow(2, j);
						curr = curr->left;
					}
					else {
						curr = curr->right;
					}
				}
			}
			if (temp_xor > ans) {
				ans = temp_xor;
			}
		}

		return ans;
	}

	int findMaximumXOR(vector<int>& nums) {

		TrieNode* head = new TrieNode();
		for (auto& i : nums) {
			insert(head, i);
		}
		int n = nums.size();
		int ans = fun(head, n, nums);

		return ans;

	}
};
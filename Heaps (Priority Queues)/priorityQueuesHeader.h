//Implementation of MinHeap
#include <vector>


class priorityQueue
{
	vector<int> pq;

public:
	priorityQueue()
	{
		//no work to do in constructor
	}

	bool isempty()
	{
		return pq.size()==0;
	}

	int getsize()
	{
		return pq.size();
	}

	int getmin()
	{
		if(isempty())
		{
			return 0;
		}
		return pq[0];
	}

	void insert(int element)
	{
		pq.push_back(element);

		//Up Heapify
		int childIndex=pq.size()-1;

		while(childIndex>0)
		{
			int parentIndex=(childIndex-1)/2;

			if(pq[childIndex]<pq[parentIndex])
			{
				//swap
				int temp=pq[childIndex];
				pq[childIndex]=pq[parentIndex];
				pq[parentIndex]=temp;				
			}
			else
			{
				//if correct position
				break;
			}
			childIndex=parentIndex;
		}
	}

	int removeMin()
	{
		int ans=pq[0];

		pq[0]=pq[pq.size()-1];

		pq.pop_back();

		//move up --> down and remove

		//Down Heapify

		int parentIndex=0;

		int leftChildIndex=2*parentIndex+1;
		int rightChildIndex=2*parentIndex+2;

		while(leftChildIndex<pq.size())
		{
			int minIndex=parentIndex;
			//the element with minimum index

			//Finding the minimum vlaue

			if(pq[minIndex]>pq[leftChildIndex])
			{
				minIndex=leftChildIndex;
			}

			if(pq[minIndex]>pq[rightChildIndex])
			{
				minIndex=rightChildIndex;
			}

			if(parentIndex==minIndex)
			{
				break;
				//that means we are at the correct position
			}

			//swap the values
			int temp=pq[minIndex];
			pq[minIndex]=pq[parentIndex];
			pq[parentIndex]=temp;

			parentIndex=minIndex;
			//move parent :: --> Up Heapify
			leftChildIndex=2*parentIndex+1;
			rightChildIndex=2*parentIndex+2;

		}
		return ans;

	}
};
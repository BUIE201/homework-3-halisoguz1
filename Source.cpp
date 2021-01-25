#include <iostream>
#include <vector>
using namespace std;

struct Node
{
	int i;
	Node* pLeft;
	Node* pRight;

	Node(int iIn) : i(iIn), pLeft(nullptr), pRight(nullptr) {}
};

void InsertToTree(Node*& pRoot, Node* pNew)
{
	if (!pRoot)
	{
		pRoot = pNew;
		return;
	}

	if (pNew->i <= pRoot->i)
		InsertToTree(pRoot->pLeft, pNew);
	else
		InsertToTree(pRoot->pRight, pNew);
}

void DeleteNodeWithTwoChildren(Node*& q, Node*& p)
{
	if (p->pRight)
	{
		DeleteNodeWithTwoChildren(q, p->pRight);
		return;
	}

	p->i = q->i;
	q = p;
	p = p->pLeft;
}

void DeleteNodeFromTree(Node*& pRoot, int i)
{
	if (!pRoot)
		return;

	if (pRoot->i < i)
	{
		DeleteNodeFromTree(pRoot->pRight, i);
		return;
	}

	if (pRoot->i > i)
	{
		DeleteNodeFromTree(pRoot->pLeft, i);
		return;
	}

	Node* q = pRoot;
	if (!q->pRight)
		pRoot = q->pLeft;
	else if (!q->pLeft)
		pRoot = q->pRight;
	else
		DeleteNodeWithTwoChildren(q, q->pLeft);

	delete q;
}

void PrintTree(Node* pRoot, int Level)
{
	if (!pRoot)
		return;

	PrintTree(pRoot->pRight, Level + 1);

	for (int i = 0; i < Level; i++)
		cout << "  ";
	cout << pRoot->i << endl;

	PrintTree(pRoot->pLeft, Level + 1);
}

void Insert(Node*& pRoot, Node* pNewNode)
{
	if (!pRoot)
		pRoot = pNewNode;
	else
	{
		if (pNewNode->i < pRoot->i)
			Insert(pRoot->pLeft, pNewNode);
		else
			Insert(pRoot->pRight, pNewNode);
	}
}



bool printingthemaxPath(Node* pRoot, int maxsum)
{
	if (maxsum == 0) {
		return true;
	}
	if (pRoot == nullptr) {
		return false;
	}



	bool rightsum = printingthemaxPath(pRoot->pRight, maxsum - pRoot->i);
	bool leftsum = printingthemaxPath(pRoot->pLeft, maxsum - pRoot->i);

	if (leftsum || rightsum) {
		cout << pRoot->i << " ";
	}

	return leftsum || rightsum;
}


int sumFunc(Node* pRoot) {
	if (pRoot == nullptr)
		return 0;
	int leftsum = sumFunc(pRoot->pLeft);
	int rightsum = sumFunc(pRoot->pRight);
	return(leftsum > rightsum ? leftsum : rightsum) + pRoot->i;

}

void FindingIt(Node* pRoot) {
	int maxsum = sumFunc(pRoot);
	cout << "The max sum is" << maxsum << endl;
	cout << " The max sum path is:" << printingthemaxPath(pRoot, maxsum) << endl;
}


void main()
{


	//*/ 5
	//	/ \
	//	4   8
	//	/   / \
	//	11  13  4
	//	/ \      \
	//	7    2      1


	int i;

	Node* pRoot = nullptr;
	/*while (true)
	{
		cin >> i;
		if (i == 99)
			break;

		Node* p = new Node(i);
		InsertToTree(pRoot, p);
	}*/

	PrintTree(pRoot, 1);
	pRoot = new Node(5);

	pRoot->pRight = new Node(8);
	pRoot->pRight->pRight = new Node(4);
	pRoot->pRight->pLeft = new Node(13);
	pRoot->pRight->pRight->pRight = new Node(1);
	pRoot->pLeft = new Node(4);
	pRoot->pLeft->pLeft = new Node(11);
	pRoot->pLeft->pLeft->pRight = new Node(2);
	pRoot->pLeft->pLeft->pLeft = new Node(7);


	FindingIt(pRoot);

}


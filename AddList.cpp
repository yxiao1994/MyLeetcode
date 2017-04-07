#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
struct Node {
	int val;
	struct Node * next;
	Node(int x) :val(x), next(nullptr) {};
};
void CreateList(vector<int> vec,Node* header) {
	Node* ptemp = header;
	for (int i = 0; i < vec.size(); i++) {
	/*Node* pnew=new Node(vec[i]);
		ptemp->next = pnew;
		ptemp=pnew;*/
		ptemp->next = new Node(vec[i]);
		ptemp = ptemp->next;

	}
}

void addTwoNumbers(Node* L1, Node * L2,Node * result) {	
	Node *p = L1->next;
	Node *q = L2->next;
	Node *cur = result;
	int carry = 0;
	while (p != nullptr||q != nullptr) {
		int val1 = (p!= nullptr) ? p->val : 0;
		int val2 = (q!= nullptr) ? q->val : 0;
		int sum = val1 + val2 + carry;
		carry = sum / 10;
		cur->next =new Node(sum % 10);
		cur = cur->next;
		if (p != nullptr)
			p = p->next;
		if (q != nullptr)
			q = q->next;
	}
	if (carry != 0)
		cur->next = new Node(1);

}
Node* addTwoNumbers(Node* L1, Node * L2) {
	//return a point
	Node *p = L1->next;
	Node *q = L2->next;
	Node* result = new Node(0);
	Node *cur = result;
	int carry = 0;
	while (p != nullptr || q != nullptr) {
		int val1 = (p != nullptr) ? p->val : 0;
		int val2 = (q != nullptr) ? q->val : 0;
		int sum = val1 + val2 + carry;
		carry = sum / 10;
		cur->next = new Node(sum % 10);
		cur = cur->next;
		if (p != nullptr)
			p = p->next;
		if (q != nullptr)
			q = q->next;
	}
	if (carry != 0)
		cur->next = new Node(1);
	return result;

}
void ReverseList(Node * Header) {
	Node * pcur = Header->next;
	Node * pnext;
	Header->next = nullptr;
	while (pcur != nullptr) {
		pnext = pcur->next;
		pcur->next = Header->next;
		Header->next = pcur;
		pcur = pnext;
	}
}
Node* removeNthFromEnd(Node* head, int n) {//删除倒数第n个元素
	int length = 0;
	Node* p1 = head->next;
	while (p1 != nullptr) {
		length++;
		p1 = p1->next;
	}
	length -= n;
	Node* pcur = head;
	for (int i = 0; i < length; i++)
		pcur = pcur->next;
	Node *pnext = pcur->next;
	pcur->next = pnext->next;
	delete pnext;
	return head;
}
void deleteNode(Node* node) {//删除节点，其中node就是该节点
	Node* pnext = node->next;
	node->val = pnext->val;
	node->next = pnext->next;
	delete pnext;
}
/*Node* merge(Node* list1, Node* list2) {
	if (list1 == NULL) return list2;
	if (list2 == NULL) return list1;

	Node* head;
	Node* tmp;

	if (list1->val < list2->val) {
		head = list1;
		list1 = list1->next;
	} 
	else {
		head = list2;
		list2 = list2->next;
	}
	tmp = head;

	while (list1 != NULL && list2 != NULL) {
		if (list1->val < list2->val) {
			tmp->next = list1;
			tmp = list1;
			list1 = list1->next;
		}
		else {
			tmp->next = list2;
			tmp = list2;
			list2 = list2->next;
		}
	}
	if (list1 != NULL) tmp->next = list1;
	if (list2 != NULL) tmp->next = list2;

	return head;
}
Node *sortList(Node *head) {
	// write your code here
	if (head == NULL) return head;
	if (head->next == NULL) {
		return head;
	}

	Node* fast = head;
	Node* slow = head;
	while (fast->next != NULL && fast->next->next != NULL) {
		fast = fast->next;
		fast = fast->next;
		slow = slow->next;
	}

	Node* mid = slow->next;
	slow->next = NULL;

	Node* list1 = sortList(head);
	Node* list2 = sortList(mid);

	Node* sorted = merge(list1, list2);
	return sorted;
}
*/
Node* findmedium(Node* head) {
	if (head == nullptr)
		return head;
	Node* fast = head;
	Node* slow = head;
	while (fast->next&&fast->next->next) {
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}
Node* mergeTwoLists(Node* L1, Node* L2) {
	if (L1 == nullptr)
		return L2;
	if (L2 == nullptr)
		return L1;
	Node *p = L1;
	Node *q = L2;
	Node* result = new Node(0);
	Node *cur = result;
	while (p != nullptr || q != nullptr) {
		int val1 = (p != nullptr) ? p->val : INT_MAX;
		int val2 = (q != nullptr) ? q->val : INT_MAX;
		if (val1 < val2) {
			cur->next = new Node(val1);
			if (p != nullptr)
				p = p->next;
		}
		else {
			cur->next = new Node(val2);
			if (q != nullptr)
				q = q->next;
		}
		cur = cur->next;
	}
	return result->next;
}
Node* sortList(Node* head) {
	Node* mid = findmedium(head);
	if (head == nullptr)
		return nullptr;
	if (head->next == nullptr)
		return head;
	Node* midnext = mid->next;
	mid->next = nullptr;
	Node* l1 = sortList(head);
	Node* l2 = sortList(midnext);
	Node* result = mergeTwoLists(l1, l2);
	return result;
}
Node* oddEvenList(Node* head) {
	if (head->next ==nullptr)
		return nullptr;
	Node* odd = head->next;
	Node* oddHead = head->next;
	Node* even = odd->next;
	Node* evenHead = odd->next;
	while (even != nullptr&&even->next != nullptr) {
		odd->next = even->next;
		odd = odd->next;
		even->next = odd->next;
		even = even->next;
	}
	odd->next = evenHead;
	return head;
}
void TraverList(Node * Header) {
	Node *temp = Header->next;
	for (; temp != nullptr; temp = temp->next)
		cout << temp->val << "  ";
	cout << endl;
}
int main() {
	vector<int> vec{9,7,6,8,3,2};
	Node *L1 = new Node(0);
	CreateList(vec, L1);
	TraverList(L1);
	cout << "After sorted:\n";
	Node* sorted=sortList(L1->next);
	Node* head = new Node(0);
	head->next = sorted;
	TraverList(head);
	//TraverList(removeNthFromEnd(L1,2));
	/*vector<int> vec2{5,6,4};
	Node *L2 = new Node(0);
	CreateList(vec2, L2);
	TraverList(L1);
	TraverList(L2);
	Node* result = new Node(0);
	//addTwoNumbers(L1, L2, result);
	TraverList(addTwoNumbers(L1,L2));
	//test list reverse
	vector<int> vec3{ 1,2,3,4,5,6 };
	Node *L3 = new Node(0);
	CreateList(vec3, L3);
	ReverseList(L3);
	TraverList(L3);*/
	int a[] = {1,2,4,5};
	string str = string("abcd");
	cout << a[0] << endl;
	cout << str[0] << endl;
	system("pause");
	return 0;
}
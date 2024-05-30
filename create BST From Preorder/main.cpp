#include <iostream>
#include <stack>
using namespace std;
class Tree {
public:
	int data;
	Tree* left;
	Tree* right;
	Tree(int d = 0, Tree* l = nullptr, Tree* r = nullptr) : data(d), left(l), right(r) {
	}
	void set_data();
	int get_data() const;
	void set_left_right(Tree* l, Tree* r) {
		left = l; right = r;
	}
};
void Tree::set_data() {
	cout << "Enter data: ";
	cin >> data;
}
int Tree::get_data() const {
	return data;
}
void display_preorder(Tree* n) {
	if (n == nullptr)
		return;
	cout << n->get_data() << endl;
	display_preorder(n->left);
	display_preorder(n->right);
}
void display_postorder(Tree* n) {
	if (n == nullptr)
		return;
	display_postorder(n->left);
	display_postorder(n->right);
	cout << n->get_data() << endl;
}
void display_inorder(Tree* n) {
	if (n == nullptr)
		return;
	display_inorder(n->left);
	cout << n->get_data() << endl;
	display_inorder(n->right);
}
void creating(Tree*& t, int key) {
	static Tree* prev = nullptr;
	if (t == nullptr) {
		t = new Tree(key);
		if (prev && prev->get_data() < key)
			prev->right = t;
		else if (prev && prev->get_data() > key)
			prev->left = t;
	}
	else {
		if (t->get_data() == key)
			return;
		else if (key < t->get_data()) {
			prev = t;
			creating(t->left, key);
		}
		else {
			prev = t;
			creating(t->right, key);
		}
	}
}
void create_BST(Tree*& n, int* arr, int size) {
	Tree* t = n;
	for (int i = 0; i < size; i++) {
		creating(n, arr[i]);
	}
	cout << "Binary Search is Created" << endl;
}
int is_BST(Tree* n) {
	static Tree* prev = nullptr;
	if (n == nullptr)
		return 1;
	if (!is_BST(n->left))
		return 0;
	if (prev != nullptr && n->get_data() <= prev->get_data())
		return 0;
	prev = n;
	return is_BST(n->right);
}
int searching_BST(Tree* t, int key) {
	if (t == nullptr)
		return 0;
	if (key == t->get_data())
		return 1;
	else if (key < t->get_data())
		return searching_BST(t->left, key);
	else
		return searching_BST(t->right, key);
}
int iterative_search(Tree* t, int key) {
	while (t != nullptr) {
		if (t->get_data() == key)
			return 1;
		else if (key < t->get_data())
			t = t->left;
		else
			t = t->right;
	}
	return -1;
}
void inserting_BST(Tree*& t, int key) {
	static Tree* prev = nullptr;
	if (t == nullptr) {
		t = new Tree(key);
		if (prev && prev->get_data() < key)
			prev->set_left_right(nullptr, t);
		else if (prev && prev->get_data() > key)
			prev->set_left_right(t, nullptr);
	}
	if (t->get_data() == key)
		return;
	else if (key < t->get_data()) {
		prev = t;
		inserting_BST(t->left, key);
	}
	else {
		prev = t;
		inserting_BST(t->right, key);
	}
}
int searching(int* arr, int start, int end, int key) {
	for (int i = start; i < end; i++) {
		if (arr[i] == key)
			return i;
	}
	return -1;
}
Tree* create_BST_from_PreAndIn(int preorder[], int inorder[], int inStart, int inEnd) {
	if (inStart > inEnd)
		return nullptr;
	static int pre_index = 0;
	Tree* n_node = new Tree(preorder[pre_index++]);
	if (inStart == inEnd)
		return n_node;
	int in_index = searching(inorder, inStart, inEnd, n_node->get_data());
	n_node->left = create_BST_from_PreAndIn(preorder, inorder, inStart, in_index - 1);
	n_node->right = create_BST_from_PreAndIn(preorder, inorder, in_index + 1, inEnd);
	return n_node;
}
Tree* createBSTpreorder(int preorder[], int &pre_index, int max, int n) {
	Tree* root = nullptr;
	if (preorder[pre_index] > max || pre_index >= n)
		return nullptr;
	root = new Tree(preorder[pre_index++]);
	root->left = createBSTpreorder(preorder, pre_index, root->data, n);
	root->right = createBSTpreorder(preorder, pre_index, max, n);
	return root;
}
void dis(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}
int main() {
	int arr[6]{ 10,5,1,7,40, 50};
	Tree* head = nullptr;
	int n = 0;
	head = createBSTpreorder(arr, n, 50, 6);
	display_inorder(head);
	return 0;
}
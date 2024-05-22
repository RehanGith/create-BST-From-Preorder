#include <iostream>
#include <stack>
using namespace std;
class Tree {
	int data;
public:
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


int main() {
	

	return 0;
}
#ifndef BST_H
#define BST_H

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

template <typename T>
struct Node
{
	T data;
	Node* left;
	Node* right;
};

template <typename T>
class BST
{
public:
	BST();
	~BST();
	void insertItem(const T& data);
	bool deleteItem(const T& data);
	bool searchItem(const T& data);
	T getItem(const T& data);
	void makeEmpty();
	bool isEmpty() const;
	bool isFull() const;
	int getLength() const;
	void print() const;
	void printR() const;
	void resetTree();
	T getNextItem();

private:
	Node<T>* root;
	int length;
	Node<T>* currentPos;

	Node<T>* getItemLocation(const T& data);
	void printR(Node<T>* loc) const;
};

#endif // !BST_H

template<typename T>
inline BST<T>::BST()
{
	root = nullptr;
	length = 0;
	currentPos = nullptr;
}

template<typename T>
inline BST<T>::~BST()
{
	makeEmpty();
}

template<typename T>
inline void BST<T>::insertItem(const T& data)
{
	if (length == 0)
	{
		root = new Node<T>;
		root->data = data;
		root->left = nullptr;
		root->right = nullptr;
		length++;
	}
	else
	{
		Node<T>* temp = root;

		while (temp != nullptr)
		{
			if (data < temp->data && temp->left != nullptr)
				temp = temp->left;
			else if (data > temp->data && temp->right != nullptr)
				temp = temp->right;
			else if (data == temp->data)
				return;
			else if (data < temp->data)
			{
				temp->left = new Node<T>;
				temp = temp->left;
				temp->data = data;
				temp->left = nullptr;
				temp->right = nullptr;
				length++;
				break;
			}
			else if (data > temp->data)
			{
				temp->right = new Node<T>;
				temp = temp->right;
				temp->data = data;
				temp->left = nullptr;
				temp->right = nullptr;
				length++;
				break;
			}
		}
	}
}

template<typename T>
inline bool BST<T>::deleteItem(const T& data)
{
	Node<T>* loc = getItemLocation(data);

	if (loc != nullptr)
	{
		Node<T>* prev = loc;
		if (loc->right != nullptr)
		{
			Node<T>* temp = loc->right;

			while (temp->left != nullptr )
			{
				prev = temp;
				temp = temp->left;
			}

			if (temp->right == nullptr)
			{
				loc->data = temp->data;
				prev->left = nullptr;
				delete temp;
				return true;
			}
			else
			{
				loc->data = temp->data;
				Node<T>* tempAdj = temp->right;
				temp->data = tempAdj->data;
				temp->right = tempAdj->right;
				temp->left = tempAdj->left;
				delete tempAdj;
				return true;
			}
		}
		else if (loc->left != nullptr)
		{
			Node<T>* temp = loc->left;

			while (temp->right != nullptr)
			{
				prev = temp;
				temp = temp->right;
			}

			if (temp->left == nullptr)
			{
				loc->data = temp->data;
				prev->right = nullptr;
				delete temp;
				return true;
			}
			else
			{
				loc->data = temp->data;
				Node<T>* tempAdj = temp->left;
				temp->data = tempAdj->data;
				temp->right = tempAdj->right;
				temp->left = tempAdj->left;
				delete tempAdj;
				return true;
			}
		}
		else
		{
			delete loc;
			return true;
		}
	}
	return false;
}

template<typename T>
inline bool BST<T>::searchItem(const T& data)
{
	Node<T>* loc = root;

	while (loc != nullptr)
	{
		if (data < loc->data)
			loc = loc->left;
		else if (data > loc->data)
			loc = loc->right;
		else if (data == loc->data)
			return true;
		else
			return false;
	}

	return false;
}

template<typename T>
inline T BST<T>::getItem(const T& data)
{
	return T();
}

template<typename T>
inline void BST<T>::makeEmpty()
{
}

template<typename T>
inline bool BST<T>::isEmpty() const
{
	return false;
}

template<typename T>
inline bool BST<T>::isFull() const
{
	return false;
}

template<typename T>
inline int BST<T>::getLength() const
{
	return 0;
}

template<typename T>
inline void BST<T>::print() const
{
	if (length > 0)
	{
		std::stack<Node<T>*> s;
		Node<T>* current = root;

		std::cout << "In-Order Traversal: ";

		// Run until we have checked all nodes (current is null AND stack is empty)
		while (current != nullptr || !s.empty()) {

			// Reach the leftmost node of the current node
			while (current != nullptr) {
				s.push(current);
				current = current->left;
			}

			// Current must be null at this point, so we process the top of the stack
			current = s.top();
			s.pop();

			std::cout << current->data << " "; // Print the node

			// We have visited the node and its left subtree. Now, visit the right subtree.
			current = current->right;
		}
		std::cout << std::endl;
		
	}
}

template<typename T>
inline void BST<T>::resetTree()
{
}

template<typename T>
inline T BST<T>::getNextItem()
{
	return T();
}

template<typename T>
inline Node<T>* BST<T>::getItemLocation(const T& data)
{
	Node<T>* loc = root;

	while (loc != nullptr)
	{
		if (data < loc->data)
			loc = loc->left;
		else if (data > loc->data)
			loc = loc->right;
		else if (data == loc->data)
			return loc;
		else
			return nullptr;
	}

	return nullptr;
}

template<typename T>
inline void BST<T>::printR() const
{
	if(root != nullptr)
		printR(root);
}

template<typename T>
inline void BST<T>::printR(Node<T>* loc) const
{
	cout << loc->data << "\n";

	if (loc->left != nullptr)
		printR(loc->left);
	if (loc->right != nullptr)
		printR(loc->right);
}

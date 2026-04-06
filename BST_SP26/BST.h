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
	T deleteItem(const T& data);
	bool searchItem(const T& data);
	T getItem(const T& data);
	void makeEmpty();
	bool isEmpty() const;
	bool isFull() const;
	int getLength() const;
	void print() const;
	void resetTree();
	T getNextItem();

private:
	Node<T>* root;
	int length;
	Node<T>* currentPos;
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
inline T BST<T>::deleteItem(const T& data)
{
	return T();
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

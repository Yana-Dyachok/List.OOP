#pragma once
template <typename T>
class List
{
private:
	template <typename T>
	struct Node
	{  
		Node* nextNode;;
		T data;
		Node(T data, Node* nextNode = nullptr) {
			this->data = data;
			this->nextNode = nextNode;
		}
	};
	Node <T>* head;
	int size;
public:
	List(void);
	~List(void);
	void pushBack(T data);
	void popFront();
	void clear();
	int getSize() { return size; }
	void pushFront(T data);
	void removeAt(int index);
	void popBack();
	void insert(T data, int index); //вставка в заданий індекс
	T listCount(T x);//повертає кількість елементів зі значенням x
	T& operator[](const int index);
};


template<typename T>
inline List<T>::List()
{
	head = nullptr;
	size = 0;
}


template<typename T>
List<T>::~List()
{
	clear();
}


template<typename T>
void List<T>::pushBack(T data)
{
	if (head == nullptr) {
		head = new Node<T>(data);
	}
	else {
		Node<T>* temp = this->head;
		while (temp->nextNode != nullptr) {
			temp = temp->nextNode;
		}
		temp->nextNode= new Node<T>(data);
	}
	this->size++;
}


template<typename T>
inline void List<T>::popFront()//delete first element
{
	Node<T>* temp = head;
	head = head->nextNode;
	delete temp;
	size--;
}


template<typename T>
inline void List<T>::clear()
{
	while (size) {
		popFront();
	}
}


template<typename T>
inline T& List<T>::operator[](const int index)
{
	int count = 0;
	Node<T>* temp = this->head;
	while (temp != nullptr) {
		if (count == index) {
			return temp->data;
		}
		temp = temp->nextNode;
		count++;
	}
}


template<typename T>
inline void List<T>::pushFront(T data)
{
	head = new Node<T>(data, head);
	size++;
}


template<typename T>
inline void List<T>::removeAt(int index)
{
	if (index == 0) {
		popFront();
	}
	else {
		Node<T>* temp = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			temp = temp->nextNode;
		}
		Node<T>* DeleteMe = temp->nextNode;
		temp->nextNode = DeleteMe->nextNode;
		delete DeleteMe;
		size--;
	}
}


template<typename T>
inline void List<T>::popBack()
{
	removeAt(size-1);
}


template<typename T>
inline void List<T>::insert(T data, int index)
{
	if (index == 0) {
		pushFront(data);
	}
	else {
		Node<T>* temp = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			temp = temp->nextNode;
		}
		Node<T>* inserNode = new Node<T>(data,temp->nextNode);
		temp->nextNode = inserNode;
		size++;
	}
}


	template<typename T>
inline T List<T>::listCount(T x)
{
	    int k = 0;
		Node<T>* temp = this->head;
		while (temp != nullptr) {
			if (temp->data == x) {
				k++;
			}
			temp = temp->nextNode;
		}
		return k;
}

#include <iostream>

using namespace std;

// @brief Node class
class Node{
	friend class Queue;
private:
	string _data;
	Node *_next;
public:
	Node(void);
	Node(string);
	Node(string,Node*);
};

// @brief Node constructor
// @retval n/a
Node::Node(void)
{
	_data = "";
	_next = NULL;
}

// @brief Node constructor
// @param data (IN) data to be stored
// @retval n/a
Node::Node(string data)
{
	_data = data;
	_next = NULL;
}

// @brief Node constructor
// @param data (IN) data to be stored
// @param next (IN) address of Node object
// @retval n/a
Node::Node(string data, Node *next)
{
	_data = data;
	_next = next;
}

// @brief Queue class
class Queue{
private:
	int _size;
	Node *_front;
	Node *_back;
public:
	Queue(void);
	~Queue(void);
	void enqueue(string);
	void dequeue(void);
	string front(void);
	string back(void);
	int size(void);
	bool empty(void);
};

// @brief Queue constructor
// @retval n/a
Queue::Queue(void)
{
	_size = 0;
	_front = NULL;
	_back = NULL;
}

// @brief Queue deconstructor will delete any Node
// 			objects that are still sitting on 
//			the queue
// @retval n/a
Queue::~Queue(void)
{
	Node *temp = NULL;
	while(!this->empty())
	{
		temp = _front;
		this->dequeue();
		delete temp;
	}
	temp = NULL;
}

// @brief create new Node object to store data
//			and place at front of queue
// @param data (IN) data to be stored
// @retval n/a
void Queue::enqueue(string data)
{
	if(_front == NULL)
	{
		_front = new Node(data,NULL);
		_back = _front;
	}
	else
	{
		_back->_next = new Node(data,NULL);
		_back = _back->_next;
	}
}

// @brief remove and delete Node object from
//			the queue
// @retval n/a
void Queue::dequeue(void)
{
	Node *temp = _front;
	if(temp)
	{
		_front = _front->_next;
		delete temp;
	}
	temp = NULL;
}

// @brief return data located at front
// of queue
// @retval data from front of queue (string)
string Queue::front(void)
{
	return _front->_data;
}

// @brief return data located at back
// of queue
// @retval data from back of queue (string)
string Queue::back(void)
{
	return _back->_data;
}

// @brief return current size of queue
// @retval size of queue (int)
int Queue::size(void)
{
	return _size;
}

// @brief indicate whether or not the queue
//			is empty
// @retval true if empty, false if not (bool)
bool Queue::empty(void)
{
	return (_front == NULL);
}

int main(void)
{
	Queue my_queue;

	my_queue.enqueue("Darth");
	my_queue.enqueue("Chewie");
	my_queue.enqueue("Obi Wan");

	cout << my_queue.back() << endl;

	while(!my_queue.empty())
	{
		cout << "Servicing..." << my_queue.front() << endl;
		my_queue.dequeue();
	}

	return 0;
}
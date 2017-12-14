#ifndef QUE
#define QUE
class Customer
{
private:
	long arrive;
	int ptime;
public:
	Customer() { arrive = ptime = 0; }
	void set_time(long when);
	long when() { return arrive; }
	int processtime() { return ptime; }
};

class Queue
{	
private:
	struct Node
	{
		Customer customer;
		struct Node * next;
	};
	enum { Q_SIZE = 10 };
	Node * first;
	Node * last;
	int number;
	const int qsize;
	Queue(const Queue & q) : qsize(0){}
	Queue & operator=(const Queue & q)
	{
		return *this;
	}
public:
	Queue(int qs = Q_SIZE);
	~Queue();
	bool isempty() const;
	bool isfull() const;
	int queuecount() const;
	bool enqueue(const Customer &item);
	bool dequeue(Customer &item);
};
#endif // !QUE


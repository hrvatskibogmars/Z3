#define brojElemenata 100
typedef int element;

struct pacijent
{
	int a, b, c, d,e;
	std::string imePacijenta;
	std::string prezimePacijenta;
	std::string datumRodjenja;
	std::string spol;
};

typedef pacijent elementtype;

struct que
{
	elementtype elements[brojElemenata];
	element front,rear;
};

int AddOne (int i)
{
	return ((i+1)% brojElemenata);
}

bool isEmpty(que *red)
{
	if (AddOne(red->rear) == red->front)
		return true;
	else
		return false;
}

elementtype FrontQ(que *red)
{
	if (isEmpty(red))
		std::cout << "Red je prazan";
	else
		return (red->elements[red->front]);
	
}

void EnQueueQ(elementtype x, que *red)
{
	if (AddOne(AddOne(red->rear))==(red->front))
		std::cout << "Red je pun";
	else
		red->rear = AddOne(red->rear);
		red->elements[red->rear] = x;
}

void DeQueueQ(que *red)
{
	if (isEmpty(red))
		std::cout << "Red je prazan";
	else
		red->front = AddOne(red->front);		
}

void InitQ(que *red)
{
	red->front = 0;
    red->rear = brojElemenata-1;
}

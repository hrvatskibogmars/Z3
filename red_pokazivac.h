struct pacijent
{
	int a, b, c, d,e;
	std::string imePacijenta;
	std::string prezimePacijenta;
	std::string datumRodjenja;
	std::string spol;
};

typedef pacijent elementtype;

struct qu
{
       elementtype b;
       qu *sljedeci;
};

struct que
{
       qu *front, *rear;
};

void InitQ(que *red)
{
     qu *glava = new qu;
     glava->sljedeci = NULL;
     red->front = glava;
     red->rear = glava;
}

bool isEmpty(que *red)
{
     if(red->rear == red->front)
     	return true;
     else
     	return false;
}

void EnQueueQ(elementtype x, que *red)
{
     qu *pom;
     pom = new qu;
     pom->b = x;
     pom->sljedeci = NULL;
     red->rear->sljedeci = pom;
     red->rear = pom;
}

elementtype FrontQ(que *red)
{
      if(isEmpty(red))
      	std::cout << "Red je prazan!";
      else
      	return (red->front->sljedeci->b);
}

void DeQueueQ(que *red)
{
     qu *pom;
     if(isEmpty(red))
     	std::cout << "Red je prazan!";
     else
	{
          pom = red->front;
          red->front = red->front->sljedeci;
          delete pom;
	}
}

#include <iostream>

/*namespace a
{
	int global_var = 15;
}

int global_var = 10;

using namespace std;

int main()
{
	int global_var = 5;
	cout << "Namespace value: " << a::global_var << "\nGlobal value: " << ::global_var << "\nLocal value: " << global_var << endl;
	return 0;
}*/

/*using namespace std;

int fun(int x)
{
	return ++x;
}

int fun(int *x)
{
	return ++*x;
}

int funr(int& x)
{
	return ++x;
}

int main()
{
	int x = 7;

	fun(x);
	cout << x << endl;

	fun(&x);
	cout << x << endl;

	funr(x);
	cout << x << endl;
}*/

/*using namespace std;

namespace test
{
int a = 5;
}
enum E1 {a=1, b=3, c=-5};
enum E3 {e, f};

enum class EC1 {a=1,b,c};
enum class EC2 {a,b=5,c};

int main()
{
	EC1 ec1 = EC1::a;
	cout << (int)ec1 << endl;
}*/

/*using pint1 = int*;
typedef int* pint2;
using namespace std;

int main()
{
	pint1 x = new int;
	pint2 y = new int[2];

	*x = 10;
	y[0] = 5;
	y[1] = 12;

	cout << *x << " " << y[0] << " " << y[1] <<  endl;

	delete x;
	delete[] y;

	x = nullptr;
	y = nullptr;

	return 0;
}*/

/*using namespace std;

class ptr
{
private:
	int* x;
	int y;
public:
	ptr() {}
	ptr(int x, int y)
	{
		this->x = new int;
		*this->x = x;
		this->y = y;
	}
	~ptr()
	{
		delete x;
		x = nullptr;
		cout << "adres po destrukcji: " << &x << " adres wskaznika po destrukcji: " << x << endl;
	}
	ptr(const ptr& p)
	{
		this->x = new int;
		*x = *p.x;
		this->y = p.y;
		cout << "test2" << endl;
		//cout << *x << " adres: " << &x << " adres wskaznika: " << x << endl;
	}

	ptr& operator=(const ptr& p)
	{
		this->x = new int;
		*x = *p.x;
		this->y = p.y;
		cout << "test" << endl;
		return *this;
	}

	void getX()
	{
		cout << *this->x << endl;
	}
	void setX(int x)
	{
		*this->x = x;
	}

	void getY()
	{
		cout << this->y << endl;
	}

	void setY(int y)
	{
		this->y = y;
	}
	/*void swap(ptr& p1, ptr& p2)
	{
		ptr tmp(p1);
		p1 = p2;
		p2 = tmp;
	}*/
	/*void getLog()
	{
		cout << "Wartosc x: " << *this->x << " adres x: " << &this->x << " wartosc y: " << this->y << endl;
	}

	void swap(ptr& p1, ptr& p2)
	{
		ptr tmp = move(p1);
		p1 = move(p2);
		p2 = move(tmp);
	}

	ptr(ptr&& p)
	{
		this->x = p.x;
		this->y = p.y;
		p.x = nullptr;
	}

	ptr& operator=(ptr&& p)
	{
		this->x = p.x;
		this->y = p.y;
		p.x = nullptr;
		return *this;
	}
};

int main()
{*/
	/*ptr p1(15, 25);
	p1.getLog();
	ptr p2;
	p2 = p1;
	p2.getLog();*/
	//ptr p2 /*= p1*/;
	//p2 = p1;
	//ptr p2(p1);
	//p2.setX(20);
	/*p2.getX();
	p1.getX();
	p2.getY();
	p1.getY();*/

	/*ptr p1(1, 1);
	ptr p2(2, 2);

	p1.getLog();
	p2.getLog();

	p1.swap(p1, p2);

	p1.getLog();
	p2.getLog();

	return 0;
}*/

/*class X
{
public:
	virtual void f()
	{
		std::cout << "X";
	}
	virtual ~X() {}
};

class Y : public X
{
public:
	void f()
	{
		std::cout << "Y";
	}
};

int main()
{
	Y y;
	X vx = y;
	X& rx = y;
	X* px = &y;

	y.f();
	vx.f();
	rx.f();
	px->f();
}*/

/*class Holder
{
public:
	int x;
	Holder():x(0) {std::cout << "Default with 0" << std::endl;};
	Holder(int x):x(x){std::cout << "Default with pushed " << x << std::endl;};
	Holder operator+(const Holder& h)
	{
		this->x += h.x;
		return *this;
	}
	Holder operator*(const Holder& h)
	{
		this->x *= h.x;
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& s, const Holder& h)
	{
		s << "Holder x = " << h.x << std::endl;
		return s;
	}

	static void* operator new(std::size_t sz)
	{
		std::cout << "New operator" << std::endl;
		return ::operator new(sz);
	}

	static void operator delete(void* p)
	{
		std::cout << "Delete operator" << std::endl;
		return ::operator delete(p);
	}
};

int main()
{
	//Holder h1, h2, h3;
	//h1.x = 2;
	//h2.x = 3;
	//h3.x = 4;
	//h1 = h1 + h2 * h3;

	std::cout << h1 << std::endl;

	Holder* ph = new Holder(3), *ph2 = ::new Holder(4);
	*ph = *ph **ph2;
	std::cout << *ph << std::endl;

	::delete ph;
	std::cout << "test" << std::endl;
	delete ph2;
}*/


template <typename T>
class Holder
{
public:
	T x;
	Holder():x(0) {};
	Holder(T x);
	Holder operator+(const Holder& h)
	{
		this->x += h.x;
		return *this;
	}
	Holder operator*(const Holder& h)
	{
		this->x *= h.x;
		return *this;
	}
};
template<typename T>
Holder<T>::Holder(T x):x(x) {};

int main()
{
	Holder<int> h1, h2, h3;
	h1.x = 2;
	h2.x = 3;
	h3.x = 4;

	h1.x = 2;
	h2.x = 3;
	h3.x = 4;
	h1 = h1 * h2 + h3;

	std::cout << h1.x << std::endl;

	Holder<float>* ph = new Holder<float>(3);


	return 0;
}

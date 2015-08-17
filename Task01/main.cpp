#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <random>
#include <array>
#include <list>

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
	}
	void getLog()
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
{
	//ptr p1(15, 25);
	//p1.getLog();
	//ptr p2;
	//p2 = p1;
	//p2.getLog();
	//ptr p2 = p1;
	//p2 = p1;
	//ptr p2(p1);
	//p2.setX(20);
	//p2.getX();
	//p1.getX();
	//p2.getY();
	//p1.getY();

	ptr p1(1, 1);
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
		cout << "X";
	}
	virtual ~X() {}
};

class Y : public X
{
public:
	void f()
	{
		cout << "Y";
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
	Holder():x(0) {cout << "Default with 0" << endl;};
	Holder(int x):x(x){cout << "Default with pushed " << x << endl;};
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

	friend ostream& operator<<(ostream& s, const Holder& h)
	{
		s << "Holder x = " << h.x << endl;
		return s;
	}

	static void* operator new(size_t sz)
	{
		cout << "New operator" << endl;
		return ::operator new(sz);
	}

	static void operator delete(void* p)
	{
		cout << "Delete operator" << endl;
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

	cout << h1 << endl;

	Holder* ph = new Holder(3), *ph2 = ::new Holder(4);
	*ph = *ph **ph2;
	cout << *ph << endl;

	::delete ph;
	cout << "test" << endl;
	delete ph2;
}*/

/*template <typename T>
class Holder
{
public:
	T x;
	Holder():x(0) {};
	Holder(T x);
	template<typename T1, typename T2>
	friend Holder<T1> operator+(const Holder<T1>& h1, const Holder<T2>& h2);
	//Holder operator+(const Holder& h)
	//{
	//	Holder<T> copy(*this);
	//	copy.x = copy.x + h.x;
	//	return copy;
	//}
	Holder operator*(const Holder& h)
	{
		Holder<T> copy(*this);
		copy.x = copy.x * h.x;
		return copy;
	}

	friend ostream& operator<<(ostream& s, const Holder& h)
	{
		s << "Holder x = " << h.x << endl;
		return s;
	}
};
template<typename T>
Holder<T>::Holder(T x):x(x) {};

template<typename T1, typename T2>
Holder<T1> operator+(const Holder<T1>& h1, const Holder<T2>& h2)
{
	Holder<T1> copy(h1);
	copy.x = copy.x + h2.x;
	return copy;
}

int main()
{
	Holder<int> h1;
	Holder<float> h2;
	Holder<l+ ong> h3;
	h1.x = 2;
	h2.x = 3;
	h3.x = 4;

	h1.x = 2;
	h2.x = 3;
	h3.x = 4;
	h1 = h1 + h2;

	//cout << h1 << endl;
	//cout << h2 << endl;

	Holder<float>* ph = new Holder<float>(3);

	Holder<Holder<int>>x, y;
	//x.x.x = 1;
	//y.x.x = 2;
	x = x + y;
	cout << x << endl;

	return 0;
}*/

using namespace std;
template <typename T> T maxt(T t1, T t2)
{
	cout << "Template 1" << endl;
	return (t1 > t2) ? t1:t2;
}

template <typename T1, typename T2> T1 maxt(T1 t1, T2 t2)
{
	cout << "Template 2" << endl;
	return (t1 > t2) ? t1:t2;
}

float maxt(float t1, float t2)
{
	cout << "Float" << endl;
	return (t1 > t2) ? t1:t2;
}

struct convert
{
    void operator()(char& ch)
    {
    	if(isupper(ch))
    		ch = tolower(ch);
    	else
    		ch = toupper(ch);
    }
};

void myfun(char& ch)
{
	convert()(ch);
}

class Randomizer
{
//		string const c("Exemplary");
//		s.assign(c);
//		cout << c << "==" << s << endl;
//
//		s.assign(c, 0, c.length()-1);
//		cout << s << endl;
//		s.assign(string("C++ by ") + string("example"));
//		cout << s << endl;
//
//		s.assign("C-style string", 7);
//		cout << s << endl; // "C-style"
//
//		s.assign("C-style\0string");
//		cout << s << endl; // "C-style"
//
//		char mutable_c_str[] = "C-style string";
//		s.assign(begin(mutable_c_str), end(mutable_c_str)-1);
//		cout << s << endl; // "C-style string"
//
//		s.assign({ 'C', '-', 's', 't', 'y', 'l', 'e' });
//		cout << s << endl; // "C-style"
//
//		s.assign("Exemplary");
//
//		//FRONT
//		char& f = s.front();
//		f = 'e';
//		cout << &f << endl;
//		f = 'E';
//		cout << f << endl;
//		cout << &f << endl;
//
//		//CLEAR
//		s.clear();
//		cout << "TEST " << s << endl;
//
//		//PUSH_BACK
//		s.assign("Exemplary");
//		char ch = 'z';
//		s.push_back(ch);
//		cout << s << endl;
//
//		//POP_BACK
//		s.pop_back();
//		cout << s << endl;
//
//		//REPLACE
//		string str("The quick brown fox jumps over the lazy dog.");
//		str.replace(10, 5, "red"); // (4)
//		str.replace(str.begin(), str.begin() + 3, 1, 'A'); // (5)
//		cout << str << endl;
//
//		//FIND_FIRST_OF
//		string search_str = string("o");
//		const char* search_cstr = "Good Bye!";
//		cout << str.find_first_of(search_str) << endl;
//		cout << str.find_first_of(search_str, 15) << endl;
//		cout << str.find_first_of(search_cstr) << endl;
//		cout << str.find_first_of(search_cstr, 0, 4) << endl;
//		cout << str.find_first_of('w') << endl;
//
//		for(string::iterator x = str.begin(); x!= str.end(); ++x)
//		{
//			cout << *x << " ";
//		}
//
//		cout << endl;
//		for (auto x:str)
//		{
//			cout << x;
//		}
//
//		cout << endl;
//
//		for_each(str.begin(), str.end(), convert());
//		cout << str << endl;
//
//		for_each(str.begin(), str.end(), myfun);
//		cout << str << endl;
//
//		for_each(str.begin(), str.end(), [](char& ch) {convert()(ch);});
//		cout << str << endl;
//
//		for_each(str.begin(), str.end(), convert());
//		cout << str << endl;
private:
	random_device rd;
	mt19937 gen;
public:
	Randomizer()
	{
		this->gen = mt19937(this->rd());
	}
	int generateRandom(int min, int max)
	{
		uniform_int_distribution<> dis(min, max);
		return dis(this->gen);
	}
};

enum class Gender {M, F};

class Person
{
public:
	string name;
	string surname;
	int age;
	Gender gender;

	struct Sum {
	    Sum() { sum = 0; }
	    void operator()(Person& p) { sum += p.age; }

	    int sum;
	};
	Sum sumage;

	void generatePerson()
	{
		Randomizer random_object;
		int nameLengthMin = 3;
		int nameLengthMax = 8;
		int surnameLengthMin = 4;
		int surnameLengthMax = 15;

		age = random_object.generateRandom(0, 99);
		gender = static_cast<Gender>(random_object.generateRandom(0, 1));

		int nameLength = random_object.generateRandom(nameLengthMin, nameLengthMax);
		for (int i = 0; i < nameLength; ++i)
			name.append(1, (char)random_object.generateRandom(97,122));

		int surnameLength = random_object.generateRandom(surnameLengthMin, surnameLengthMax);
		for (int i = 0; i < surnameLength; ++i)
			surname.append(1, (char)random_object.generateRandom(97,122));
	}

	friend ostream& operator<<(ostream& s, const Person& p)
	{
		s << "|Name: " << p.name << endl;
		s << "|Surname: " << p.surname << endl;
		s << "|Age: " << p.age << endl;
		if (p.gender == Gender::M)
			s << "|Sex: " << "Male" << endl;
		else
			s << "|Sex: " << "Female" << endl;
		return s;
	}
	bool operator<(const Person & lhs)
	{
		if (this->name == lhs.name)
			return this->surname < lhs.surname;
		return this->name < lhs.name;
	}
};

int main()
{
//	cout << maxt(1, 2) << endl;
//	cout << maxt(1.1, 2.2) << endl;
//	cout << maxt(1.1f, 2.2f) << endl;
//	cout << maxt('1', '2') << endl;
//	cout << maxt(1, '2') << endl;
//	cout << maxt<int>(1.1f, 2.2f) << endl;
//	cout << maxt<float>(1.1f, 2.2f) << endl;
//	cout << maxt<char>(1, '2') << endl;
//	cout << maxt<char, char>(1, '2') << endl;
//
//	ASSIGN
//	string s;
//	s.assign(4, '=');
//	cout << s << endl;

//	string const c("Exemplary");
//	s.assign(c);
//	cout << c << "==" << s << endl;
//
//	s.assign(c, 0, c.length()-1);
//	cout << s << endl;
//	s.assign(string("C++ by ") + string("example"));
//	cout << s << endl;
//
//	s.assign("C-style string", 7);
//	cout << s << endl; // "C-style"
//
//	s.assign("C-style\0string");
//	cout << s << endl; // "C-style"
//
//	char mutable_c_str[] = "C-style string";
//	s.assign(begin(mutable_c_str), end(mutable_c_str)-1);
//	cout << s << endl; // "C-style string"
//
//	s.assign({ 'C', '-', 's', 't', 'y', 'l', 'e' });
//	cout << s << endl; // "C-style"
//
//	s.assign("Exemplary");
//
//	//FRONT
//	char& f = s.front();
//	f = 'e';
//	cout << &f << endl;
//	f = 'E';
//	cout << f << endl;
//	cout << &f << endl;
//
//	//CLEAR
//	s.clear();
//	cout << "TEST " << s << endl;
//
//	//PUSH_BACK
//	s.assign("Exemplary");
//	char ch = 'z';is not
//	s.push_back(ch);
//	cout << s << endl;
//
//	//POP_BACK
//	s.pop_back();
//	cout << s << endl;
//
//	//REPLACE
//	string str("The quick brown fox jumps over the lazy dog.");
//	str.replace(10, 5, "red"); // (4)
//	str.replace(str.begin(), str.begin() + 3, 1, 'A'); // (5)
//	cout << str << endl;
//
//	//FIND_FIRST_OF
//	string search_str = string("o");
//	const char* search_cstr = "Good Bye!";
//	cout << str.find_first_of(search_str) << endl;
//	cout << str.find_first_of(search_str, 15) << endl;
//	cout << str.find_first_of(search_cstr) << endl;
//	cout << str.find_first_of(search_cstr, 0, 4) << endl;
//	cout << str.find_first_of('w') << endl;
//
//	for(string::iterator x = str.begin(); x!= str.end(); ++x)
//	{
//		cout << *x << " ";
//	}
//
//	cout << endl;
//	for (auto x:str)
//	{
//		cout << x;
//	}
//
//	cout << endl;
//
//	for_each(str.begin(), str.end(), convert());
//	cout << str << endl;
//
//	for_each(str.begin(), str.end(), myfun);
//	cout << str << endl;
//
//	for_each(str.begin(), str.end(), [](char& ch) {convert()(ch);});
//	cout << str << endl;
//
//	for_each(str.begin(), str.end(), convert());
//	cout << str << endl;

//	Randomizer r1;
//	int random_number = r1.generateRandom(20, 500);
//	cout << random_number << endl;
//
//	Person persons[10];
//	for(int i = 0; i < 10; ++i)
//		persons[i].generatePerson();
//	for (int i = 0; i < 10; ++i)
//	{
//		cout << "Person " << i+1 << endl;
//		cout << persons[i] << endl;
//	}

	array<Person, 10> persons;
//	int i = 1;
//
	for (auto& p:persons)
	{
		p.generatePerson();
	}
//	for (auto& p:persons)
//	{
//		cout << "Person " << i << endl;
//		cout << p << endl;
//		++i;
//	}
//	int i = 1;
//	for (auto it = persons.begin(); it != persons.end(); ++it)
//	{
//		cout << "Person " << i << endl;
//		cout << *it << endl;
//		++i;
//	}
//
//	for_each(persons.begin(), persons.end(), Person());
//
//	for (int i = 0; i < persons.size(); ++i)
//	{
//		cout << "Person " << i+1 << endl;
//		cout << persons[i] << endl;
//	}


	//ZROBIC REVERSE CZWORKAMI 1 2 3 4 5 6 7 8 9 10 4 3 2 1 8 7 6 5 10 9
//	vector<Person> personsVec;
//
//	for (int i = 0; i < 10; i++)
//	{
//		personsVec.push_back(Person());
//		personsVec[i].generatePerson();
//		cout << "Person " << i+1 << endl;
//		cout << personsVec[i] << endl;
//	}
//
//	int personsVecSize = ceil(personsVec.size() / 4);
//	cout << personsVecSize;
//
//	for (unsigned int i = 0; i < personsVec.size(); i += 4)
//	{
//		reverse(personsVec.begin(), personsVec.end());
//	}
//
//	for (int i = 0; i < 10; i++)
//	{
//		cout << "Person " << i+1 << endl;
//		cout << personsVec[i] << endl;
//	}

	list<Person> personsList(10, Person());

	for (auto& p:personsList)
	{
		p.generatePerson();
	}

	Person::Sum s = for_each(personsList.begin(), personsList.end(), Person::Sum());

	int i = 1;
	for (list<Person>::iterator it = personsList.begin(); it != personsList.end(); it++)
	{
		cout << "Person: " << i << endl;
		cout << *it << endl;
		++i;
	}
	cout << "Sum of age: " << s.sum << endl;

	i = 1;
	personsList.sort();
	for (list<Person>::iterator it = personsList.begin(); it != personsList.end(); it++)
	{
		cout << "Person: " << i << endl;
		cout << *it << endl;
		++i;
	}
}

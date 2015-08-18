//#include <iostream>
//#include <string>

#include "MemPoolTemp.h"
#include "Stats.h"

int main()
{
	{
		std::cout << "MEMORY POOL" << std::endl;
		std::cout << "-----------" << std::endl;
		MemPool::MemoryPool obj(2);
		std::string* p = obj.allocate();
		std::string* q = obj.allocate();
		std::string* w = obj.allocate();

		std::cout << p << std::endl;
		std::cout << q << std::endl;
		std::cout << w << std::endl;

		obj.deallocate(p);
		obj.deallocate(q);
		obj.deallocate(w);

		std::string* z = obj.allocate();
		std::string* x = obj.allocate();

		std::string* c = nullptr;
		obj.deallocate(c);
	}
	std::cout << std::endl;
	{
		std::cout << "MEMORY POOL TEMPLATE" << std::endl;
		std::cout << "--------------------" << std::endl;
		MemPoolTemplate::MemoryPool<int> obj(2);
			int* p = obj.allocate();
			int* q = obj.allocate();
			int* w = obj.allocate();

			std::cout << p << std::endl;
			std::cout << q << std::endl;
			std::cout << w << std::endl;

			obj.deallocate(p);
			obj.deallocate(q);
			obj.deallocate(w);

			int* z = obj.allocate();
			int* x = obj.allocate();

			int* c = nullptr;
			obj.deallocate(c);
	}

	{
		std::cout << std::endl;
		std::cout << "STATS" << std::endl;
		std::cout << "-----" << std::endl;
		Stats obj;
		std::string test = "test";
		std::string test2 = "test2";
		std::string test3 = "test";
		obj.push(test);
		obj.push(test2);
		obj.push(test3);

		obj.printStats();
	}

	return 0;
}

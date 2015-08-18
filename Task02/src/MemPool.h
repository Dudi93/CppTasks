#include <iostream>
#include <string>
#include <vector>

namespace MemPool
{
class MemoryPool
{
private:
	std::vector <void*> m_pAdresses;
public:
	MemoryPool(int size)
	{
		std::string** test = new std::string*[size];
		for (int i = 0; i < size; ++i)
		{
			void* adress = &test[i];
			m_pAdresses.push_back(adress);
			std::cout << "Dodano do puli: " << adress << std::endl;
		}
		delete[] test;
	}
	~MemoryPool()
	{
	}

	std::string* allocate()
	{
		if (m_pAdresses.size() == 0)
		{
			std::string* adress = new std::string;
			m_pAdresses.push_back(adress);
			delete adress;
		}
		std::string* stringAdress = static_cast<std::string*>(m_pAdresses[m_pAdresses.size()-1]);
		m_pAdresses.pop_back();
		std::cout << "Pobrano: " << stringAdress << std::endl;
		return stringAdress;
	}
	bool deallocate(std::string* ptr)
	{
		if (ptr == nullptr)
		{
			std::cout << "Can't delete, nullptr" << std::endl;
			return false;
		}
		m_pAdresses.push_back(ptr);
		std::cout << "Wrzucono: " << m_pAdresses[m_pAdresses.size()-1] << std::endl;
		std::cout << "Deleted" << std::endl;
		return true;
	}
};
}

#include "MemPool.h"

namespace MemPoolTemplate
{
template <typename T>
class MemoryPool
{
private:
	std::vector <void*> m_pAdresses;
public:
	MemoryPool(int size)
	{
		T** test = new T*[size];
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

	T* allocate()
	{
		if (m_pAdresses.size() == 0)
		{
			T* adress = new T;
			m_pAdresses.push_back(adress);
			delete adress;
		}
		T* stringAdress = static_cast<T*>(m_pAdresses[m_pAdresses.size()-1]);
		m_pAdresses.pop_back();
		std::cout << "Pobrano: " << stringAdress << std::endl;
		return stringAdress;
	}
	bool deallocate(T* ptr)
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

#include <iostream>
#include <map>
#include <string>

class Stats
{
private:
	std::map <std::string, int> statMap;
public:
	void push(const std::string & p)
	{
		auto it = statMap.find(p);
		if(it != statMap.end())
		{
			it->second = it->second + 1;
		}
		else
			statMap[p] = 1;
	}
	void printStats(void)
	{
		for (auto it: statMap)
		{
			std::cout << it.first << " " << it.second << std::endl;
		}
	}
};

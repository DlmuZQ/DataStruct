#pragma once
#include <vector>
class DSSort
{
public:
	~DSSort();
	void BubbleSort(std::vector<int> &vInData);
	void SelectSort(std::vector<int> &vInData);

friend DSSort& theSort();

private:
	DSSort(const DSSort &){}
	DSSort();

	
};


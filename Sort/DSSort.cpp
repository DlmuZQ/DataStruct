#include "DSSort.h"



DSSort::DSSort()
{
}
/*
冒泡排序的改进
多设置了一个flag，用于标记数组是否已经有序
*/
void DSSort::BubbleSort(std::vector<int>& vInData)
{
	bool bflag = true;
	int i, j;

	for (i = 0; i < vInData.size() && bflag; i++)
	{
		bflag = false;
		for (j = vInData.size() - 2 - i; j >= i; j--)
		{
			if (vInData[j] > vInData[j + 1])
			{
				std::swap(vInData[j], vInData[j + 1]);
				bflag = true;
			}		
		}
	}
}


DSSort::~DSSort()
{
}

DSSort & theSort()
{
	static DSSort Sort;
	return Sort;  //返回唯一一个排序对象
}

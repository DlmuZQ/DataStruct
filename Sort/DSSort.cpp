#include "DSSort.h"



DSSort::DSSort()
{
}
/*
ð������ĸĽ�
��������һ��flag�����ڱ�������Ƿ��Ѿ�����
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

void DSSort::SelectSort(std::vector<int>& vInData)
{
	int i, j, min;
	for (i = 0; i < vInData.size(); i++) {
		min = i;
		for (j = i + 1; j < vInData.size(); j ++)
		{
			if (vInData[i] > vInData[j])
				min = j;
		}
		if (min != i)
			std::swap(vInData[i], vInData[min]);
	}
}


DSSort::~DSSort()
{
}

DSSort & theSort()
{
	static DSSort Sort;
	return Sort;  //����Ψһһ���������
}

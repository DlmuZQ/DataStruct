#include "DSSort.h"



DSSort::DSSort()
{
}

void DSSort::HeadAdjust(std::vector<int> &vInData, int indx, int squre)
{
	int temp, j;
	temp = vInData[indx];
	
	for (j = 2 * indx + 1; j <= squre; j *= 2) {
		if (j < squre && vInData[j] < vInData[j + 1])
			++j;
		if (temp >= vInData[j])
			break;
		vInData[indx] = vInData[j];
		indx = j;
	}

	vInData[indx] = temp;
}

void DSSort::Merge(std::vector<int> &vIn, std::vector<int> &vOut, int i, int m, int n)
{
	int j, k, l;

	for (j = m + 1, k = i; j <= n&&i <= m; k++) {
		if (vIn[j] < vIn[i])
			vOut[k] = vIn[j++];
		else
			vOut[k] = vIn[i++];
	}
	if (j <= n) {
		for (l = 0; l <= n - j; l++)
			vOut[k + l] = vIn[j + l];
	}
	if (i <= m) {
		for (l = 0; l <= m - i; l++)
			vOut[k + l] = vIn[i + l];
	}
}

void DSSort::MergePass(std::vector<int>& vIn, std::vector<int>& vOut, int s, int n)
{
	int i;
	for (i = 0; i <= n - 2 * s; i += 2 * s) {
		Merge(vIn, vOut, i, i + s, i + 2 * s);
	}
	if (i < n - s)
		Merge(vIn, vOut, i, i + s, n);
	else
		for (int j = i; j <= n; j++)
			vOut[j] = vIn[j];
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


void DSSort::InsertSort(std::vector<int> &vInData)
{
	int i,j;
	for (i = 1; i < vInData.size(); i++) {
		for (j = i; j >= 1; j--) {
			if (vInData[j] < vInData[j - 1])
				std::swap(vInData[j], vInData[j - 1]);
			else
				break;
		}
	}
}

void DSSort::ShellSort(std::vector<int>& vInData)
{
	int i, j;
	int iIncrement = vInData.size();//增量序列

	do 
	{
		iIncrement = iIncrement / 3 + 1;
		for (i = iIncrement; i < vInData.size(); i++) {
			for (j = i - iIncrement; j >= 0 && vInData[j] > vInData[j + iIncrement]; j -= iIncrement)
				std::swap(vInData[j], vInData[j + iIncrement]);
		}
	} while (iIncrement > 1);	
}

void DSSort::HeapSort(std::vector<int>& vInData)
{
	/*
	首先建立大顶堆
	其次将堆顶与最后一个元素交换，调整堆
	*/
	int i;
	for (i = vInData.size() / 2 - 1; i >= 0; i--)
		HeadAdjust(vInData, i, vInData.size() - 1);

	for (i = vInData.size() - 1; i >= 0; i--) {
		std::swap(vInData[i], vInData[0]);
		HeadAdjust(vInData, 0, i - 1);
	}
}

void DSSort::MergeSort(std::vector<int> &vInData)
{
	std::vector<int> vTemp;
	//vTemp.reserve(vInData.size());
	vTemp.resize(vInData.size());
	int k = 1;
	while (k < vInData.size())
	{
		MergePass(vInData, vTemp, k, vInData.size());
		k = 2 * k;
		MergePass(vTemp, vInData, k, vInData.size());
		k = 2 * k;
	}
}

void DSSort::QiuckSort(std::vector<int> &vInData)
{
	QiuckSortImp(vInData,vInData.size(),0,vInData.size()-1);
}

void DSSort::QiuckSortImp(std::vector<int> &vInData,int length, int start, int end)
{
	int indx = Partition(vInData, length, start, end);
	if (indx > start)
		QiuckSortImp(vInData, length, start, indx - 1);
	if (indx < end)
		QiuckSortImp(vInData, length, indx + 1, end);
}

int DSSort::Partition(std::vector<int> &vInData, int length, int start, int end)
{
	if (vInData.size() <= 0 || length < 0 || start < 0 || end >= length)
		return -1;
	int indx;
	if (end == start)
		indx = start;
	else
		indx= std::rand() % (end - start) + start;
	std::swap(vInData[indx], vInData[end]);

	int small = start - 1;
	for (indx = start; indx < end; indx++) {
		if (vInData[indx] < vInData[end]) {
			++small;
			if (small != indx)
				std::swap(vInData[small], vInData[indx]);
		}
	}
	++small;
	std::swap(vInData[small], vInData[end]);

	return small;
}

DSSort::~DSSort()
{
}

DSSort & theSort()
{
	static DSSort Sort;
	return Sort;  //返回唯一一个排序对象
}

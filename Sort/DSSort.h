#pragma once
#include <vector>
//冒 择 路（入） 兮（希） 快 归 堆
class DSSort
{
public:
	~DSSort();
	void BubbleSort(std::vector<int> &vInData);
	void SelectSort(std::vector<int> &vInData);
	void InsertSort(std::vector<int> &vInData);
	void ShellSort(std::vector<int> &vInData);
	void HeapSort(std::vector<int> &vInData);

	//有问题
	void MergeSort(std::vector<int> &vInData);

	void QiuckSort(std::vector<int> &vInData);
	
	friend DSSort& theSort();

private:
	DSSort(const DSSort &) {}
	DSSort();

	void QiuckSortImp(std::vector<int> &vInData,int length,int start, int end);
	int Partition(std::vector<int> &vInData, int length, int start, int end);

	//调整堆排序
	void HeadAdjust(std::vector<int> &vInData, int indx, int squre);

	//归并排序中的merge函数
	void Merge(std::vector<int> &vIn, std::vector<int> &vOut, int i, int m, int n);
	void MergePass(std::vector<int> &vIn, std::vector<int> & vOut, int s, int n);
};
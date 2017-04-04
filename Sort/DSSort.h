#pragma once
#include <vector>
//ð �� ·���룩 �⣨ϣ�� �� �� ��
class DSSort
{
public:
	~DSSort();
	void BubbleSort(std::vector<int> &vInData);
	void SelectSort(std::vector<int> &vInData);
	void InsertSort(std::vector<int> &vInData);
	void ShellSort(std::vector<int> &vInData);
	void HeapSort(std::vector<int> &vInData);

	//������
	void MergeSort(std::vector<int> &vInData);

	void QiuckSort(std::vector<int> &vInData);
	
	friend DSSort& theSort();

private:
	DSSort(const DSSort &) {}
	DSSort();

	void QiuckSortImp(std::vector<int> &vInData,int length,int start, int end);
	int Partition(std::vector<int> &vInData, int length, int start, int end);

	//����������
	void HeadAdjust(std::vector<int> &vInData, int indx, int squre);

	//�鲢�����е�merge����
	void Merge(std::vector<int> &vIn, std::vector<int> &vOut, int i, int m, int n);
	void MergePass(std::vector<int> &vIn, std::vector<int> & vOut, int s, int n);
};
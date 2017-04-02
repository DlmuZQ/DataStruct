#include "DSHash.h"

DSHash::DSHash(int TableSize)
{
	_hTable = new HasTable;
	_hTable->count = TableSize;
	_hTable->elem = new int[TableSize];
	for (int i =0; i<TableSize ; i++)
	{
		_hTable->elem[i] = NULLKEY;
	}
	_m = TableSize;
}

DSHash::DSHash(const DSHash &)
{
}

DSHash::~DSHash()
{
	delete[] _hTable->elem;
	delete[] _hTable;
	if (_hTable != NULL)
	{
		_hTable = NULL;
	}
}

void DSHash::InsertHash(int key)
{
	int addr = Hash(key);
	while (_hTable->elem[addr] != NULLKEY) //�����ͻ
		addr = Hash(addr + 1); //���ÿ�����ַ��������̽��
	_hTable->elem[addr] = key;
}

Status DSHash::SearchHash(int key, int &addr)
{
	addr = Hash(key);
	while (_hTable->elem[addr] != key) //������ͻ
	{
		addr = Hash(addr + 1);
		if (_hTable->elem[addr] == NULLKEY || addr == Hash(key)) //û���ҵ����߻ص���ʼֵ
		{
			return UNSUCCESS;
		}
	}
	return SUCCESS;
}

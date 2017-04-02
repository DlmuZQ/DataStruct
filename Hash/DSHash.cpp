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
	while (_hTable->elem[addr] != NULLKEY) //解决冲突
		addr = Hash(addr + 1); //采用开发地址法的线性探测
	_hTable->elem[addr] = key;
}

Status DSHash::SearchHash(int key, int &addr)
{
	addr = Hash(key);
	while (_hTable->elem[addr] != key) //发生冲突
	{
		addr = Hash(addr + 1);
		if (_hTable->elem[addr] == NULLKEY || addr == Hash(key)) //没有找到或者回到开始值
		{
			return UNSUCCESS;
		}
	}
	return SUCCESS;
}

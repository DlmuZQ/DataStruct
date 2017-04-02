#pragma once
#include <iostream>
#define SUCCESS 1
#define UNSUCCESS 0
#define NULLKEY -1
#define HASHSIZE  10

using Status = int;
struct HasTable
{
	int *elem;
	int count;
};
class DSHash
{
public:
	DSHash(int TableSize);
	~DSHash();

	
	void InsertHash(int key);

	Status SearchHash(int key,int &addr);

private:
	HasTable *_hTable;
	int _m;
	DSHash(const DSHash &);

	/*
	判别函数
	采用留余法
	*/
	inline int Hash(int key) { return key%_m; }
};


#pragma once
#include "animal.h"

class CSnake :
	public CAnimal
{
public:
	CSnake(void);
	~CSnake(void);
public:
	virtual  void PlayAnimal();
};


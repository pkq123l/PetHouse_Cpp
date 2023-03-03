#pragma once
#include<string>
using namespace std;

class CAnimal
{
public:
	CAnimal(void);
	virtual ~CAnimal(void);
public:
	int    m_nAge;
	string m_strColor;
	string m_strName;
public:
	void InitAnimal(string &name, string&color, int age);
	virtual  void PlayAnimal()=0;
	void ShowAnimal();
};


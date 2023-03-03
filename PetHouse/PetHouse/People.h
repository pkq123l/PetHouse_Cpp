#pragma once
#include<string>
using namespace std;
#include"House.h"
#include"def_config.h"


class CPeople
{
public:
	CPeople(void);
	~CPeople(void);
public:
	int m_money;
	string m_strName;
public:
	void InitPoeple(string& name, int money);
	bool BuyAnimal(CAnimal *pAni, Animal_kind kind);
	CCage* CreateCage();
	void PushAnimal(CCage* pCage, CAnimal* pAni);
	void PushCage(CHouse* pHouse, CCage*pCage);
	void KillAnimal(CHouse* pHouse, int id);
	void DestoryCage(CHouse* pHouse, int id);
	void LookAnimal(CHouse *pHouse, int id);
	void PlayWithAnimal(CHouse *pHouse, int id);
	void ShowPoeple();
};


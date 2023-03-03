#include "Animal.h"
#include<iostream>
using namespace std;


CAnimal::CAnimal(void)
{
	m_nAge=0;
	m_strColor="";
	m_strName="";
}

CAnimal::~CAnimal(void)
{
}

void CAnimal::InitAnimal(string &name, string&color, int age){
	m_nAge=age;
	m_strColor=color;
	m_strName=name;
}

void CAnimal::ShowAnimal(){
	cout<<"name: "<<m_strName<<"  , color: "<<m_strColor<<"   , age:"<<m_nAge<<endl;

}
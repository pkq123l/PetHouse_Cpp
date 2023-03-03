#include "People.h"
#include<iostream>
using namespace std;


CPeople::CPeople(void)
{
}


CPeople::~CPeople(void)
{
}

void CPeople::InitPoeple(string& name, int money){
	m_money = money;
	m_strName = name;
}


#define BUY_ANIMAL(ANIMAL_COST)\
	if(m_money-ANIMAL_COST<0){\
		cout<<"���~~,ûǮ�����ˣ�����"<<endl;\
		return false;\
	}else{\
		m_money -=ANIMAL_COST;\
	}



bool CPeople::BuyAnimal(CAnimal *pAni, Animal_kind kind){
	if(pAni==nullptr){
		cout<<"����Ϊ��"<<endl;
		return false;
	}

	switch (kind)
	{
	case animal_cat:  //��è
		{
			/*if(m_money-DEF_COST_CAT<0){
				cout<<"���~~,ûǮ�����ˣ�����"<<endl;
				return false;
			}else{
				m_money -=DEF_COST_CAT;
			}*/

			BUY_ANIMAL(DEF_COST_CAT)
		}
		break;
	case animal_dog:
		{
			BUY_ANIMAL(DEF_COST_DOG)
		}
		break;
	case animal_snake:
		{
			BUY_ANIMAL(DEF_COST_SNA)
		}
		break;
	}

	return true;
}


CCage* CPeople::CreateCage(){
	CCage *pCage = new CCage;
	int id = 0;
	cout<<"���������ӵı�ţ�id ����0��"<<endl;
	cin>>id;
	while( id<=0){
		cout<<"��������ӱ�Ų��Ϸ�������������"<<endl;
		cin>>id;
	}

	pCage->InitCage(id);

	return pCage;
}
void CPeople::PushAnimal(CCage* pCage, CAnimal* pAni){
	if(pCage == nullptr || pAni== nullptr){
		cout<<"���� �� ���� Ϊ��"<<endl;
		return ;
	}

	pCage->m_pAni = pAni;
	cout<<"����ɹ���ӵ�������"<<endl;
}
void CPeople::PushCage(CHouse* pHouse, CCage*pCage){
	if(pCage == nullptr || pHouse== nullptr){
		cout<<"���� �� ���� Ϊ��"<<endl;
		return ;
	}

	pHouse->m_lstCage.push_back(pCage);

	cout<<"���ӳɹ���ӵ�������"<<endl;

}
void CPeople::KillAnimal(CHouse* pHouse, int id){
	if(pHouse == nullptr){
		cout<<"����Ϊ��"<<endl;
		return ;
	}

	list<CCage*>::iterator ite =  pHouse->m_lstCage.begin();
	while( ite !=  pHouse->m_lstCage.end() ){
		if( (*ite) && (*ite)->m_id == id  ){   //ƥ��ɹ�
		
			if((*ite)->m_pAni ){  //�ж��������Ƿ���ڶ���
				delete (*ite)->m_pAni;   //ɱ������
				(*ite)->m_pAni = nullptr;
				cout<<"�ɹ�ɱ������"<<endl;

				return ;
			}
		}
		ite++;
	}
	cout<<"û��ƥ�䵽���� ���� ����û�ж���"<<endl;

}
void CPeople::DestoryCage(CHouse* pHouse, int id){
	if(pHouse == nullptr){
		cout<<"����Ϊ��"<<endl;
		return ;
	}

	list<CCage*>::iterator ite =  pHouse->m_lstCage.begin();
	while( ite !=  pHouse->m_lstCage.end() ){

		if( (*ite) && (*ite)->m_id == id ){  //ƥ�䵽����
		
			if(  (*ite)->m_pAni  ){   //ɾ������
				delete (*ite)->m_pAni;
				(*ite)->m_pAni = nullptr;
			
			}

			delete (*ite);   //��������
			(*ite) = nullptr;

			pHouse->m_lstCage.erase(ite);  //ɾ���ڵ�

			cout<<"�ɹ���������"<<endl;
			return ;

		}
		ite++;
	}

	cout<<"û��ƥ�䵽��Ӧ������"<<endl;

}
void CPeople::LookAnimal(CHouse *pHouse, int id){
	if(pHouse == nullptr){
		cout<<"����Ϊ��"<<endl;
		return ;
	}
	if(  id == 0){  //�鿴���е�����
		list<CCage*>::iterator ite =  pHouse->m_lstCage.begin();
		while( ite !=  pHouse->m_lstCage.end() ){

			if(  *ite  ){
				cout<<"���ӱ�� "<<(*ite)->m_id<<"  :";
				if(  (*ite)->m_pAni ){
					
					(*ite)->m_pAni->ShowAnimal();
				}else{
					cout<<"����Ϊ��"<<endl;
				}
			}

			ite++;
		}
	
	}else{   //�鿴ָ������
		list<CCage*>::iterator ite =  pHouse->m_lstCage.begin();
		while( ite !=  pHouse->m_lstCage.end() ){
	
			if(  *ite  ){  
				if((*ite)->m_id  == id){
					cout<<"���ӱ�� "<<(*ite)->m_id<<"  :";
					if(  (*ite)->m_pAni ){
						(*ite)->m_pAni->ShowAnimal();
					}else{
						cout<<"����Ϊ��"<<endl;
					}

					return ;
				}
			}

			ite++;
		}
		
		cout<<"û��ƥ�䵽��Ӧ������"<<endl;
	}

}
void CPeople::PlayWithAnimal(CHouse *pHouse, int id){
	if(pHouse == nullptr){
		cout<<"����Ϊ��"<<endl;
		return ;
	}


	list<CCage*>::iterator ite =  pHouse->m_lstCage.begin();
	while( ite !=  pHouse->m_lstCage.end() ){
		if(  (*ite) &&  (*ite)->m_id ==id ){
			cout<<m_strName<<"  ��׼��ȥ��ˣ  "<<endl;

			if(  (*ite)->m_pAni ){
				(*ite)->m_pAni->PlayAnimal();
			
			}else{
				cout<<" �Լ��¶�����ˣ"<<endl;
			}
		
			return ;
		}

		ite++;
	}


}
void CPeople::ShowPoeple(){

	cout<<"name = "<<m_strName<<"  , money = "<<m_money<<endl;
}
#include "House.h"


CHouse::CHouse(void)
{
}


CHouse::~CHouse(void)
{
	list<CCage*>::iterator ite =    m_lstCage.begin();
	while(ite != m_lstCage.end()){
		if(  (*ite)  ){   //�ж������Ƿ����
			if(  (*ite)->m_pAni  )   //�ж������Ƿ��ж���
			{
				delete (*ite)->m_pAni;   //���ն���
				(*ite)->m_pAni = nullptr;
			}

			//��������
			delete (*ite);
			(*ite) = nullptr;
		}
		//ite = m_lstCage.erase(ite);
		ite++;
	}

	m_lstCage.clear();  //���� �ڵ�ͳһ����
}

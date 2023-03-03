#include "House.h"


CHouse::CHouse(void)
{
}


CHouse::~CHouse(void)
{
	list<CCage*>::iterator ite =    m_lstCage.begin();
	while(ite != m_lstCage.end()){
		if(  (*ite)  ){   //判断笼子是否存在
			if(  (*ite)->m_pAni  )   //判断笼子是否有动物
			{
				delete (*ite)->m_pAni;   //回收动物
				(*ite)->m_pAni = nullptr;
			}

			//回收笼子
			delete (*ite);
			(*ite) = nullptr;
		}
		//ite = m_lstCage.erase(ite);
		ite++;
	}

	m_lstCage.clear();  //链表 节点统一回收
}

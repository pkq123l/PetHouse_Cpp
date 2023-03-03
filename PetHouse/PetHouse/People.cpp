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
		cout<<"穷鬼~~,没钱买动物了！！！"<<endl;\
		return false;\
	}else{\
		m_money -=ANIMAL_COST;\
	}



bool CPeople::BuyAnimal(CAnimal *pAni, Animal_kind kind){
	if(pAni==nullptr){
		cout<<"动物为空"<<endl;
		return false;
	}

	switch (kind)
	{
	case animal_cat:  //买猫
		{
			/*if(m_money-DEF_COST_CAT<0){
				cout<<"穷鬼~~,没钱买动物了！！！"<<endl;
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
	cout<<"请输入笼子的编号（id 大于0）"<<endl;
	cin>>id;
	while( id<=0){
		cout<<"输入的笼子编号不合法，请重新输入"<<endl;
		cin>>id;
	}

	pCage->InitCage(id);

	return pCage;
}
void CPeople::PushAnimal(CCage* pCage, CAnimal* pAni){
	if(pCage == nullptr || pAni== nullptr){
		cout<<"笼子 或 动物 为空"<<endl;
		return ;
	}

	pCage->m_pAni = pAni;
	cout<<"动物成功添加到笼子中"<<endl;
}
void CPeople::PushCage(CHouse* pHouse, CCage*pCage){
	if(pCage == nullptr || pHouse== nullptr){
		cout<<"笼子 或 房子 为空"<<endl;
		return ;
	}

	pHouse->m_lstCage.push_back(pCage);

	cout<<"笼子成功添加到房子中"<<endl;

}
void CPeople::KillAnimal(CHouse* pHouse, int id){
	if(pHouse == nullptr){
		cout<<"房子为空"<<endl;
		return ;
	}

	list<CCage*>::iterator ite =  pHouse->m_lstCage.begin();
	while( ite !=  pHouse->m_lstCage.end() ){
		if( (*ite) && (*ite)->m_id == id  ){   //匹配成功
		
			if((*ite)->m_pAni ){  //判断笼子中是否存在动物
				delete (*ite)->m_pAni;   //杀死动物
				(*ite)->m_pAni = nullptr;
				cout<<"成功杀死动物"<<endl;

				return ;
			}
		}
		ite++;
	}
	cout<<"没有匹配到笼子 或者 笼子没有动物"<<endl;

}
void CPeople::DestoryCage(CHouse* pHouse, int id){
	if(pHouse == nullptr){
		cout<<"房子为空"<<endl;
		return ;
	}

	list<CCage*>::iterator ite =  pHouse->m_lstCage.begin();
	while( ite !=  pHouse->m_lstCage.end() ){

		if( (*ite) && (*ite)->m_id == id ){  //匹配到笼子
		
			if(  (*ite)->m_pAni  ){   //删除动物
				delete (*ite)->m_pAni;
				(*ite)->m_pAni = nullptr;
			
			}

			delete (*ite);   //销毁笼子
			(*ite) = nullptr;

			pHouse->m_lstCage.erase(ite);  //删除节点

			cout<<"成功销毁笼子"<<endl;
			return ;

		}
		ite++;
	}

	cout<<"没有匹配到对应的笼子"<<endl;

}
void CPeople::LookAnimal(CHouse *pHouse, int id){
	if(pHouse == nullptr){
		cout<<"房子为空"<<endl;
		return ;
	}
	if(  id == 0){  //查看所有的笼子
		list<CCage*>::iterator ite =  pHouse->m_lstCage.begin();
		while( ite !=  pHouse->m_lstCage.end() ){

			if(  *ite  ){
				cout<<"笼子编号 "<<(*ite)->m_id<<"  :";
				if(  (*ite)->m_pAni ){
					
					(*ite)->m_pAni->ShowAnimal();
				}else{
					cout<<"笼子为空"<<endl;
				}
			}

			ite++;
		}
	
	}else{   //查看指定笼子
		list<CCage*>::iterator ite =  pHouse->m_lstCage.begin();
		while( ite !=  pHouse->m_lstCage.end() ){
	
			if(  *ite  ){  
				if((*ite)->m_id  == id){
					cout<<"笼子编号 "<<(*ite)->m_id<<"  :";
					if(  (*ite)->m_pAni ){
						(*ite)->m_pAni->ShowAnimal();
					}else{
						cout<<"笼子为空"<<endl;
					}

					return ;
				}
			}

			ite++;
		}
		
		cout<<"没有匹配到对应的笼子"<<endl;
	}

}
void CPeople::PlayWithAnimal(CHouse *pHouse, int id){
	if(pHouse == nullptr){
		cout<<"房子为空"<<endl;
		return ;
	}


	list<CCage*>::iterator ite =  pHouse->m_lstCage.begin();
	while( ite !=  pHouse->m_lstCage.end() ){
		if(  (*ite) &&  (*ite)->m_id ==id ){
			cout<<m_strName<<"  正准备去玩耍  "<<endl;

			if(  (*ite)->m_pAni ){
				(*ite)->m_pAni->PlayAnimal();
			
			}else{
				cout<<" 自己孤独的玩耍"<<endl;
			}
		
			return ;
		}

		ite++;
	}


}
void CPeople::ShowPoeple(){

	cout<<"name = "<<m_strName<<"  , money = "<<m_money<<endl;
}
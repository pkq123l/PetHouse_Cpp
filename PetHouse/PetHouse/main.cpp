#include<iostream>
#include<sstream>
using namespace std;

#include"People.h"
#include"cat.h"
#include"dog.h"
#include"snake.h"


//��ȡ��������
void GetAnimalAttr(string & name,string & color,int &age){
	string str = "";
	cout<<"�����붯���������Ϣ(���֣���ɫ������)"<<endl;
	getline(cin,str);
	stringstream ss(str);

	string s;
	int i=0;
	while(ss>>s){
		cout<<s<<endl;
		if(i==0){
			name = s;
		}else if( i== 1){
			color = s;
		}else if(i==2){
			age = atoi(s.c_str());
		}
		i++;
	}
}

#define DEF_BUY_ANIMAL(CLASS_NAME,ANIMAL_KIND)\
	pAni = new CLASS_NAME;\
	GetAnimalAttr(name,color,age);\
	pAni->InitAnimal(name,color,age);\
	if( !pPeo->BuyAnimal(pAni,ANIMAL_KIND)){\
		delete pAni;\
		pAni = nullptr;\
	}

void ShowCmd(){
	cout<<"******************��ӭ��������С��*****************"<<endl;
	cout<<CMD_QUIT<<"      : �����˳�"<<endl;
	cout<<CMD_HELP<<"      : �������"<<endl;
	cout<<CMD_BUY_CAT<<"   : ��è"<<endl;
	cout<<CMD_BUY_DOG<<"   : ��"<<endl;
	cout<<CMD_BUY_SNA<<" : ����"<<endl;
	cout<<CMD_KILL<<"      : ɱ��ĳ������"<<endl;
	cout<<CMD_DESTORY<<"   : ����ĳ�����ӣ�����һ�����٣�"<<endl;
	cout<<CMD_LOOK<<"      : �鿴ĳ����������ж���"<<endl;
	cout<<CMD_PLAY<<"      : ��ĳ��������ˣ"<<endl;
	cout<<CMD_SHOW<<"      : ��ʾ������Ϣ"<<endl;
	cout<<"***************************************************"<<endl;
}


int main(){
	CPeople *  pPeo = new CPeople;
	string  namePeo = "�����";
	pPeo->InitPoeple(namePeo,DEF_INIT_MONEY);

	CHouse * pHouse = new CHouse;


	string cmd = "";
	//cin>>cmd;
	ShowCmd();

	while(1){
		getline(cin,cmd);

		if(CMD_QUIT ==cmd){
			break;
		}

		if(CMD_HELP == cmd){
			ShowCmd();
		}

		CAnimal *pAni = nullptr;
		string name= "";
		string color= "";
		int  age= 0;
		if(cmd == CMD_BUY_CAT){   //��è
			//pAni = new CCat;
			////��ȡ��������
			//GetAnimalAttr(name,color,age);
			//pAni->InitAnimal(name,color,age);
			//if( !pPeo->BuyAnimal(pAni,animal_cat)){
			//	delete pAni;
			//	pAni = nullptr;
			//}

			DEF_BUY_ANIMAL(CCat,animal_cat);
		}else if(cmd == CMD_BUY_DOG){
			DEF_BUY_ANIMAL(CDog,animal_dog);
		}else if(cmd == CMD_BUY_SNA){
			DEF_BUY_ANIMAL(CSnake,animal_snake);
		}

		if(pAni){  //�������ӣ�װ���ӣ��ŵ�������
			CCage*pCage = pPeo->CreateCage();
			pPeo->PushAnimal(pCage,pAni);

			pPeo->PushCage(pHouse,pCage);
		}

		if(CMD_KILL == cmd){
			cout<<"������Ҫɱ�����������id"<<endl;
			int id = 0;
			cin>>id;

			pPeo->KillAnimal(pHouse,id);
	
		}

		if(CMD_DESTORY == cmd){
			cout<<"������Ҫ���ٵ�����id"<<endl;
			int id = 0;
			cin>>id;

			pPeo->DestoryCage(pHouse,id);
	
		}
		if(CMD_LOOK == cmd){
			cout<<"������Ҫ�鿴������id(id==0:�鿴���е����ӣ�id>0 :�鿴ָ������)"<<endl;
			int id = 0;
			cin>>id;

			pPeo->LookAnimal(pHouse,id);
	
		}

		if(CMD_PLAY ==cmd){
			cout<<"���������ӵ�id"<<endl;
			int id = 0;
			cin>>id;

			pPeo->PlayWithAnimal(pHouse,id);
		}

		if(CMD_SHOW ==cmd){
			pPeo->ShowPoeple();
		}
	
	}

	if(pPeo){
		delete pPeo;
		pPeo = nullptr;
		
	}
	if(pHouse){
		delete pHouse;
		pHouse  =nullptr;
	}

	
	return 0;
}
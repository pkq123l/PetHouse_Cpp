#include<iostream>
#include<sstream>
using namespace std;

#include"People.h"
#include"cat.h"
#include"dog.h"
#include"snake.h"


//获取动物属性
void GetAnimalAttr(string & name,string & color,int &age){
	string str = "";
	cout<<"请输入动物的属性信息(名字，颜色，年龄)"<<endl;
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
	cout<<"******************欢迎来到宠物小屋*****************"<<endl;
	cout<<CMD_QUIT<<"      : 程序退出"<<endl;
	cout<<CMD_HELP<<"      : 命令帮助"<<endl;
	cout<<CMD_BUY_CAT<<"   : 买猫"<<endl;
	cout<<CMD_BUY_DOG<<"   : 买狗"<<endl;
	cout<<CMD_BUY_SNA<<" : 买蛇"<<endl;
	cout<<CMD_KILL<<"      : 杀死某个动物"<<endl;
	cout<<CMD_DESTORY<<"   : 销毁某个笼子（动物一起销毁）"<<endl;
	cout<<CMD_LOOK<<"      : 查看某个动物或所有动物"<<endl;
	cout<<CMD_PLAY<<"      : 和某个动物玩耍"<<endl;
	cout<<CMD_SHOW<<"      : 显示人物信息"<<endl;
	cout<<"***************************************************"<<endl;
}


int main(){
	CPeople *  pPeo = new CPeople;
	string  namePeo = "马里奥";
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
		if(cmd == CMD_BUY_CAT){   //买猫
			//pAni = new CCat;
			////获取动物属性
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

		if(pAni){  //建造笼子，装笼子，放到房子里
			CCage*pCage = pPeo->CreateCage();
			pPeo->PushAnimal(pCage,pAni);

			pPeo->PushCage(pHouse,pCage);
		}

		if(CMD_KILL == cmd){
			cout<<"请输入要杀死动物的笼子id"<<endl;
			int id = 0;
			cin>>id;

			pPeo->KillAnimal(pHouse,id);
	
		}

		if(CMD_DESTORY == cmd){
			cout<<"请输入要销毁的笼子id"<<endl;
			int id = 0;
			cin>>id;

			pPeo->DestoryCage(pHouse,id);
	
		}
		if(CMD_LOOK == cmd){
			cout<<"请输入要查看的笼子id(id==0:查看所有的笼子，id>0 :查看指定笼子)"<<endl;
			int id = 0;
			cin>>id;

			pPeo->LookAnimal(pHouse,id);
	
		}

		if(CMD_PLAY ==cmd){
			cout<<"请输入笼子的id"<<endl;
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
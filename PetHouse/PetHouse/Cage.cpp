#include "Cage.h"


CCage::CCage(void)
{
	m_pAni = nullptr;
	m_id = 0;
}


CCage::~CCage(void)
{

}

void CCage::InitCage(int id){

	m_id = id;
}
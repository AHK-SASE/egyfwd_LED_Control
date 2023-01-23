#include "IntCtrl_driver.h"


static void SetPriorityGrouping(Group_SubgroupType	PriorityGrouping){
	//uint32_t	APINT_Temp	= NVIC_APINT;
	uint32_t	u32_PriorityGroupingTemp	=	((uint32_t)PriorityGrouping	& 7UL);
//	uint32_t  Test;
	
	// APINT_Temp	&=	~((uint32_t)(VECT_KEY_MASK	|	APINT_PRIGROUP_MASK));
	NVIC_APINT = ((VECT_KEY<<16) + (u32_PriorityGroupingTemp <<  APINT_PRIGROUP));
	//Test = NVIC_APINT;
}

static void IntCrtl_SetPriority(IntCtrl_InterruptType IntrNum, uint8_t u8_IntPriority) { 
	uint8_t InterruptPriority = ((u8_IntPriority & 0x07) << ((((IntrNum )%4) *8) + 5));
	//NVIC_PRIx 
	if(IntrNum > INTCTRL_INTERRUPT_TYPE_SYSTICK){
			PRIx(IntrNum)  = InterruptPriority; 
	} 

}
static void	IntCtrl_EnableInterupt(IntCtrl_InterruptType	IntrNum){
	uint32_t BitNum	= (IntrNum)%32;
	if(IntrNum > INTCTRL_INTERRUPT_TYPE_SYSTICK){
			
			ENx(IntrNum) |= (1 << BitNum); 
	} 

}
static void	IntCtrl_DisableInterupt(IntCtrl_InterruptType	IntrNum){
	if(IntrNum > INTCTRL_INTERRUPT_TYPE_SYSTICK){
			DISx(IntrNum) &= ~(1 << (IntrNum)%32); 
	} 
}


void IntCrtl_Init(const Int_ConfigType* g_user_data){
	__asm("CPSIE  I");
	
	SetPriorityGrouping(g_user_data->groupspriority_config); 

	uint8_t u8_IntrPrioriity = 0;
	uint8_t u8_GroupPriority = (uint8_t)g_user_data->Int_Cfg.Group_Prio;
	uint8_t u8_SubGroupPriority = (uint8_t)g_user_data->Int_Cfg.Sub_Group_Prio;
	IntCtrl_InterruptType IntrNum = g_user_data->Int_Cfg.Interrupt_Type; 
	
	if(bxxx == g_user_data->groupspriority_config) { 
				u8_IntrPrioriity = u8_GroupPriority; 
	} 
	else if(bxxy ==  g_user_data->groupspriority_config){ 
		u8_IntrPrioriity = ((u8_GroupPriority & 0x03) << 1UL) | ((u8_SubGroupPriority & 0x01 << 0));
	}		
	else if(bxyy == g_user_data->groupspriority_config){ 
		u8_IntrPrioriity = (( u8_GroupPriority & 0x01) << 2UL) | ((u8_SubGroupPriority & 0x03) << 0);
	}
	else if(byyy == g_user_data->groupspriority_config){
		u8_IntrPrioriity = u8_SubGroupPriority;
	} 
	else{
	// Invalid 
	}
	IntCrtl_SetPriority(IntrNum, u8_IntrPrioriity);
	IntCtrl_EnableInterupt(IntrNum);
	


}

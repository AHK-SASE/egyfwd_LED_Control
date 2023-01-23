#include "std_types.h"
#include "MCU_hw.h"


#define NVIC_BASE          					0xE000E000
#define VECT_KEY_MASK								0xFFFF0000		
#define APINT_PRIGROUP_MASK					0x00000700
#define VECT_KEY										0x05FA
#define APINT_PRIGROUP							8
#define NVIC_APINT									*((volatile uint32_t*)(NVIC_BASE + 0xD0C))
#define NVIC_INTCTRL								*((volatile INTCTRL_TAG *)(NVIC_BASE + 0xD04))

#define PRIx(i) 										*((volatile uint32_t *)(NVIC_BASE + 0x400 + (i / 4) * 4))
#define ENx(i) 											*((volatile uint32_t *)(NVIC_BASE + 0x100 + ((i / 32) * 32)))
#define DISx(i) 										*((volatile uint32_t *)(NVIC_BASE + 0x180 + ((i / 32) * 32)))



/********************************************************************************
 *	GLOBAL DATA TYPES AND STRUCTURES
 ********************************************************************************/
typedef struct
{
    uint32_t VECACTOR 	: 8;
    uint32_t 						:	3;
    uint32_t RETBASE 		: 1;
    uint32_t VECPEND 		: 8;
    uint32_t 						: 2;
    uint32_t ISRPEND 		: 1;
    uint32_t ISRPRE 		: 1;
    uint32_t 						: 1;
    uint32_t PENDSTCLR 	: 1;
    uint32_t PENDSTSET 	: 1;
    uint32_t UNPENDSV 	: 1;
    uint32_t PENDSV 		: 1;
    uint32_t 						: 2;
    uint32_t NMISET 		: 1;
} INTCTRL_BF;

typedef union{
    uint32_t R;
    INTCTRL_BF B;
} INTCTRL_TAG;




/********************************************************************************
 *	GLOBAL CONSTANT MACROS
 ********************************************************************************/

// #define PENDx(i) *((volatile uint32 *)(CORTEXM4_PERI_BASE_Address + 0x208))
// #define UNPENDx(i) *((volatile uint32 *)(CORTEXM4_PERI_BASE_Address + 0x288))
// #define ACTIVEx(i) *((volatile uint32 *)(CORTEXM4_PERI_BASE_Address + 0x308))



		
static void SetPriorityGrouping(Group_SubgroupType	PriorityGrouping);
static void IntCtrl_SetPriority(IntCtrl_InterruptType	IntrNum,	uint8_t	u8_IntPriority);
static void	IntCtrl_EnableInterupt(IntCtrl_InterruptType	IntrNum);
static void	IntCtrl_DisableInterupt(IntCtrl_InterruptType	IntrNum);
void IntCrtl_Init(const Int_ConfigType* g_user_data);
		
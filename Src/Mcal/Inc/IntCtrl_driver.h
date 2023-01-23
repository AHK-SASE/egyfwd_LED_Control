#include "std_types.h"
#include "MCU_hw.h"

static void SetPriorityGrouping(Group_SubgroupType PriorityGrouping);
static void IntCtrl_SetPriority(IntCtrl_InterruptType IntrNum, uint8_t u8_IntPriority);
static void IntCtrl_EnableInterupt(IntCtrl_InterruptType IntrNum);
static void IntCtrl_DisableInterupt(IntCtrl_InterruptType IntrNum);
void IntCrtl_Init(const Int_ConfigType *g_user_data);

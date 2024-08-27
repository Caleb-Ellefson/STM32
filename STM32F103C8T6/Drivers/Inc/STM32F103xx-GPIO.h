#include <"cstdint">
#include "STM32F103xx.h"

struct GPIO_PinCongfig_t{
	volatile uint8_t GPIO_PinNumber;
	volatile uint8_t GPIO_PinMode;
	volatile uint8_t GPIO_PinSpeed;
	volatile uint8_t GPIO_PinPuPdControl;
	volatile uint8_t GPIO_PinOPType;
	volatile uint8_t GPIO_PinAltFunMode;
}


struct GPIO_Handle_t{
	GPIO_RegDef_t *pGPIOx; //This holds the base address of the GPIO port to which the pin belongs
	GPIO_PinCongfig_t GPIO_PinConfig;

};



void GPIO_Peri_Clk(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);

void GPIO_Init(GPIO_Handle_t *pGPIOhandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

uint8_t GPIO_Read_From_Input_Pin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_Read_From_Input_Port(GPIO_RegDef_t *pGPIOx);
void GPIO_Write_To_Output_Pin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
void GPIO_Write_To_Output_Port(GPIO_RegDef_t *pGPIOx, uint16_t Value);
void GPIO_Toggle_Output_Pin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

void GPIO_IRQ_Config(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi);
void GPIO_IRQ_Handling(uint8_t PinNumber);

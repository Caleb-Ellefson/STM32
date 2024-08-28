#include "STM32F103xx-GPIO.h"




//					GPIO Peripheral Clock Setup

/************************************************************************
@fn             - GPIO_Peri_Clk

@brief          - This function enables or disables peripheral clock for a given GPIO port.

@param[in]      - pGPIOx: Base address of the GPIO peripheral.
@param[in]      - EnorDi: ENABLE or DISABLE macros (STATUS namespace in the main header file).

@return         - void

@Note           - none

*/



void GPIO_Peri_Clk(GPIO_Reg_Def_t *pGPIOx, uint8_t EnorDi) {
    switch(reinterpret_cast<uintptr_t>(pGPIOx)) {
        case Memory::GPIOA_BASEADDR:
            if (EnorDi == Status::ENABLE) {
                Clock::GPIOA_PCLK_EN();
            } else {
                Clock::GPIOA_PCLK_DI();
            }
            break;
        case Memory::GPIOB_BASEADDR:
            if (EnorDi == Status::ENABLE) {
                Clock::GPIOB_PCLK_EN();
            } else {
                Clock::GPIOB_PCLK_DI();
            }
            break;
        case Memory::GPIOC_BASEADDR:
            if (EnorDi == Status::ENABLE) {
                Clock::GPIOC_PCLK_EN();
            } else {
                Clock::GPIOC_PCLK_DI();
            }
            break;
        case Memory::GPIOD_BASEADDR:
            if (EnorDi == Status::ENABLE) {
                Clock::GPIOD_PCLK_EN();
            } else {
                Clock::GPIOD_PCLK_DI();
            }
            break;
        case Memory::GPIOE_BASEADDR:
            if (EnorDi == Status::ENABLE) {
                Clock::GPIOE_PCLK_EN();
            } else {
                Clock::GPIOE_PCLK_DI();
            }
            break;
        case Memory::GPIOF_BASEADDR:
            if (EnorDi == Status::ENABLE) {
                Clock::GPIOF_PCLK_EN();
            } else {
                Clock::GPIOF_PCLK_DI();
            }
            break;
        case Memory::GPIOG_BASEADDR:
            if (EnorDi == Status::ENABLE) {
                Clock::GPIOG_PCLK_EN();
            } else {
                Clock::GPIOG_PCLK_DI();
            }
            break;
        default:
            // Handle error or unknown GPIO port case
            break;
    }
}


//					GPIO Initialization

/************************************************************************
@fn             - GPIO_Init

@brief          - This function initializes the given GPIO pin.

@param[in]      - pGPIOhandle: Handle structure for a GPIO pin.

@return         - void

@Note           - Refer to the specific microcontroller's datasheet for the correct configuration.

*/
void GPIO_Init(GPIO_Handle_t *pGPIOhandle){

	uint32_t temp = 0; //temp. register
	//config mode

	if (pGPIOhandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODES::GPIO_MODE_IN_ANALOG){

		temp = pGPIOhandle->GPIO_PinConfig.GPIO_PinMode << (2 *pGPIOhandle->GPIO_PinConfig.GPIO_PinNumber);
	}
	//configure speed

	//cibfugyre pupd settings

	//congifure optype

	//configure alt functionality

};


//					GPIO De-initialization

/************************************************************************
@fn             - GPIO_DeInit

@brief          - This function de-initializes the given GPIO port.

@param[in]      - pGPIOx: Base address of the GPIO peripheral.

@return         - void

@Note           - Resets the GPIO registers to their default state.

*/
void GPIO_DeInit(GPIO_Reg_Def_t *pGPIOx){

}


//					Read from GPIO Input Pin

/************************************************************************
@fn             - GPIO_Read_From_Input_Pin

@brief          - This function reads the value from a specific GPIO input pin.

@param[in]      - pGPIOx: Base address of the GPIO peripheral.
@param[in]      - PinNumber: GPIO pin number.

@return         - uint8_t: Value read from the input pin (0 or 1).

@Note           - none

*/
uint8_t GPIO_Read_From_Input_Pin(GPIO_Reg_Def_t *pGPIOx, uint8_t PinNumber){

};


//					Read from GPIO Input Port

/************************************************************************
@fn             - GPIO_Read_From_Input_Port

@brief          - This function reads the value from the entire GPIO input port.

@param[in]      - pGPIOx: Base address of the GPIO peripheral.

@return         - uint16_t: Value read from the input port.

@Note           - none

*/
uint16_t GPIO_Read_From_Input_Port(GPIO_Reg_Def_t *pGPIOx){

};


//					Write to GPIO Output Pin

/************************************************************************
@fn             - GPIO_Write_To_Output_Pin

@brief          - This function writes a value to a specific GPIO output pin.

@param[in]      - pGPIOx: Base address of the GPIO peripheral.
@param[in]      - PinNumber: GPIO pin number.
@param[in]      - Value: Value to write to the output pin (0 or 1).

@return         - void

@Note           - none

*/
void GPIO_Write_To_Output_Pin(GPIO_Reg_Def_t *pGPIOx, uint8_t PinNumber, uint8_t Value){

};


//					Write to GPIO Output Port

/************************************************************************
@fn             - GPIO_Write_To_Output_Port

@brief          - This function writes a value to the entire GPIO output port.

@param[in]      - pGPIOx: Base address of the GPIO peripheral.
@param[in]      - Value: Value to write to the output port.

@return         - void

@Note           - none

*/
void GPIO_Write_To_Output_Port(GPIO_Reg_Def_t *pGPIOx, uint16_t Value){

};


//					Toggle GPIO Output Pin

/************************************************************************
@fn             - GPIO_Toggle_Output_Pin

@brief          - This function toggles the value of a specific GPIO output pin.

@param[in]      - pGPIOx: Base address of the GPIO peripheral.
@param[in]      - PinNumber: GPIO pin number.

@return         - void

@Note           - none

*/
void GPIO_Toggle_Output_Pin(GPIO_Reg_Def_t *pGPIOx, uint8_t PinNumber){

};


//					GPIO Interrupt Configuration

/************************************************************************
@fn             - GPIO_IRQ_Config

@brief          - This function configures the IRQ for a specific GPIO pin.

@param[in]      - IRQNumber: Interrupt Request Number.
@param[in]      - IRQPriority: Priority of the interrupt.
@param[in]      - EnorDi: ENABLE or DISABLE macros (STATUS namespace in the main header file).

@return         - void

@Note           - none

*/
void GPIO_IRQ_Config(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi){

};


//					GPIO Interrupt Handling

/************************************************************************
@fn             - GPIO_IRQ_Handling

@brief          - This function handles the IRQ for a specific GPIO pin.

@param[in]      - PinNumber: GPIO pin number.

@return         - void

@Note           - Should be called in the ISR of the corresponding IRQ.

*/
void GPIO_IRQ_Handling(uint8_t PinNumber){

};

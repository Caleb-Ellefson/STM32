#ifndef STM32F103XX_GPIO_DRIVER_H
#define STM32F103XX_GPIO_DRIVER_H

#include <cstdint>
#include "STM32F103xx.h"

//Declare Namespaces
using Registers::GPIO_Reg_Def_t;

// GPIO Configuration Structure
struct GPIO_PinConfig_t {				
    volatile uint8_t GPIO_PinNumber;       // Pin number
    volatile uint8_t GPIO_PinMode;         // Mode of the pin (Input, Output, Alternate function, Analog)
    volatile uint8_t GPIO_PinSpeed;        // Speed of the pin (Low, Medium, High)
    volatile uint8_t GPIO_PinPuPdControl;  // Pull-up/Pull-down control
    volatile uint8_t GPIO_PinOPType;       // Output type (Push-pull, Open-drain)
    volatile uint8_t GPIO_PinAltFunMode;   // Alternate function mode (if applicable)
};

// GPIO Handle Structure
struct GPIO_Handle_t {
    GPIO_Reg_Def_t *pGPIOx;           // Pointer to the GPIO port base address
    GPIO_PinConfig_t GPIO_PinConfig;  // GPIO pin configuration settings
};

namespace GPIO_MODES {

    // In input mode (MODE[1:0]=00)
    constexpr uint8_t GPIO_MODE_IN_ANALOG = 0;
    constexpr uint8_t GPIO_MODE_IN_FLOAT = 1;
    constexpr uint8_t GPIO_MODE_IN_PUPD = 2;

    // Interrupt modes
    constexpr uint8_t GPIO_MODE_IT_FT = 3;
    constexpr uint8_t GPIO_MODE_IT_RT = 4;
    constexpr uint8_t GPIO_MODE_IT_RFT = 5;

    // In output mode (MODE[1:0] > 00)
    constexpr uint8_t GPIO_MODE_OUT_PP = 0;
    constexpr uint8_t GPIO_MODE_OUT_OD = 1;
    constexpr uint8_t GPIO_MODE_OUT_ALTFN_PP = 2;
    constexpr uint8_t GPIO_MODE_OUT_ALTFN_OD = 3;

    // Speed modes
    constexpr uint8_t GPIO_SPEED_RESET = 0;
    constexpr uint8_t GPIO_SPEED_10MHz = 1;
    constexpr uint8_t GPIO_SPEED_2MHz = 2;
    constexpr uint8_t GPIO_SPEED_50Mhz = 3;
}

namespace GPIO_PINS {
    constexpr uint8_t GPIO_PIN_NO_0 = 0;
    constexpr uint8_t GPIO_PIN_NO_1 = 1;
    constexpr uint8_t GPIO_PIN_NO_2 = 2;
    constexpr uint8_t GPIO_PIN_NO_3 = 3;
    constexpr uint8_t GPIO_PIN_NO_4 = 4;
    constexpr uint8_t GPIO_PIN_NO_5 = 5;
    constexpr uint8_t GPIO_PIN_NO_6 = 6;
    constexpr uint8_t GPIO_PIN_NO_7 = 7;
    constexpr uint8_t GPIO_PIN_NO_8 = 8;
    constexpr uint8_t GPIO_PIN_NO_9 = 9;
    constexpr uint8_t GPIO_PIN_NO_10 = 10;
    constexpr uint8_t GPIO_PIN_NO_11 = 11;
    constexpr uint8_t GPIO_PIN_NO_12 = 12;
    constexpr uint8_t GPIO_PIN_NO_13 = 13;
    constexpr uint8_t GPIO_PIN_NO_14 = 14;
    constexpr uint8_t GPIO_PIN_NO_15 = 15;
};

// Peripheral Clock Setup
void GPIO_Peri_Clk(GPIO_Reg_Def_t *pGPIOx, uint8_t EnorDi);

// GPIO Initialization and De-initialization
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_Reg_Def_t *pGPIOx);

// GPIO Read and Write Operations
uint8_t GPIO_Read_From_Input_Pin(GPIO_Reg_Def_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_Read_From_Input_Port(GPIO_Reg_Def_t *pGPIOx);
void GPIO_Write_To_Output_Pin(GPIO_Reg_Def_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
void GPIO_Write_To_Output_Port(GPIO_Reg_Def_t *pGPIOx, uint16_t Value);
void GPIO_Toggle_Output_Pin(GPIO_Reg_Def_t *pGPIOx, uint8_t PinNumber);

// GPIO Interrupt Configuration and Handling
void GPIO_IRQ_Config(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi);
void GPIO_IRQ_Handling(uint8_t PinNumber);

#endif // STM32F103XX_GPIO_DRIVER_H

#include <cstdint>

namespace Memory {
    // Base address of the Flash memory
    constexpr uint32_t FLASH_BASEADDR = 0x08000000UL;

    // Base address of SRAM1 (Static RAM)
    constexpr uint32_t SRAM1_BASEADDR = 0x20000000UL;

    // Base address of the system ROM (System memory)
    constexpr uint32_t ROM = 0x1FFFF000UL;

    // Alias for SRAM base address
    constexpr uint32_t SRAM = SRAM1_BASEADDR;

    // Base address for peripherals
    constexpr uint32_t PERIPH_BASE = 0x40000000UL;

    // Base address for APB1 peripherals
    constexpr uint32_t APB1PERIPH_BASEADDR = PERIPH_BASE;

    // Base address for APB2 peripherals
    constexpr uint32_t APB2PERIPH_BASEADDR = 0x40010000UL;

    // Base address for AHB1 peripherals
    constexpr uint32_t AHB1_BASEADDR = 0x40018000UL;

    // Base address for RCC
    constexpr uint32_t RCC_BASEADDR = 0x40021000UL;

    // Base addresses for GPIO peripherals on APB2 bus
    constexpr uint32_t GPIOA_BASEADDR = APB2PERIPH_BASEADDR + 0x0800;   // GPIO Port A
    constexpr uint32_t GPIOB_BASEADDR = APB2PERIPH_BASEADDR + 0x0C00;   // GPIO Port B
    constexpr uint32_t GPIOC_BASEADDR = APB2PERIPH_BASEADDR + 0x1000;   // GPIO Port C
    constexpr uint32_t GPIOD_BASEADDR = APB2PERIPH_BASEADDR + 0x1400;   // GPIO Port D
    constexpr uint32_t GPIOE_BASEADDR = APB2PERIPH_BASEADDR + 0x1800;   // GPIO Port E
    constexpr uint32_t GPIOF_BASEADDR = APB2PERIPH_BASEADDR + 0x1C00;   // GPIO Port F
    constexpr uint32_t GPIOG_BASEADDR = APB2PERIPH_BASEADDR + 0x2000;   // GPIO Port G

    // Base address for EXTI (External Interrupt) controller on APB2 bus
    constexpr uint32_t EXTI_BASEADDR = APB2PERIPH_BASEADDR + 0x0400;

    // Base address for USART1 on APB2 bus
    constexpr uint32_t USART1_BASEADDR = APB2PERIPH_BASEADDR + 0x3C00;

    // Base addresses for SPI peripherals on APB1 bus
    constexpr uint32_t SPI2_BASEADDR = APB1PERIPH_BASEADDR + 0x3800;   // SPI2
    constexpr uint32_t SPI3_BASEADDR = APB1PERIPH_BASEADDR + 0x3C00;   // SPI3

    // Base addresses for USART/UART peripherals on APB1 bus
    constexpr uint32_t USART2_BASEADDR = APB1PERIPH_BASEADDR + 0x4400;   // USART2
    constexpr uint32_t USART3_BASEADDR = APB1PERIPH_BASEADDR + 0x4800;   // USART3
    constexpr uint32_t UART4_BASEADDR = APB1PERIPH_BASEADDR + 0x4C00;   // UART4
    constexpr uint32_t UART5_BASEADDR = APB1PERIPH_BASEADDR + 0x5000;   // UART5

    // Base addresses for I2C peripherals on APB1 bus
    constexpr uint32_t I2C1_BASEADDR = APB1PERIPH_BASEADDR + 0x5400;   // I2C1
    constexpr uint32_t I2C2_BASEADDR = APB1PERIPH_BASEADDR + 0x5800;   // I2C2
}

namespace Registers {

    struct GPIO_Reg_Def {
        volatile uint32_t CRL;   // 0x00: Port Configuration Register Low
        volatile uint32_t CRH;   // 0x04: Port Configuration Register High
        volatile uint32_t IDR;   // 0x08: Port Input Data Register
        volatile uint32_t ODR;   // 0x0C: Port Output Data Register
        volatile uint32_t BSRR;  // 0x10: Port Bit Set/Reset Register
        volatile uint32_t BRR;   // 0x14: Port Bit Reset Register
        volatile uint32_t LCKR;  // 0x18: Port Configuration Lock Register
    };

    struct RCC_Reg_Def {
        volatile uint32_t CR;       	// 0x00: Clock Control Register
        volatile uint32_t CFGR;     	// 0x04: Clock Configuration Register
        volatile uint32_t CIR;      	// 0x08: Clock Interrupt Register
        volatile uint32_t APB2RSTR; 	// 0x0C: APB2 Peripheral Reset Register
        volatile uint32_t APB1RSTR; 	// 0x10: APB1 Peripheral Reset Register
        volatile uint32_t AHBENR;   	// 0x14: AHB Peripheral Clock Enable Register
        volatile uint32_t APB2ENR;  	// 0x18: APB2 Peripheral Clock Enable Register
        volatile uint32_t APB1ENR;  	// 0x1C: APB1 Peripheral Clock Enable Register
        volatile uint32_t BDCR;     	// 0x20: Backup Domain Control Register
        volatile uint32_t CSR;      	// 0x24: Control/Status Register
    };

    // Peripheral Definitions (Peripheral base addresses typecasted to xxx_Reg_Def)
    inline GPIO_Reg_Def* const GPIOA = reinterpret_cast<GPIO_Reg_Def*>(Memory::GPIOA_BASEADDR);
    inline GPIO_Reg_Def* const GPIOB = reinterpret_cast<GPIO_Reg_Def*>(Memory::GPIOB_BASEADDR);
    inline GPIO_Reg_Def* const GPIOC = reinterpret_cast<GPIO_Reg_Def*>(Memory::GPIOC_BASEADDR);
    inline GPIO_Reg_Def* const GPIOD = reinterpret_cast<GPIO_Reg_Def*>(Memory::GPIOD_BASEADDR);
    inline GPIO_Reg_Def* const GPIOE = reinterpret_cast<GPIO_Reg_Def*>(Memory::GPIOE_BASEADDR);
    inline GPIO_Reg_Def* const GPIOF = reinterpret_cast<GPIO_Reg_Def*>(Memory::GPIOF_BASEADDR);
    inline GPIO_Reg_Def* const GPIOG = reinterpret_cast<GPIO_Reg_Def*>(Memory::GPIOG_BASEADDR);

    inline RCC_Reg_Def* const RCC = reinterpret_cast<RCC_Reg_Def*>(Memory::RCC_BASEADDR);
}

// Peripheral Clock Enable/Disable Macros
namespace Clock {
    inline void GPIOA_PCLK_EN()  { Registers::RCC->APB2ENR |= (1 << 2); }
    inline void GPIOB_PCLK_EN()  { Registers::RCC->APB2ENR |= (1 << 3); }
    inline void GPIOC_PCLK_EN()  { Registers::RCC->APB2ENR |= (1 << 4); }
    inline void GPIOD_PCLK_EN()  { Registers::RCC->APB2ENR |= (1 << 5); }
    inline void GPIOE_PCLK_EN()  { Registers::RCC->APB2ENR |= (1 << 6); }
    inline void GPIOF_PCLK_EN()  { Registers::RCC->APB2ENR |= (1 << 7); }
    inline void GPIOG_PCLK_EN()  { Registers::RCC->APB2ENR |= (1 << 8); }

    inline void I2C1_PCLK_EN()   { Registers::RCC->AHBENR |= (1 << 21); }
    inline void I2C2_PCLK_EN()   { Registers::RCC->AHBENR |= (1 << 22); }

    inline void SPI2_PCLK_EN()   { Registers::RCC->AHBENR |= (1 << 14); }
    inline void SPI3_PCLK_EN()   { Registers::RCC->AHBENR |= (1 << 15); }

    inline void USART2_PCLK_EN() { Registers::RCC->AHBENR |= (1 << 17); }
    inline void USART3_PCLK_EN() { Registers::RCC->AHBENR |= (1 << 18); }
    inline void UART4_PCLK_EN()  { Registers::RCC->AHBENR |= (1 << 19); }
    inline void UART5_PCLK_EN()  { Registers::RCC->AHBENR |= (1 << 20); }

    inline void GPIOA_PCLK_DI()  { Registers::RCC->APB2ENR &= ~(1 << 2); }
    inline void GPIOB_PCLK_DI()  { Registers::RCC->APB2ENR &= ~(1 << 3); }
    inline void GPIOC_PCLK_DI()  { Registers::RCC->APB2ENR &= ~(1 << 4); }
    inline void GPIOD_PCLK_DI()  { Registers::RCC->APB2ENR &= ~(1 << 5); }
    inline void GPIOE_PCLK_DI()  { Registers::RCC->APB2ENR &= ~(1 << 6); }
    inline void GPIOF_PCLK_DI()  { Registers::RCC->APB2ENR &= ~(1 << 7); }
    inline void GPIOG_PCLK_DI()  { Registers::RCC->APB2ENR &= ~(1 << 8); }

    inline void I2C1_PCLK_DI()   { Registers::RCC->AHBENR &= ~(1 << 21); }
    inline void I2C2_PCLK_DI()   { Registers::RCC->AHBENR &= ~(1 << 22); }

    inline void SPI2_PCLK_DI()   { Registers::RCC->AHBENR &= ~(1 << 14); }
    inline void SPI3_PCLK_DI()   { Registers::RCC->AHBENR &= ~(1 << 15); }

    inline void USART2_PCLK_DI() { Registers::RCC->AHBENR &= ~(1 << 17); }
    inline void USART3_PCLK_DI() { Registers::RCC->AHBENR &= ~(1 << 18); }
    inline void UART4_PCLK_DI()  { Registers::RCC->AHBENR &= ~(1 << 19); }
    inline void UART5_PCLK_DI()  { Registers::RCC->AHBENR &= ~(1 << 20); }
}

namespace Status {
    constexpr uint8_t ENABLE = 1;
    constexpr uint8_t DISABLE = 0;

    constexpr uint8_t SET = ENABLE;
    constexpr uint8_t RESET = DISABLE;

    constexpr uint8_t GPIO_PIN_SET = SET;
    constexpr uint8_t GPIO_PIN_RESET = RESET;
    
}

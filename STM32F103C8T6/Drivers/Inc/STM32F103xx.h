#include <stdint.h>

// Base address of the Flash memory
#define FLASH_BASEADDR          0x0800000UL

// Base address of SRAM1 (Static RAM)
#define SRAM1_BASEADDR          0x20000000UL

// Base address of the system ROM (System memory)
#define ROM                     0x1FFFF000UL

// Alias for SRAM base address
#define SRAM                    SRAM1_BASEADDR

// Base address for peripherals
#define PERIPH_BASE             0x400000000UL

// Base address for APB1 peripherals
#define APB1PERIPH_BASEADDR     PERIPH_BASE

// Base address for APB2 peripherals
#define APB2PERIPH_BASEADDR     0x40010000UL

// Base address for AHB1 peripherals
#define AHB1_BASEADDR           0x40018000UL

//Base addresse for RCC

#define RCC_BASEADDR			0x40021000UL

// Base addresses for GPIO peripherals on APB2 bus
#define GPIOA_BASEADDR          (APB2PERIPH_BASEADDR + 0x0800)   // GPIO Port A
#define GPIOB_BASEADDR          (APB2PERIPH_BASEADDR + 0x0C00)   // GPIO Port B
#define GPIOC_BASEADDR          (APB2PERIPH_BASEADDR + 0x1000)   // GPIO Port C
#define GPIOD_BASEADDR          (APB2PERIPH_BASEADDR + 0x1400)   // GPIO Port D
#define GPIOE_BASEADDR          (APB2PERIPH_BASEADDR + 0x1800)   // GPIO Port E
#define GPIOF_BASEADDR          (APB2PERIPH_BASEADDR + 0x1C00)   // GPIO Port F
#define GPIOG_BASEADDR          (APB2PERIPH_BASEADDR + 0x2000)   // GPIO Port G

// Base address for EXTI (External Interrupt) controller on APB2 bus
#define EXTI_BASEADDR           (APB2PERIPH_BASEADDR + 0x0400)

// Base address for USART1 on APB2 bus
#define USART1_BASEADDR         (APB2PERIPH_BASEADDR + 0x3C00)

// Base addresses for SPI peripherals on APB1 bus
#define SPI2_BASEADDR           (APB1PERIPH_BASEADDR + 0x3800)   // SPI2
#define SPI3_BASEADDR           (APB1PERIPH_BASEADDR + 0x3C00)   // SPI3

// Base addresses for USART/UART peripherals on APB1 bus
#define USART2_BASEADDR         (APB1PERIPH_BASEADDR + 0x4400)   // USART2
#define USART3_BASEADDR         (APB1PERIPH_BASEADDR + 0x4800)   // USART3
#define UART4_BASEADDR          (APB1PERIPH_BASEADDR + 0x4C00)   // UART4
#define UART5_BASEADDR          (APB1PERIPH_BASEADDR + 0x5000)   // UART5

// Base addresses for I2C peripherals on APB1 bus
#define I2C1_BASEADDR           (APB1PERIPH_BASEADDR + 0x5400)   // I2C1
#define I2C2_BASEADDR           (APB1PERIPH_BASEADDR + 0x5800)   // I2C2


//*****************************************Peripheral Register Definition Structures *****************************************

typedef struct {

    volatile uint32_t _CRL;   // 0x00: Port Configuration Register Low
    volatile uint32_t _CRH;   // 0x04: Port Configuration Register High
    volatile uint32_t _IDR;   // 0x08: Port Input Data Register
    volatile uint32_t _ODR;   // 0x0C: Port Output Data Register
    volatile uint32_t _BSRR;  // 0x10: Port Bit Set/Reset Register
    volatile uint32_t _BRR;   // 0x14: Port Bit Reset Register
    volatile uint32_t _LCKR;  // 0x18: Port Configuration Lock Register

} GPIO_Reg_Def_t;


typedef struct {

    volatile uint32_t RCC_CR;       	// 0x00: Clock Control Register
    volatile uint32_t RCC_CFGR;     	// 0x04: Clock Configuration Register
    volatile uint32_t RCC_CIR;      	// 0x08: Clock Interrupt Register
    volatile uint32_t RCC_APB2RSTR; 	// 0x0C: APB2 Peripheral Reset Register
    volatile uint32_t RCC_APB1RSTR; 	// 0x10: APB1 Peripheral Reset Register
    volatile uint32_t RCC_AHBENR;   	// 0x14: AHB Peripheral Clock Enable Register
    volatile uint32_t RCC_APB2ENR;  	// 0x18: APB2 Peripheral Clock Enable Register
    volatile uint32_t RCC_APB1ENR;  	// 0x1C: APB1 Peripheral Clock Enable Register
    volatile uint32_t RCC_BDCR;     	// 0x20: Backup Domain Control Register
    volatile uint32_t RCC_CSR;      	// 0x24: Control/Status Register

} RCC_Reg_Def_t;


// Peripheral Definitions (Pheripherial base addresses typecasted to xxx_RegDef_t)

// Peripheral Clock Enable Macros

// Clock Enable Macro for GPIOx peripherals
#define GPIOA_PCLK_EN()  (RCC->RCC_APB2ENR |= (1 << 2))   // Enable clock for GPIOA
#define GPIOB_PCLK_EN()  (RCC->RCC_APB2ENR |= (1 << 3))   // Enable clock for GPIOB
#define GPIOC_PCLK_EN()  (RCC->RCC_APB2ENR |= (1 << 4))   // Enable clock for GPIOC
#define GPIOD_PCLK_EN()  (RCC->RCC_APB2ENR |= (1 << 5))   // Enable clock for GPIOD
#define GPIOE_PCLK_EN()  (RCC->RCC_APB2ENR |= (1 << 6))   // Enable clock for GPIOE
#define GPIOF_PCLK_EN()  (RCC->RCC_APB2ENR |= (1 << 7))   // Enable clock for GPIOF
#define GPIOG_PCLK_EN()  (RCC->RCC_APB2ENR |= (1 << 8))   // Enable clock for GPIOG

// Clock Enable Macro for I2Cx peripherals
#define I2C1_PCLK_EN()   (RCC->RCC_AHB1ENR |= (1 << 21))  // Enable clock for I2C1
#define I2C2_PCLK_EN()   (RCC->RCC_AHB1ENR |= (1 << 22))  // Enable clock for I2C2

// Clock Enable Macro for SPIx peripherals
#define SPI2_PCLK_EN()   (RCC->RCC_AHB1ENR |= (1 << 14))  // Enable clock for SPI2
#define SPI3_PCLK_EN()   (RCC->RCC_AHB1ENR |= (1 << 15))  // Enable clock for SPI3

// Clock Enable Macro for USARTx peripherals
#define USART2_PCLK_EN() (RCC->RCC_AHB1ENR |= (1 << 17))  // Enable clock for USART2
#define USART3_PCLK_EN() (RCC->RCC_AHB1ENR |= (1 << 18))  // Enable clock for USART3
#define UART4_PCLK_EN()  (RCC->RCC_AHB1ENR |= (1 << 19))  // Enable clock for UART4
#define UART5_PCLK_EN()  (RCC->RCC_AHB1ENR |= (1 << 20))  // Enable clock for UART5


// Peripheral Clock Disable Macros

// Clock Disable Macro for GPIOx peripherals
#define GPIOA_PCLK_DI()  (RCC->RCC_APB2ENR &= ~(1 << 2))  // Disable clock for GPIOA
#define GPIOB_PCLK_DI()  (RCC->RCC_APB2ENR &= ~(1 << 3))  // Disable clock for GPIOB
#define GPIOC_PCLK_DI()  (RCC->RCC_APB2ENR &= ~(1 << 4))  // Disable clock for GPIOC
#define GPIOD_PCLK_DI()  (RCC->RCC_APB2ENR &= ~(1 << 5))  // Disable clock for GPIOD
#define GPIOE_PCLK_DI()  (RCC->RCC_APB2ENR &= ~(1 << 6))  // Disable clock for GPIOE
#define GPIOF_PCLK_DI()  (RCC->RCC_APB2ENR &= ~(1 << 7))  // Disable clock for GPIOF
#define GPIOG_PCLK_DI()  (RCC->RCC_APB2ENR &= ~(1 << 8))  // Disable clock for GPIOG

// Clock Disable Macro for I2Cx peripherals
#define I2C1_PCLK_DI()   (RCC->RCC_AHB1ENR &= ~(1 << 21)) // Disable clock for I2C1
#define I2C2_PCLK_DI()   (RCC->RCC_AHB1ENR &= ~(1 << 22)) // Disable clock for I2C2

// Clock Disable Macro for SPIx peripherals
#define SPI2_PCLK_DI()   (RCC->RCC_AHB1ENR &= ~(1 << 14)) // Disable clock for SPI2
#define SPI3_PCLK_DI()   (RCC->RCC_AHB1ENR &= ~(1 << 15)) // Disable clock for SPI3

// Clock Disable Macro for USARTx peripherals
#define USART2_PCLK_DI() (RCC->RCC_AHB1ENR &= ~(1 << 17)) // Disable clock for USART2
#define USART3_PCLK_DI() (RCC->RCC_AHB1ENR &= ~(1 << 18)) // Disable clock for USART3
#define UART4_PCLK_DI()  (RCC->RCC_AHB1ENR &= ~(1 << 19)) // Disable clock for UART4
#define UART5_PCLK_DI()  (RCC->RCC_AHB1ENR &= ~(1 << 20)) // Disable clock for UART5

#include <cstdint>

// RCC base address and register offsets
constexpr uint32_t RCC_BASE_ADDR = 0x40021000UL;
constexpr uint32_t RCC_CFGR_REG_OFFSET = 0x04UL;
constexpr uint32_t RCC_CR_REG_OFFSET = 0x00UL;
constexpr uint32_t RCC_APB2ENR_OFFSET = 0x18UL;

// RCC register addresses
constexpr uint32_t RCC_CFGR_REG_ADDR = RCC_BASE_ADDR + RCC_CFGR_REG_OFFSET;
constexpr uint32_t RCC_CR_REG_ADDR = RCC_BASE_ADDR + RCC_CR_REG_OFFSET;
constexpr uint32_t RCC_APB2ENR_REG_ADDR = RCC_BASE_ADDR + RCC_APB2ENR_OFFSET;

// GPIOA base address and register offsets
constexpr uint32_t GPIOA_BASE_ADDR = 0x40010800UL;
constexpr uint32_t GPIOA_CRH_OFFSET = 0x04UL;

// GPIOA register addresses
constexpr uint32_t GPIOA_CRH_REG_ADDR = GPIOA_BASE_ADDR + GPIOA_CRH_OFFSET;

int main(void)
{
    // Enable the HSE clock using the HSEON bit (RCC_CR)
    uint32_t* pRccCrReg = reinterpret_cast<uint32_t*>(RCC_CR_REG_ADDR);
    *pRccCrReg |= (1 << 16);

    // Wait until HSE clock from the external crystal stabilizes
    while (!(*pRccCrReg & (1 << 17)));

    // Switch the system clock to HSE (RCC_CFGR)
    uint32_t* pRccCfgrReg = reinterpret_cast<uint32_t*>(RCC_CFGR_REG_ADDR);
    *pRccCfgrReg |= (1 << 0);

    // Configure the RCC_CFGR MCO bit fields to select HSE as clock source
    *pRccCfgrReg &= ~(0x7 << 24);  // Clear bits 24, 25, and 26
    *pRccCfgrReg |= (0x4 << 24);   // Set HSE as MCO source

    // Enable the peripheral clock for GPIOA peripheral
    uint32_t* pRccApb2Enr = reinterpret_cast<uint32_t*>(RCC_APB2ENR_REG_ADDR);
    *pRccApb2Enr |= (1 << 2);  // Enable GPIOA peripheral clock

    // Configure the mode of GPIOA pin 8 as alternate function mode
    uint32_t* pGPIOA_CRH = reinterpret_cast<uint32_t*>(GPIOA_CRH_REG_ADDR);
    *pGPIOA_CRH &= ~(0xF << 0);  // Clear bits for PA8
    *pGPIOA_CRH |= (0xB << 0);   // Set PA8 to AF Push-Pull

    for (;;); 
}

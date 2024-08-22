#include <cstdint>  

// Base addresses for hardware peripherals
constexpr uint32_t ADC_BASE_ADDR = 0x40012400UL;
constexpr uint32_t RCC_BASE_ADDR = 0x40021000UL;

// Offsets 
constexpr uint32_t ADC_CR1_REG_OFFSET = 0x04UL; 
constexpr uint32_t RCC_APB2_ENR_OFFSET = 0x18UL;  

constexpr uint32_t ADC_CR1_REG_ADDR = ADC_BASE_ADDR + ADC_CR1_REG_OFFSET;  
constexpr uint32_t RCC_APB2_ENR_ADDR = RCC_BASE_ADDR + RCC_APB2_ENR_OFFSET; 

// Pointers to access the registers
// Use reinterpret_cast on the actual bit address values we want to change delcaring they are unsinged
// 32 bit interger while still keeping the orginal address declartion constexpr to tell the compiler
// that we know the value at compile time making it more optmized.

volatile uint32_t* const pAdcCr1Reg = reinterpret_cast<volatile uint32_t*>(ADC_CR1_REG_ADDR);
volatile uint32_t* const pRccApb2Enr = reinterpret_cast<volatile uint32_t*>(RCC_APB2_ENR_ADDR);

int main() {
    // Enable peripheral clock for ADC1 by setting the corresponding bit in the RCC_APB2_ENR register
    *pRccApb2Enr |= (1 << 9);  // Set bit 9 to enable ADC1 clock

    // Modify ADC CR1 Register
    *pAdcCr1Reg |= (1 << 8);  // Set bit 8 in ADC CR1 register 

    return 0;  // Exit the program
}

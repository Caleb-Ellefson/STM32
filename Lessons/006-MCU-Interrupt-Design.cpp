#include <cstdint>

// Base Addresses
constexpr uint32_t RCC_BASE_ADDR = 0x40021000UL;
constexpr uint32_t GPIOA_BASE_ADDR = 0x40010800UL;
constexpr uint32_t EXTI_BASE_ADDR = 0x40010400UL;
constexpr uint32_t NVIC_BASE_ADDR = 0xE000E100UL;

// Register Offsets
constexpr uint32_t RCC_APB2ENR_OFFSET = 0x18UL;
constexpr uint32_t GPIOA_CRH_OFFSET = 0x04UL;
constexpr uint32_t GPIOA_ODR_OFFSET = 0x0CUL;
constexpr uint32_t EXTI_IMR_OFFSET = 0x00UL;
constexpr uint32_t EXTI_RTSR_OFFSET = 0x08UL;
constexpr uint32_t EXTI_PR_OFFSET = 0x14UL;
constexpr uint32_t NVIC_ISER0_OFFSET = 0x00UL;

// Register Addresses
constexpr uint32_t RCC_APB2ENR_ADDR = RCC_BASE_ADDR + RCC_APB2ENR_OFFSET;
constexpr uint32_t GPIOA_CRH_ADDR = GPIOA_BASE_ADDR + GPIOA_CRH_OFFSET;
constexpr uint32_t GPIOA_ODR_ADDR = GPIOA_BASE_ADDR + GPIOA_ODR_OFFSET;
constexpr uint32_t EXTI_IMR_ADDR = EXTI_BASE_ADDR + EXTI_IMR_OFFSET;
constexpr uint32_t EXTI_RTSR_ADDR = EXTI_BASE_ADDR + EXTI_RTSR_OFFSET;
constexpr uint32_t EXTI_PR_ADDR = EXTI_BASE_ADDR + EXTI_PR_OFFSET;
constexpr uint32_t NVIC_ISER0_ADDR = NVIC_BASE_ADDR + NVIC_ISER0_OFFSET;

// Bit Masks
constexpr uint32_t RCC_APB2ENR_IOPAEN = (1 << 2);
constexpr uint32_t GPIO_CRH_MODE9_MASK = 0xF << (4 * 1); // PA9 is at position 4*1 in CRH
constexpr uint32_t GPIO_CRH_MODE9 = (0x03 << (4 * 1)); // PA9 as output (max speed 50MHz)
constexpr uint32_t GPIO_CRH_CNF9 = (0x00 << (4 * 1)); // PA9 as push-pull
constexpr uint32_t EXTI_IMR_MR8 = (1 << 8);
constexpr uint32_t EXTI_RTSR_TR8 = (1 << 8);
constexpr uint32_t EXTI_PR_PR8 = (1 << 8);
constexpr uint32_t NVIC_ISER_EXTI9 = (1 << 23); // Example IRQ number

void configure_gpio();
void configure_exti();
void configure_nvic();

extern "C" void EXTI9_IRQHandler(void);

int main() {
    // Enable GPIOA and AFIO clocks
    *reinterpret_cast<volatile uint32_t*>(RCC_APB2ENR_ADDR) |= RCC_APB2ENR_IOPAEN;

    // Configure GPIO pins PA8 and PA9
    configure_gpio();

    // Configure EXTI for PA8
    configure_exti();

    // Configure NVIC for EXTI9
    configure_nvic();

    while (true) {
        // Main loop
        // Optionally, you can add a delay or other code here
    }
}

void configure_gpio() {
    volatile uint32_t* gpio_crh = reinterpret_cast<volatile uint32_t*>(GPIOA_CRH_ADDR);

    // Configure PA9 as output (push-pull, max speed 50 MHz)
    *gpio_crh &= ~GPIO_CRH_MODE9_MASK; // Clear PA9 bits in CRH
    *gpio_crh |= (GPIO_CRH_MODE9 | GPIO_CRH_CNF9); // Set PA9 as output
}

void configure_exti() {
    volatile uint32_t* exti_imr = reinterpret_cast<volatile uint32_t*>(EXTI_IMR_ADDR);
    volatile uint32_t* exti_rtsr = reinterpret_cast<volatile uint32_t*>(EXTI_RTSR_ADDR);
    volatile uint32_t* exti_pr = reinterpret_cast<volatile uint32_t*>(EXTI_PR_ADDR);

    // Configure EXTI line 8 (connected to PA8) for rising edge trigger
    *exti_imr |= EXTI_IMR_MR8; // Unmask EXTI line 8
    *exti_rtsr |= EXTI_RTSR_TR8; // Trigger on rising edge

    // Clear any pending interrupt
    *exti_pr |= EXTI_PR_PR8;
}

void configure_nvic() {
    volatile uint32_t* nvic_iser0 = reinterpret_cast<volatile uint32_t*>(NVIC_ISER0_ADDR);
    *nvic_iser0 |= NVIC_ISER_EXTI9; // Enable EXTI line 9 interrupt
}

// EXTI line 9 interrupt handler
extern "C" void EXTI9_IRQHandler(void) {
    volatile uint32_t* exti_pr = reinterpret_cast<volatile uint32_t*>(EXTI_PR_ADDR);

    // Clear the EXTI line 9 pending bit
    *exti_pr |= EXTI_PR_PR8;

    // Set PA9 high to light up the LED
    volatile uint32_t* gpioa_odr = reinterpret_cast<volatile uint32_t*>(GPIOA_ODR_ADDR);
    *gpioa_odr |= (1 << 9); // Set PA9 high

    // Optional: Add some delay or reset PA9 low if needed
}

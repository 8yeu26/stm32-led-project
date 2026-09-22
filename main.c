#define RCC_BASE        0x40021000
#define GPIOA_BASE      0x40010800
#define GPIOC_BASE      0x40011000

#define RCC_APB2ENR     (*(volatile unsigned int *)(RCC_BASE + 0x18))
#define GPIOA_CRL       (*(volatile unsigned int *)(GPIOA_BASE + 0x00))
#define GPIOC_CRH       (*(volatile unsigned int *)(GPIOC_BASE + 0x04))
#define GPIOA_ODR       (*(volatile unsigned int *)(GPIOA_BASE + 0x0C))
#define GPIOC_ODR       (*(volatile unsigned int *)(GPIOC_BASE + 0x0C))

void Delay_ms(unsigned int t)
{
    unsigned int i,j;
    for(i = t; i > 0; i--)
        for(j = 7200; j > 0; j--);
}

int main(void)
{
    RCC_APB2ENR |= (1<<2) | (1<<4);

    GPIOA_CRL &= ~(0x0F << 4);
    GPIOA_CRL |=  (0x03 << 4);
    GPIOA_CRL &= ~(0x0F << 8);
    GPIOA_CRL |=  (0x03 << 8);
    GPIOA_CRL &= ~(0x0F << 12);
    GPIOA_CRL |=  (0x03 << 12);

    GPIOC_CRH &= ~(0x0F << 20);
    GPIOC_CRH |=  (0x03 << 20);

    GPIOA_ODR |= (1<<1) | (1<<2) | (1<<3);
    GPIOC_ODR |= (1<<13);

    while(1)
    {
        GPIOA_ODR &= ~(1<<1);
        Delay_ms(1000);
        GPIOA_ODR |= (1<<1);

        GPIOA_ODR &= ~(1<<2);
        Delay_ms(1000);
        GPIOA_ODR |= (1<<2);

        GPIOA_ODR &= ~(1<<3);
        Delay_ms(1000);
        GPIOA_ODR |= (1<<3);

        GPIOC_ODR &= ~(1<<13);
        Delay_ms(1000);
        GPIOC_ODR |= (1<<13);
    }
}

void SystemInit(void)
{

}
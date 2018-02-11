#ifndef DELAY_H_
#define DELAY_H_


#ifdef __cplusplus
extern "C" {
#endif

//void delay_us(uint32_t us);
#define delay_ms(us) LL_mDelay(us)
//void Delay(__IO uint32_t nTime);

//void TimingDelay_Decrement(void);
//static __IO uint32_t TimingDelay;

#ifdef __cplusplus
}
#endif

#endif

#ifndef __DMA_H
#define	__DMA_H


#include "stm32f10x.h"


// ���ڶ�Ӧ��DMA����ͨ��
#define  USART_TX_DMA_CHANNEL     DMA1_Channel4

// ����Ĵ�����ַ
#define  USART_DR_ADDRESS        (USART1_BASE+0x04)
// һ�η��͵�������
#define  SENDBUFF_SIZE            16

#define    ADC_DMA_CLK                   RCC_AHBPeriph_DMA1


void DMA_E2M_IT_Config(void);
void DMA_M2E_IT_Config(void);

#endif /* __DAC_H */


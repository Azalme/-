	
#include "bsp_dma.h"	
#include "stm32f10x.h"	
#include "bsp_dac.h"
#include "bsp_usart.h"
#include "bsp_adc.h"
#include "bsp_key.h"  
#include "gpio.h"



extern __IO uint16_t SendBuff[SENDBUFF_SIZE];
float local[32];//���ת������ֵ


// �ֲ����������ڱ���ת�������ĵ�ѹֵ 	 
//float ADC_ConvertedValueLocal;        

// �����ʱ
void Delay(__IO uint32_t nCount)
{
  for(; nCount != 0; nCount--);
} 



int main(void)
{	
	LED_GPIO_Config();
	LED1_TOGGLE;
	int i;
	gpio_config();
	Delay(5000);
	i=judge();	
	//int a=1;
	
  EXTI_Key_Config();
	DAC_Mode_Init(i);
	// ���ô���
	USART_Config();

	// ADC ��ʼ��
	ADCx_Init(i);
	Delay(5000);

		/*
		a=50;
		LED1_TOGGLE;
		
    //����жϱ�־λ
		EXTI_ClearITPendingBit(KEY1_INT_EXTI_LINE); 
	
		DAC_Mode_Init(i);
		// ADC ��ʼ��
		ADCx_Init(i);
		Delay(5000);
	if(EXTI_GetITStatus(KEY1_INT_EXTI_LINE) != RESET) 
	{
		i=i+1;
		LED1_TOGGLE;
		
    //����жϱ�־λ
		EXTI_ClearITPendingBit(KEY1_INT_EXTI_LINE); 
	
		DAC_Mode_Init(i);
		// ADC ��ʼ��
		ADCx_Init(i);
		Delay(5000);
	}*/
  //��������
	//USART_DMACmd(DEBUG_USARTx, USART_DMAReq_Tx, ENABLE);
	while(1)
	{
	 for(i=0;i<16;i++)
 			{
 				local[i]=(float)SendBuff[i]/4096*3.3;
 			}
	 
	 
		for(i=0;i<16;i++)
		{
				printf("%f\\",local[i]);
		}
				printf("\n");
				Delay(1500000);
		//a=a-1;
		}
		//i=i+1;
}	

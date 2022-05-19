#include "bsp_adc.h"
#include "bsp_dma.h"	


//__IO uint16_t ADC_Count=0;


/**
  * @brief  ADC GPIO ��ʼ��
  * @param  ��
  * @retval ��
  */
void ADCx_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	// �� ADC IO�˿�ʱ��
	ADC_GPIO_APBxClock_FUN ( ADC_GPIO_CLK, ENABLE );
	
	// ���� ADC IO ����ģʽ
	// ����Ϊģ������
	GPIO_InitStructure.GPIO_Pin = ADC_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	
	// ��ʼ�� ADC IO
	GPIO_Init(ADC_PORT, &GPIO_InitStructure);				
}

/**
  * @brief  ����ADC����ģʽ
  * @param  ��
  * @retval ��
  */
void ADCx_Mode_Config(int a)
{
	ADC_InitTypeDef ADC_InitStructure;	
	
	// ��ADCʱ��
	ADC_APBxClock_FUN ( ADC_CLK, ENABLE );
	
	/****************************************/
	DMA_E2M_IT_Config();//DMA����
	/****************************************/
	
	// ADC ģʽ����
	// ֻʹ��һ��ADC�����ڶ���ģʽ
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
	
	// ��ֹɨ��ģʽ����ͨ����Ҫ����ͨ������Ҫ
	ADC_InitStructure.ADC_ScanConvMode = ENABLE ; 
	// ����ת��ģʽ
	ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;

	// �����ⲿ����ת���������������
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None; 

	// ת������Ҷ���
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
	
	// ת��ͨ��1��
	ADC_InitStructure.ADC_NbrOfChannel = 1;	
		
	// ��ʼ��ADC
	ADC_Init(ADC1, &ADC_InitStructure);
	
	// ����ADCʱ��ΪPCLK2��8��Ƶ����9MHz
	RCC_ADCCLKConfig(RCC_PCLK2_Div8); 
	
	// ���� ADC ͨ��ת��˳��Ͳ���ʱ��         һ���ڲ���16�� ���������T=T/16       ��ӦT=��12.5+adcSampleTime)*t(adc����Ƶ��)��t=1/f)
																																									//��f(����Ƶ��)=f(����Ŀ��)*16=f(ʱ��Ƶ��)/��12.5+adcSampleTime)
																																									//����sampletimeΪ71ʱΪ6700HZ���� 1Ϊ40180HZ����  41-13700
		if(a==-1)                                                                       //2232HZ
		{
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 1, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 2, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 3, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 4, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 5, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 6, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 7, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 8, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 9, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 10, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 11, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 12, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 13, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 14, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 15, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 16, ADC_SampleTime_239Cycles5);
		}									
			else
			if(a==0)                                                                       //2232HZ
		{
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 1, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 2, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 3, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 4, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 5, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 6, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 7, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 8, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 9, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 10, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 11, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 12, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 13, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 14, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 15, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 16, ADC_SampleTime_239Cycles5);
		}
	else																																						
	if(a==1)
	{
	ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 1, ADC_SampleTime_71Cycles5);       //6700HZ
	ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 2, ADC_SampleTime_71Cycles5);
	ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 3, ADC_SampleTime_71Cycles5);
	ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 4, ADC_SampleTime_71Cycles5);
	ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 5, ADC_SampleTime_71Cycles5);
	ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 6, ADC_SampleTime_71Cycles5);
	ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 7, ADC_SampleTime_71Cycles5);
	ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 8, ADC_SampleTime_71Cycles5);
	ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 9, ADC_SampleTime_71Cycles5);
	ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 10, ADC_SampleTime_71Cycles5);
	ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 11, ADC_SampleTime_71Cycles5);
	ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 12, ADC_SampleTime_71Cycles5);
	ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 13, ADC_SampleTime_71Cycles5);
	ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 14, ADC_SampleTime_71Cycles5);
	ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 15, ADC_SampleTime_71Cycles5);
	ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 16, ADC_SampleTime_71Cycles5);
	}
	else 
		if(a==2)                                                                       //13700HZ
		{
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 1, ADC_SampleTime_28Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 2, ADC_SampleTime_28Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 3, ADC_SampleTime_28Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 4, ADC_SampleTime_28Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 5, ADC_SampleTime_28Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 6, ADC_SampleTime_28Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 7, ADC_SampleTime_28Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 8, ADC_SampleTime_28Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 9, ADC_SampleTime_28Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 10, ADC_SampleTime_28Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 11, ADC_SampleTime_28Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 12, ADC_SampleTime_28Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 13, ADC_SampleTime_28Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 14, ADC_SampleTime_28Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 15, ADC_SampleTime_28Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 16, ADC_SampleTime_28Cycles5);
		}
	else 
		if(a==3)                                                                       //40180HZ
		{
				ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 1, ADC_SampleTime_1Cycles5);
				ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 2, ADC_SampleTime_1Cycles5);
				ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 3, ADC_SampleTime_1Cycles5);
				ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 4, ADC_SampleTime_1Cycles5);
				ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 5, ADC_SampleTime_1Cycles5);
				ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 6, ADC_SampleTime_1Cycles5);
				ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 7, ADC_SampleTime_1Cycles5);
				ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 8, ADC_SampleTime_1Cycles5);
				ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 9, ADC_SampleTime_1Cycles5);
				ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 10, ADC_SampleTime_1Cycles5);
				ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 11, ADC_SampleTime_1Cycles5);
				ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 12, ADC_SampleTime_1Cycles5);
				ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 13, ADC_SampleTime_1Cycles5);
				ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 14, ADC_SampleTime_1Cycles5);
				ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 15, ADC_SampleTime_1Cycles5);
				ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 16, ADC_SampleTime_1Cycles5);
		}
		
	// ADC ת�����������жϣ����жϷ�������ж�ȡת��ֵ
	//ADC_ITConfig(ADCx, ADC_IT_EOC, ENABLE);                      //���ڼ���ת������
	
		// ʹ��ADC DMA ����
	ADC_DMACmd(ADC1, ENABLE);
	
	// ����ADC ������ʼת��
	ADC_Cmd(ADC1, ENABLE);
	
	// ��ʼ��ADC У׼�Ĵ���  
	ADC_ResetCalibration(ADC1);
	// �ȴ�У׼�Ĵ�����ʼ�����
	while(ADC_GetResetCalibrationStatus(ADC1));
	
	// ADC��ʼУ׼
	ADC_StartCalibration(ADC1);
	// �ȴ�У׼���
	while(ADC_GetCalibrationStatus(ADC1));
	
	// ����û�в����ⲿ����������ʹ���������ADCת�� 
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);                //������������
}
/*
static void ADC_NVIC_Config(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;
	// ���ȼ�����
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

  // �����ж����ȼ�
  NVIC_InitStructure.NVIC_IRQChannel = ADC_IRQ;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
}
*/

/**
  * @brief  ADC��ʼ��
  * @param  ��
  * @retval ��
  */
void ADCx_Init(int i)
{
	ADCx_GPIO_Config();
	ADCx_Mode_Config(i);
	//ADC_NVIC_Config();
}
/*********************************************END OF FILE**********************/

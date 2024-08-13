#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "CLCD_interface.h"
#include <util/delay.h>


void main(void)
{
	PORT_voidInit();
	CLCD_voidInit();
	sint8 Local_u8LoopCounter1;
	sint8 Local_u8LoopCounter2;
	uint8 Local_u8Temp;
	uint8 Arr[8]={'S','A','P','O','N','B','C','O'};



	//CLCD_voidSendSpecialCharacter(Local_u8MyPattern,0,0,0);
	//CLCD_voidSendBinaryNum(64);
	//CLCD_voidSendHexaNum(0xABCDEF);


	//sint32 x=-100300;


	//CLCD_voidSendNumber(x);

	while(1)
	{
		//char string1[]="ayhaga3ady";
		//CLCD_u8SinWaveSendString(string1);
		for(Local_u8LoopCounter1=0;Local_u8LoopCounter1<8;Local_u8LoopCounter1++)
		{
			for(Local_u8LoopCounter2=Local_u8LoopCounter1+1;Local_u8LoopCounter2<8;Local_u8LoopCounter2++)
			{
				if(Arr[Local_u8LoopCounter1]<Arr[Local_u8LoopCounter2])
				{
					Local_u8Temp=Arr[Local_u8LoopCounter1];
					Arr[Local_u8LoopCounter1]=Arr[Local_u8LoopCounter2];
					Arr[Local_u8LoopCounter2]=Local_u8Temp;
				}
			}
		}
		for(Local_u8LoopCounter2=15;Local_u8LoopCounter2>=-5;Local_u8LoopCounter2--)
		{
			CLCD_voidSendComd(1);
			CLCD_voidGoToXY(Local_u8LoopCounter2,1);
			for(Local_u8LoopCounter1=4;Local_u8LoopCounter1>=0;Local_u8LoopCounter1--)
			{
				CLCD_voidSendData(Arr[Local_u8LoopCounter1]);
			}
			_delay_ms(100);
		}
	}

}


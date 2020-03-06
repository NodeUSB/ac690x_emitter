#ifndef __LCD_DRV_API_H__
#define __LCD_DRV_API_H__

#include "sdk_cfg.h"
#include "rtc/rtc_api.h"

///************************************************************/
///****************������Ļ�Ĵ�С
///****************˵������������һ�����Ӧһ��bit
///************************************************************/
#define  LCDPAGE            8
#define  LCDCOLUMN          128

#define SCR_WIDTH           LCDCOLUMN
#define SCR_HEIGHT          (LCDPAGE*8)

//SPI1�ӿ�ѡ��
#if 1//
//SPI1A
//#define LCD_SPI_SET_GROUP()       do{JL_IOMAP->CON1 &= ~BIT(4);}while(0)
//#define LCD_SPI_SET_DATAIN()      do{JL_PORTB->DIR &= ~BIT(10);}while(0)
//#define LCD_SPI_SET_CLK()	      do{JL_PORTB->DIR &= ~BIT(11);}while(0)
//#define LCD_SPI_SET_DATAOUT()     do{JL_PORTB->DIR &= ~BIT(12);}while(0)

#define LCD_SPI_SET_GROUP()       do{JL_IOMAP->CON1 |= BIT(16);}while(0)
#define LCD_SPI_SET_DATAIN()      do{JL_PORTC->DIR  &= ~BIT(2);}while(0)
#define LCD_SPI_SET_CLK()	      do{JL_PORTC->DIR  &= ~BIT(0);}while(0)
#define LCD_SPI_SET_DATAOUT()     do{JL_PORTC->DIR  &= ~BIT(1);}while(0)


#else
//SPI1B
#define LCD_SPI_SET_GROUP()       do{JL_IOMAP->CON1  |= BIT(4);}while(0)
#define LCD_SPI_SET_DATAIN()      do{PORTC_DIR &= ~BIT(2);}while(0)
#define LCD_SPI_SET_CLK()	      do{PORTC_DIR &= ~BIT(5);}while(0)
#define LCD_SPI_SET_DATAOUT()     do{PORTC_DIR &= ~BIT(8);}while(0)

#endif

#define LCD_DATA_OUT()
#define	LCD_CLK_OUT()
#define LCD_SPI_SET_MODE_OUT()       do{JL_SPI2->CON &= ~BIT(3);}while(0)
#define LCD_SPI_SET_MODE_INOUT()     do{JL_SPI2->CON |= BIT(3);}while(0)


#define	LCD_A0_OUT()	    do{JL_PORTC->DIR &= ~BIT(2);}while(0)
#define	LCD_A0_L()	        do{JL_PORTC->OUT &= ~BIT(2);}while(0)
#define	LCD_A0_H()	        do{JL_PORTC->OUT |= BIT(2);}while(0)

#define LCD_RES_OUT()	    do{JL_PORTC->DIR &= ~BIT(3);}while(0)//
#define LCD_RES_L()	        do{JL_PORTC->OUT &= ~BIT(3);}while(0)
#define LCD_RES_H()	        do{JL_PORTC->OUT |= BIT(3);}while(0)

#define LCD_CS_OUT()	    do{JL_PORTC->DIR &= ~BIT(4);}while(0)//
#define LCD_CS_L()	        do{JL_PORTC->OUT &= ~BIT(4);}while(0)
#define LCD_CS_H()	        do{JL_PORTC->OUT |= BIT(4);}while(0)


#define LCD_BL_ON()         do{PORTR_DIR(PORTR0,0);PORTR_OUT(PORTR0,1);}while(0)
#define LCD_PORT_OUT()      do{LCD_DATA_OUT();LCD_CLK_OUT();LCD_A0_OUT();LCD_RES_OUT();LCD_CS_OUT();}while(0)
#define LCD_PORT_OUT_H()    do{LCD_DATA_OUT();LCD_CLK_OUT();LCD_A0_H();  LCD_RES_H();	LCD_CS_H();}while(0)

//ȫ�ֱ�������
extern u8 disp_buf[];

//��������
void draw_lcd_buf(void);
void lcd_clear(void);
void lcd_init(void);
void lcd_hardware_init(void);
void lcd_128x64_set(u8 page,u8 column);
extern bool font_init(u8 language);
#endif/*__LCD_DRV_API_H__*/

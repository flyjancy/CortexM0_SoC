#include "code_def.h"
#include <stdint.h>
#include "camera_initial_reg_file.h"

uint32_t Read_CAMERA_DATA_STATE(void)
{
	return(CAMERA_CONFIG->CAMERA_DATA_STATE);
}

void Set_CAMERA_DATA_STATE(uint32_t state)
{
	CAMERA_CONFIG->CAMERA_DATA_STATE = state;
}
uint32_t Read_CAMERA_SDA(void)
{
    return(CAMERA_CONFIG->CAMERA_CONFIG_SDAI);
}
void Set_CAMERA_SDA_W(void)
{
    CAMERA_CONFIG->CAMERA_CONFIG_SDAOEN = 1;
}
void Set_CAMERA_SDA_R(void)
{
    CAMERA_CONFIG->CAMERA_CONFIG_SDAOEN = 0;
}
void Set_CAMERA_SCL(void)
{
    CAMERA_CONFIG->CAMERA_CONFIG_SCL = 1;
}
void Clr_CAMERA_SCL(void)
{
    CAMERA_CONFIG->CAMERA_CONFIG_SCL = 0;
}
void Set_CAMERA_SDA(void)
{
    CAMERA_CONFIG->CAMERA_CONFIG_SDAO = 1;
}
void Clr_CAMERA_SDA(void)
{
    CAMERA_CONFIG->CAMERA_CONFIG_SDAO = 0;
}
void Set_CAMERA_PWDN(void)
{
    CAMERA_CONFIG->CAMERA_CONFIG_PWDN = 1;
}
void Clr_CAMERA_PWDN(void)
{
    CAMERA_CONFIG->CAMERA_CONFIG_PWDN = 0;
}
void Set_CAMERA_RST(void)
{
    CAMERA_CONFIG->CAMERA_CONFIG_RST = 1;
}
void Clr_CAMERA_RST(void)
{
    CAMERA_CONFIG->CAMERA_CONFIG_RST = 0;
}
void CAMERA_Start(void)
{
	
	Set_CAMERA_SDA();
    Set_CAMERA_SCL();
	delay(80);
    Clr_CAMERA_SDA();
    delay(80);
    Clr_CAMERA_SCL();
}
void CAMERA_Stop(void)
{
	Clr_CAMERA_SDA();
    delay(80);
    Set_CAMERA_SCL();
	delay(80);
	Set_CAMERA_SDA();
    delay(80);
}
void CAMERA_Waite(void)
{
	delay(80);
    Set_CAMERA_SCL();
    delay(100);
    Clr_CAMERA_SCL();
}
void CAMERA_NA(void)
{
	delay(80);
	Set_CAMERA_SDA();
	Set_CAMERA_SCL();	
	delay(80);
	Clr_CAMERA_SCL();
	delay(80);
	Clr_CAMERA_SDA();
	delay(80);
}
void CAMERA_Write_Byte(uint8_t data)
{
	uint8_t j;	 
	for(j=0;j<8;j++)
	{
		if(data&0x80)Set_CAMERA_SDA();
		else Clr_CAMERA_SDA();
		data<<=1;
        delay(20);
		Set_CAMERA_SCL();	
		delay(80);
		Clr_CAMERA_SCL();
        delay(80);		   
	}			 
	Set_CAMERA_SDA_R();		
	delay(80);
	Set_CAMERA_SCL();			
	delay(80);        
	Clr_CAMERA_SCL();	 
	Set_CAMERA_SDA_W();		   
}
uint8_t CAMERA_Read_Byte(void)
{
    uint8_t temp=0,j;    
	Set_CAMERA_SDA_R();		
	for(j=8;j>0;j--) 
	{		     	  
		delay(80);
		Set_CAMERA_SCL();
		temp=temp<<1;
		if(Read_CAMERA_SDA())
            temp++;   
		delay(80);
		Clr_CAMERA_SCL();
	}	
	Set_CAMERA_SDA_W();		   
	return temp;
}

uint8_t CAMERA_Read_Reg(uint16_t reg)
{
    uint8_t val;
    CAMERA_Start();
    CAMERA_Write_Byte(0x78);
    //CAMERA_Waite();
    CAMERA_Write_Byte(reg >> 8);
    //CAMERA_Waite();
    CAMERA_Write_Byte(reg);
    //CAMERA_Waite();
    CAMERA_Stop();
    delay(100);
    CAMERA_Start();
    CAMERA_Write_Byte(0x79);
    //CAMERA_Waite();
    val = CAMERA_Read_Byte();
    CAMERA_NA();
    CAMERA_Stop();
    return val;
}
void CAMERA_Command(uint8_t addr_h,uint8_t addr_l,uint8_t data)
{
	CAMERA_Start();
	CAMERA_Write_Byte(0x78);
    //CAMERA_Waite();
	CAMERA_Write_Byte(addr_h);
    //CAMERA_Waite();
	CAMERA_Write_Byte(addr_l);
    //CAMERA_Waite();
	CAMERA_Write_Byte(data);
    //CAMERA_Waite();
	CAMERA_Stop();
}

void CAMERA_Initial(void)
{
    Set_CAMERA_SDA_W();
	Clr_CAMERA_PWDN();
	delay(100);
	Set_CAMERA_RST();
	delay(100);

    uint16_t reg;
    reg  = CAMERA_Read_Reg(0x300a);
    reg <<= 8;
    reg |= CAMERA_Read_Reg(0x300b);
    
    
    uint32_t i;
    // QVGA RGB565
	for(i=0;i<sizeof(camera_initial_reg)/3;i++) 
		CAMERA_Command(camera_initial_reg[i][0],camera_initial_reg[i][1],camera_initial_reg[i][2]);
    
    //FA INITIAL
    CAMERA_Command(0x30,0x00,0x20);

    uint16_t addr = 0x8000;
    uint8_t state = 0x8f;
    uint16_t iteration = 100;

    for(i=0;i<sizeof(OV5640_AF_FW);i++) 
	{
		CAMERA_Command(addr >> 8,addr,OV5640_AF_FW[i]);
		addr++;
	}  
    CAMERA_Command(0x30,0x22, 0x00);
    CAMERA_Command(0x30,0x23, 0x00);
    CAMERA_Command(0x30,0x24, 0x00);
    CAMERA_Command(0x30,0x25, 0x00);
    CAMERA_Command(0x30,0x26, 0x00);
    CAMERA_Command(0x30,0x27, 0x00);
    CAMERA_Command(0x30,0x28, 0x00);
    CAMERA_Command(0x30,0x29, 0xFF);
    CAMERA_Command(0x30,0x00, 0x00);
    CAMERA_Command(0x30,0x04, 0xFF);
    CAMERA_Command(0x00,0x00, 0x00);
    CAMERA_Command(0x00,0x00, 0x00);
    CAMERA_Command(0x00,0x00, 0x00);
    CAMERA_Command(0x00,0x00, 0x00);

    do {
        state = (uint8_t)CAMERA_Read_Reg(0x3029);
        delay(10);
        if (iteration-- == 0)
        {	
            break;
        }
    } 
    while(state!=0x70);

    //LIGHT MODE
    CAMERA_Command(0x32,0x12,0x03);	
	for(i=0;i<7;i++)
        CAMERA_Command((0x3400+i >>8 ),0x3400+i,OV5640_LIGHTMODE_TBL[i]); 
	CAMERA_Command(0x32,0x12,0x13); 
	CAMERA_Command(0x32,0x12,0xa3);

    //COLOR SATURATION
	CAMERA_Command(0x32,0x12,0x03);	
	CAMERA_Command(0x53,0x81,0x1c);
	CAMERA_Command(0x53,0x82,0x5a);
	CAMERA_Command(0x53,0x83,0x06);
	for(i=0;i<6;i++)
        CAMERA_Command((0x5384+i) >> 8,0x5384+i,OV5640_SATURATION_TBL[i]);
	CAMERA_Command(0x53,0x8b, 0x98);
	CAMERA_Command(0x53,0x8a, 0x01);
	CAMERA_Command(0x32,0x12, 0x13); 
	CAMERA_Command(0x32,0x12, 0xa3); 

    //BRIGHTNESS
    uint8_t brtval;
	brtval=0;
	CAMERA_Command(0x32,0x12,0x03);	
	CAMERA_Command(0x55,0x87,brtval<<4);
	CAMERA_Command(0x55,0x88,0x01);
	CAMERA_Command(0x32,0x12,0x13); 
	CAMERA_Command(0x32,0x12,0xa3);

    //CONTRAST
    uint8_t reg0val=0X00;
	uint8_t reg1val=0X20;
	CAMERA_Command(0x32,0x12,0x03); 
	CAMERA_Command(0x55,0x85,reg0val);
	CAMERA_Command(0x55,0x86,reg1val); 
	CAMERA_Command(0x32,0x12,0x13);
	CAMERA_Command(0x32,0x12,0xa3); 

    //SHARPNESS
    CAMERA_Command(0x53,0x08,0x25);
	CAMERA_Command(0x53,0x00,0x08);
	CAMERA_Command(0x53,0x01,0x30);
	CAMERA_Command(0x53,0x02,0x10);
	CAMERA_Command(0x53,0x03,0x00);
	CAMERA_Command(0x53,0x09,0x08);
	CAMERA_Command(0x53,0x0a,0x30);
	CAMERA_Command(0x53,0x0b,0x04);
	CAMERA_Command(0x53,0x0c,0x06);

    //FA CONSTANT
    CAMERA_Command(0x30,0x23,0x01);
    CAMERA_Command(0x30,0x22,0x04);
    iteration = 5000;
    do {
    	 state = (uint8_t)CAMERA_Read_Reg(0x3023);
        if (iteration-- == 0)
        {
            break ;
        }
        delay(10);
    } while(state!=0x00);
    
   
}
uint32_t Read_CAMERA_DATA_LEN(void)
{
    return(CAMERA_CONFIG->CAMERA_DATA_LEN);
}

void photo()
{
    Set_CAMERA_DATA_STATE(1);
	while (Read_CAMERA_DATA_STATE());
}
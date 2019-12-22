#include <stdint.h>

//INTERRUPT DEF
#define NVIC_CTRL_ADDR (*(volatile unsigned *)0xe000e100)

//CAMERA DEF
typedef struct{
    volatile uint16_t CAMERA_VALUE[240][320];
}CAMERAType;

#define CAMERA_BASE 0x40300000
#define CAMERA ((CAMERAType *)CAMERA_BASE)

//CAMERA CONFIG DEF
typedef struct{
    volatile uint32_t CAMERA_CONFIG_RST;
    volatile uint32_t CAMERA_CONFIG_PWDN;
    volatile uint32_t CAMERA_CONFIG_SCL;
    volatile uint32_t CAMERA_CONFIG_SDAO;
    volatile uint32_t CAMERA_CONFIG_SDAI;
    volatile uint32_t CAMERA_CONFIG_SDAOEN;
    volatile uint32_t CAMERA_DATA_STATE;
    volatile uint32_t CAMERA_DATA_LEN;
}CAMERA_CONFIGType;

#define CAMERA_CONFIG_BASE 0x40330000
#define CAMERA_CONFIG ((CAMERA_CONFIGType *)CAMERA_CONFIG_BASE)


//LCD DEF
typedef struct {
    volatile uint32_t LCD_CS; // 0x40050000
    volatile uint32_t LCD_RS; // 0x40050004
    volatile uint32_t LCD_WR; // 0x40050008
    volatile uint32_t LCD_RD; // 0x4005000C
    volatile uint32_t LCD_RST;// 0x40050010
    volatile uint32_t LCD_BL_CTR;// 0x40050014
    volatile uint32_t LCD_DATA[16];// 0x40050018-0x40050054
}LCDType;

#define LCD_BASE 0x40050000
#define LCD ((LCDType *)LCD_BASE)

//SysTick DEF
typedef struct{
    volatile uint32_t CTRL;
    volatile uint32_t LOAD;
    volatile uint32_t VALUE;
    volatile uint32_t CALIB;
}SysTickType;

#define SysTick_BASE 0xe000e010
#define SysTick ((SysTickType *)SysTick_BASE)

//UART DEF
typedef struct{
    volatile uint32_t UARTRX_DATA;
    volatile uint32_t UARTTX_STATE;
    volatile uint32_t UARTTX_DATA;
}UARTType;

#define UART_BASE 0x40000010
#define UART ((UARTType *)UART_BASE)

// UART
char ReadUARTState(void);
char ReadUART(void);
void WriteUART(char data);
void UARTString(char *stri);
void UARTHandle(void);

//SCB DEF
typedef struct
{
  volatile uint32_t CPUID;                  
  volatile uint32_t ICSR;                   
  volatile uint32_t VTOR;                   
  volatile uint32_t AIRCR;                  
  volatile uint32_t SCR;                    
  volatile uint32_t CCR;                    
  volatile uint8_t  SHP[12];                
  volatile uint32_t SHCSR;                  
  volatile uint32_t CFSR;                   
  volatile uint32_t HFSR;                   
  volatile uint32_t DFSR;                   
  volatile uint32_t MMFAR;                  
  volatile uint32_t BFAR;                   
  volatile uint32_t AFSR;                   
  volatile uint32_t PFR[2];                 
  volatile uint32_t DFR;                    
  volatile uint32_t ADR;                    
  volatile uint32_t MMFR[4];                
  volatile uint32_t ISAR[5];                
  volatile uint32_t RESERVED0[5];
  volatile uint32_t CPACR;                  
} SCBType;

#define SCB_BASE 0xe000ed00
#define SCB ((SCBType *)SCB_BASE)

// SYSTICK
void SysTickHandler(void);
void Set_SysTick_CTRL(uint32_t ctrl);
void Set_SysTick_LOAD(uint32_t load);
uint32_t Read_SysTick_VALUE(void);
void Set_SysTick_VALUE(uint32_t value);
void Set_SysTick_CALIB(uint32_t calib);
uint32_t Timer_Ini(void);
uint8_t Timer_Stop(uint32_t *duration_t,uint32_t start_t);

// DELAY FUNC
void delay(uint32_t time);

// INTERUPT
void KEY0(void);
void KEY1(void);
void KEY2(void);
void KEY3(void);

// CAMERA
void Set_CAMERA_SDA_W(void);
void Set_CAMERA_SDA_R(void);
void Set_CAMERA_SCL(void);
void Clr_CAMERA_SCL(void);
void Set_CAMERA_RST(void);
void Clr_CAMERA_RST(void);
void Set_CAMERA_PWDN(void);
void Clr_CAMERA_PWDN(void);
void Set_CAMERA_SDA(void);
uint32_t Read_CAMERA_SDA(void);
void Clr_CAMERA_SDA(void);
void CAMERA_Start(void);
void CAMERA_Stop(void);
void CAMERA_Waite(void);
void CAMERA_Write_Byte(uint8_t data);
void CAMERA_Command(uint8_t addr_h,uint8_t addr_l,uint8_t data);
void CAMERA_Data(uint8_t data);
void CAMERA_Initial(void);
uint32_t Read_CAMERA_DATA_STATE(void);
void Set_CAMERA_DATA_STATE(uint32_t state);
uint32_t Read_CAMERA_DATA_LEN(void);
uint8_t CAMERA_Read_Byte(void);
uint8_t CAMERA_Read_Reg(uint16_t reg);
uint8_t CAMERA_Focus_Init(void);
void CAMERA_Light_Mode(void);	
void CAMERA_Color_Saturation(void);
void CAMERA_Brightness(void);	
void CAMERA_Contrast(void);	
void CAMERA_Sharpness(void);	
uint8_t CAMERA_Focus_Constant(void);
void CAMERA_NA(void);
void photo();

//  LCD 
typedef struct  
{										    
	uint16_t width;			
	uint16_t height;			
	uint16_t id;				
	uint8_t  dir;			
	uint16_t wramcmd;		
	uint16_t setxcmd;		
	uint16_t setycmd;		
}_lcd_dev; 	  

extern _lcd_dev lcddev;

extern uint16_t  POINT_COLOR;  
extern uint16_t  BACK_COLOR; 

//      BASIC SIGNAL SET AND CLEAR
#define LCD_CS_SET         (LCD->LCD_CS        = 1) 	 
#define LCD_RS_SET         (LCD->LCD_RS        = 1) 
#define LCD_WR_SET         (LCD->LCD_WR        = 1) 
#define LCD_RD_SET         (LCD->LCD_RD        = 1) 
#define LCD_RST_SET        (LCD->LCD_RST       = 1)
#define LCD_BL_CTR_SET     (LCD->LCD_BL_CTR    = 1)
     
#define LCD_CS_CLR         (LCD->LCD_CS        = 0) 	 
#define LCD_RS_CLR         (LCD->LCD_RS        = 0) 
#define LCD_WR_CLR         (LCD->LCD_WR        = 0) 
#define LCD_RD_CLR         (LCD->LCD_RD        = 0) 
#define LCD_RST_CLR        (LCD->LCD_RST       = 0)
#define LCD_BL_CTR_CLR     (LCD->LCD_BL_CTR    = 0)
     
//      DATA     
#define LCD_DATA0_SET( x )   (LCD->LCD_DATA[0]   = (x))
#define LCD_DATA1_SET( x )   (LCD->LCD_DATA[1]   = (x)) 	  	 
#define LCD_DATA2_SET( x )   (LCD->LCD_DATA[2]   = (x)) 	 
#define LCD_DATA3_SET( x )   (LCD->LCD_DATA[3]   = (x)) 	 
#define LCD_DATA4_SET( x )   (LCD->LCD_DATA[4]   = (x)) 	 
#define LCD_DATA5_SET( x )   (LCD->LCD_DATA[5]   = (x)) 	 
#define LCD_DATA6_SET( x )   (LCD->LCD_DATA[6]   = (x)) 	 
#define LCD_DATA7_SET( x )   (LCD->LCD_DATA[7]   = (x)) 	 
#define LCD_DATA8_SET( x )   (LCD->LCD_DATA[8]   = (x)) 	 
#define LCD_DATA9_SET( x )   (LCD->LCD_DATA[9]   = (x)) 	 
#define LCD_DATA10_SET( x )  (LCD->LCD_DATA[10]  = (x)) 	 
#define LCD_DATA11_SET( x )  (LCD->LCD_DATA[11]  = (x)) 	 
#define LCD_DATA12_SET( x )  (LCD->LCD_DATA[12]  = (x)) 	 
#define LCD_DATA13_SET( x )  (LCD->LCD_DATA[13]  = (x)) 	 
#define LCD_DATA14_SET( x )  (LCD->LCD_DATA[14]  = (x)) 	 
#define LCD_DATA15_SET( x )  (LCD->LCD_DATA[15]  = (x)) 	 

// #define LCD_WR_DATA(data){\
// LCD_RS_SET;\
// LCD_CS_CLR;\
// MakeData(data);\
// LCD_WR_CLR;\
// LCD_WR_SET;\
// LCD_CS_SET;\
// } 

//      SCANNING DIRECTION
#define L2R_U2D  0 // LEFT TO RIGHT, UP TO DOWN
#define L2R_D2U  1 // LEFT TO RIGHT, DOWN TO UP
#define R2L_U2D  2 // RIGHT TO LEFT, UP TO DOWN
#define R2L_D2U  3 // RIGHT TO LEFT, DOWN TO UP

#define U2D_L2R  4 // UP TO DOWN, LEFT TO RIGHT
#define U2D_R2L  5 // UP TO DOWN, RIGHT TO LEFT
#define D2U_L2R  6 // DOWN TO UP, LEFT TO RIGHT
#define D2U_R2L  7 // DOWN TO UP, RIGHT TO LEFT

#define DFT_SCAN_DIR    L2R_U2D // DEFAULT

//  PEN COLOR
#define WHITE         	 0xFFFF
#define BLACK         	 0x0000	  
#define BLUE         	 0x001F  
#define BRED             0XF81F
#define GRED 			 0XFFE0
#define GBLUE			 0X07FF
#define RED           	 0xF800
#define MAGENTA       	 0xF81F
#define GREEN         	 0x07E0
#define CYAN          	 0x7FFF
#define YELLOW        	 0xFFE0
#define BROWN 			 0XBC40 
#define BRRED 			 0XFC07 
#define GRAY  			 0X8430 

//  GUI COLOR ( COLOR OF PANEL )
#define DARKBLUE      	 0X01CF	
#define LIGHTBLUE      	 0X7D7C	 
#define GRAYBLUE       	 0X5458 


#define LIGHTGREEN     	 0X841F 
#define LGRAY 			 0XC618 // BACKGROUND COLOR OF WINDOW

#define LGRAYBLUE        0XA651 // MIDDLE LAYER COLOR
#define LBBLUE           0X2B12 // COLOR OF SWITCHED

//  LCD RESOLUTION
#define SSD_HOR_RESOLUTION		800		// LCD HORIZON RESOLUTION
#define SSD_VER_RESOLUTION		480		// LCD VERTICAL RESOLUTION

//  LCD DRIVING PARAMETER
#define SSD_HOR_PULSE_WIDTH		1		
#define SSD_HOR_BACK_PORCH		46		
#define SSD_HOR_FRONT_PORCH		210		

#define SSD_VER_PULSE_WIDTH		1		
#define SSD_VER_BACK_PORCH		23		
#define SSD_VER_FRONT_PORCH		22		

//  AUTO CALCULATE
#define SSD_HT	(SSD_HOR_RESOLUTION+SSD_HOR_BACK_PORCH+SSD_HOR_FRONT_PORCH)
#define SSD_HPS	(SSD_HOR_BACK_PORCH)
#define SSD_VT 	(SSD_VER_RESOLUTION+SSD_VER_BACK_PORCH+SSD_VER_FRONT_PORCH)
#define SSD_VPS (SSD_VER_BACK_PORCH)  	

void LCD_Init(uint8_t dir);									
void LCD_DisplayOn(void);													
void LCD_DisplayOff(void);													
void LCD_Clear(uint16_t Color);	 											
void LCD_SetCursor(uint16_t Xpos, uint16_t Ypos);							
void LCD_DrawPoint(uint16_t x,uint16_t y);									
void LCD_Fast_DrawPoint(uint16_t x,uint16_t y,uint16_t color);							
uint16_t  LCD_ReadPoint(uint16_t x,uint16_t y); 										
void LCD_Draw_Circle(uint16_t x0,uint16_t y0,uint8_t r);						 		
void LCD_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);					
void LCD_DrawRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);		   		
void LCD_Fill(uint16_t sx,uint16_t sy,uint16_t ex,uint16_t ey,uint16_t color);		   	
void LCD_Color_Fill(uint16_t sx,uint16_t sy,uint16_t ex,uint16_t ey,uint16_t *color);	
void LCD_ShowChar(uint16_t x,uint16_t y,uint8_t num,uint8_t size,uint8_t mode);			
void LCD_ShowNum(uint16_t x,uint16_t y,uint32_t num,uint8_t len,uint8_t size);  					
void LCD_ShowxNum(uint16_t x,uint16_t y,uint32_t num,uint8_t len,uint8_t size,uint8_t mode);				
void LCD_ShowString(uint16_t x,uint16_t y,uint16_t width,uint16_t height,uint8_t size,uint8_t *p);		

void LCD_WriteReg(uint16_t LCD_Reg, uint16_t LCD_RegValue);
uint16_t LCD_ReadReg(uint16_t LCD_Reg);
void LCD_WriteRAM_Prepare(void);
void LCD_WriteRAM(uint16_t RGB_Code);
void LCD_SSD_BackLightSet(uint8_t pwm);							
void LCD_Scan_Dir(uint8_t dir);									
void LCD_Display_Dir(uint8_t dir);
void LCD_Set_Window(uint16_t sx,uint16_t sy,uint16_t width,uint16_t height);

# Copyright (C) 2018  Intel Corporation. All rights reserved.
# Your use of Intel Corporation's design tools, logic functions 
# and other software and tools, and its AMPP partner logic 
# functions, and any output files from any of the foregoing 
# (including device programming or simulation files), and any 
# associated documentation or information are expressly subject 
# to the terms and conditions of the Intel Program License 
# Subscription Agreement, the Intel Quartus Prime License Agreement,
# the Intel FPGA IP License Agreement, or other applicable license
# agreement, including, without limitation, that your use is for
# the sole purpose of programming logic devices manufactured by
# Intel and sold by Intel or its authorized distributors.  Please
# refer to the applicable agreement for further details.

# Quartus Prime Version 18.1.0 Build 625 09/12/2018 SJ Lite Edition
# File: C:\Users\range\Desktop\CortexM0_SoC\QUARTUS\CortexM0_SoC.tcl
# Generated on: Sat Dec 21 22:04:50 2019

package require ::quartus::project

set_location_assignment PIN_W16 -to clk
set_location_assignment PIN_C6 -to RSTn
set_location_assignment PIN_AA20 -to LCD_DATA[14]
set_location_assignment PIN_G10 -to row[3]
set_location_assignment PIN_AA22 -to LCD_DATA[12]
set_location_assignment PIN_Y19 -to LCD_DATA[10]
set_location_assignment PIN_W21 -to LCD_DATA[8]
set_location_assignment PIN_W19 -to LCD_DATA[6]
set_location_assignment PIN_V21 -to LCD_DATA[4]
set_location_assignment PIN_V15 -to LCD_DATA[2]
set_location_assignment PIN_F10 -to row[2]
set_location_assignment PIN_L7 -to row[1]
set_location_assignment PIN_K7 -to row[0]
set_location_assignment PIN_T13 -to LCD_DATA[0]
set_location_assignment PIN_J7 -to col[0]
set_location_assignment PIN_J8 -to col[1]
set_location_assignment PIN_H8 -to col[2]
set_location_assignment PIN_G8 -to col[3]
set_location_assignment PIN_P7 -to SWCLK
set_location_assignment PIN_R7 -to SWDIO
set_location_assignment PIN_AB17 -to LCD_BL_CTR
set_location_assignment PIN_AB18 -to LCD_DATA[15]
set_location_assignment PIN_AA19 -to LCD_DATA[13]
set_location_assignment PIN_AB22 -to LCD_DATA[11]
set_location_assignment PIN_Y20 -to LCD_DATA[9]
set_location_assignment PIN_Y21 -to LCD_DATA[7]
set_location_assignment PIN_V20 -to LCD_DATA[5]
set_location_assignment PIN_U22 -to LCD_DATA[3]
set_location_assignment PIN_V14 -to LCD_DATA[1]
set_location_assignment PIN_R14 -to LCD_CS
set_location_assignment PIN_T12 -to LCD_RST
set_location_assignment PIN_T14 -to LCD_WR
set_location_assignment PIN_P14 -to LCD_RS
set_location_assignment PIN_U15 -to LCD_RD
set_location_assignment PIN_AA13 -to CAMERA_VSYNC
set_location_assignment PIN_V18 -to CAMERA_DATA[7]
set_location_assignment PIN_Y22 -to CAMERA_DATA[6]
set_location_assignment PIN_W22 -to CAMERA_DATA[5]
set_location_assignment PIN_AA17 -to CAMERA_DATA[4]
set_location_assignment PIN_AA18 -to CAMERA_DATA[3]
set_location_assignment PIN_Y16 -to CAMERA_DATA[2]
set_location_assignment PIN_Y17 -to CAMERA_DATA[1]
set_location_assignment PIN_Y14 -to CAMERA_DATA[0]
set_location_assignment PIN_AA15 -to CAMERA_HREF
set_location_assignment PIN_Y15 -to CAMERA_RST
set_location_assignment PIN_AA14 -to CAMERA_SCL
set_location_assignment PIN_AB15 -to CAMERA_SDA
set_location_assignment PIN_V19 -to CAMERA_PCLK
set_location_assignment PIN_AB20 -to CAMERA_PWDN

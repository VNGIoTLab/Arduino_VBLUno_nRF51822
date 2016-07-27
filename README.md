#VBLUno_nRF51822 - Arduino

These is packages that help use Arduino for VBLUno_nRF51822 BLE kit


##Hardware

1. Kit VBLUno nRF51822 (http://iotviet.com.vn/store/detail?id=2)

  * Nordic nRF51822 with Cortex-M0 32bit CPU
  * Bluetooth Low Energy interface
  * Compatible Arduino Uno pinout 
  * I2C, UART, SWD, 30 GPIOs
  * 256KB Rom
  * 32KB Ram
  * Support Arduino, mbed,...
  * Upload firmware: SWD (CMSIS-DAP), Serial

2. Kit BLE_NANO and BLE_NANO_CRICLE: Comming soon

 
##Requirements

1. Python 2.7: Select 32bit version at https://www.python.org/downloads/release/python-2712/

2. Tool pc-nrfutil-0.3.0: https://github.com/NordicSemiconductor/pc-nrfutil/releases/tag/v0.3.0
  * Device Firmware Update procedure over Serial and Bluetooth Low Energy
  * To install, please see readme.md and requirement.txt in that package


##Install Board Package Add-on

1. Get Arduino IDE from Arduino website and install it to your PC
           http://arduino.cc/en/Main/Software

2. Start the IDE and from the Menu, click "Preference...", add the following line to "Additional Boards Manager URLs"
           https://raw.githubusercontent.com/VNGIoTLab/Arduino_VBLUno_nRF51822/master/package_vngiotlab_index.json

3. Install the "VNGIoTLab VBLUno nRF51822 Boards" add-on via Boards Manager from the Menu: Tools -> Board -> Boards Manager ...

##Bootloaders
The VBLUno nRF51822 boards are proloaded the bootloader already. Normally, you can skip this step. 

In the "VNGIoTLab_VBLUno_nRF51822_board_v100.zip\bootloader" folder, there is a firmware (bootloader.hex) for the VBLUno nRF51822 board, it allows you to load Arduino sketch using the Arduino IDE over Serial.

To load the bootloader, connect the board to your PC using a CMSIS-DAP module over SWD interface, it will prompt a drive (MBED), drag the bootloader firmware to the drive.

## How to Play

1. Select board and serial port

  Select the VBLUno nRF51822 (V1.0 32KB) board from the menu of the Arduino IDE,

    Menu > Tools > Board > RBL nRF51822
    
  
  Select the serial port for print out with the USB Interface Dongle,
  
    Menu > Tools > Port > [you board serial port name]
  
2. Blink

  To test the board, we suggest you to load the Blink example to see if it works.

    Menu > File > Examples > 01.Basics > Blink

  Use the upload icon to load the sketch to your board.
  
3. BLE Examples

  There are some BLE examples you can try.
  
    Menu > File > BLE_Examples

  #### BLE_HRM
   
  This is an Heart Rate Monitor demo, it simulates Heart Rate detection. You can use Nordic nRFToolBox App to play.

  #### BLE_Beacon
    
  This is to implement Apple's iBeacon, you can try it with our BeaconTool available in the AppStore for iOS and PlayStore for Android.

  #### SimpleControls
  
  This sample shows how to define your own protocol and to control the I/O of the board from a Central (e.g. iPhone) using the BLE Controller App.
  
  #### SimpleChat
  
  This sample allows you to send text message from the board to your central device such as iPhone or Android using the BLE Controller App.
  
  #### BLEController

  This example allows you to use the BLE Controller App (available for iOS and Android) to control the pin state such as High, Low, PWM, Analog, etc.
  
  #### nRF51822_UART
  
  This example allows you to exchange data with your central device (e.g. iPhone 5) and the data will be redirected to the UART.


##Links:
- http://iotviet.com.vn/store/detail?id=2
- https://www.facebook.com/bleviet/?fref=ts
- https://www.facebook.com/iotviet.vn/?fref=ts

##License
Copyright (c) 2016 VNGIoTLab

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

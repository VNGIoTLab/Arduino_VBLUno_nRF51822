# VNGIoTLab VBLUno nRF518 boards (version 1 & 2) on Arduino IDE
These are packages that help to use Arduino IDE for VBLUno_nRF51822 BLE boards (version 1 & 2)

## Lựa chọn ngôn ngữ / Select language:
1. [Ngôn ngữ tiếng Việt](https://github.com/VNGIoTLab/Arduino_VBLUno_nRF51822#ngôn-ngữ-tiếng-việt)
2. [English language](https://github.com/VNGIoTLab/Arduino_VBLUno_nRF51822#english-language)

# Ngôn ngữ tiếng Việt

## Chú ý


**0. TÀI LIỆU, HƯỚNG DẪN SỬ DỤNG VỀ BO MẠCH VBLUno51, VUI LÒNG TRUY CẬP [VBLUNO51 WIKI PAGES](https://vngiotlab.github.io/vbluno/)**

1. [TUTORIALS](https://github.com/VNGIoTLab/Arduino_VBLUno_nRF51822/tree/master/Tutorial)

2. Phiên bản hiện tại: v2.0.0 (Bổ sung gói cài đặt cho VBLUno version 2, nạp tự động qua DAPLink ).
Phiên bản: v1.0.4 (Bổ sung gói cài đặt online cho MacOSX). Trước khi nâng cấp phiên bản, bạn cần remove phiên bản cũ hơn.
3. [Các video demo sử dụng Arduino cho VBLUno kit](https://github.com/VNGIoTLab/Arduino_VBLUno_nRF51822#các-video-demo-cho-vbluno-kit)
4. Mọi vấn đề gặp phải khi sử dụng Arduino IDE cho kit VBLUno, các bạn có thể viết tại [ĐÂY](https://github.com/VNGIoTLab/Arduino_VBLUno_nRF51822/issues)

## Tính năng
1. Các tài nguyên này cho phép sử dụng Arduino IDE để lập trình, biên dịch chương trình điều khiển (firmware) cho mạch phát triển VBLUno và BLE Nano.
2. Nạp firmware cho mạch qua cổng nối tiếp (Cổng USB trên mạch VBLUno)
3. Cung cấp các hàm API giao tiếp Bluetooth Low Energy (BLE) cho SoftDevice S130, hỗ trợ vai trò BLE Central và BLE Peripheral.
4. Hỗ trợ cài đặt online và offline.
5. Đã kiểm tra chạy tốt trên các hệ điều hành:
	* Microsoft Windows 7 – 64 bit.
	* Microsoft Windows 10 – 64 bit.
	* Ubuntu 14.04 LTS – 64 bit.
	* Ubuntu 16.04 LTS – 64 bit.
	* MacOSX

## Phần cứng
1. [Kit VBLUno nRF51822 của VNGIoTLab](http://iotviet.com.vn/store/detail?id=2)
    * Chip Nordic nRF51822 với lõi Cortex-M0 32bit
    * Giao tiếp Bluetooth Low Energy
    * Tương thích chuẩn pinout của Arduino Uno
    * I2C, SPI, UART, SWD, 30 GPIOs
    * 256KB Flash
    * 32KB Ram
    * Hỗ trợ Arduino, ARM mbed, Nordic SDK, Apache Mynewt, RIOT-OS…
    * Nạp firmware: SWD (CMSIS-DAP), Serial
    * Sơ đồ nguyên lý: [Xem tại đây](https://github.com/VNGIoTLab/Arduino_VBLUno_nRF51822/raw/master/Schematic_and_Pinout/VBLUno_V1_BLE_ARDUINO_SCHEMATIC.pdf)
    * Hình ảnh sơ đồ chân: ![alt tag](https://github.com/VNGIoTLab/Arduino_VBLUno_nRF51822/blob/master/Schematic_and_Pinout/VBLUno_V1_Pinout.jpg)

## Cài đặt các thành phần cần thiết

### 1. Cài đặt trình điều khiển cho chip CP210x – USB to UART

* Nếu đã cài đặt, bạn có thể  bỏ qua bước này

* Thực hiện: Tải trình điều khiển phù hợp tại [ĐÂY](https://www.silabs.com/products/mcu/Pages/USBtoUARTBridgeVCPDrivers.aspx) và cài đặt vào máy
          

### 2. Cài đặt Arduino IDE

* Nếu đã cài đặt, bạn có thể  bỏ qua bước này

* Thực hiện: Tải bản cài đặt phù hợp tại [ĐÂY](http://arduino.cc/en/Main/Software) và cài đặt vào máy. 

* Chú ý: Nếu bạn đang sử dụng hệ điều hành Linux (tương tự với MacOSX), cần chạy Arduino IDE với quyền root. Điều này giúp Arduino IDE có thể mở cổng nối tiếp (UART) để nạp firmware cho mạch VBLUno.
    * Mở Terminal (Ctrl + Alt + T)
    * Chuyển đến thư mục đã cài đặt Arduino bằng cách sử dụng lệnh “cd”. 
                       Ví dụ cd /home/mrABC/arduino-1.6.10
    * Mở Arduino IDE với lệnh sudo: sudo ./aduino


### 3. Cài đặt gói dữ liệu của mạch VBLUno cho Arduino IDE

**_Cách 1: Cài đặt online_**

  * Chạy Arduino IDE, vào menu File, chọn "Preferences", thêm dòng sau vào ô  "Additional Boards Manager URLs": `https://raw.githubusercontent.com/VNGIoTLab/Arduino_VBLUno_nRF51822/master/package_vngiotlab_vbluno_index.json`
  *Chú ý: * Bạn có thể thêm nhiều địa chỉ URLs tại đây, phân tách chúng bởi dấy phẩy. 	 
  
     
  * Cài đặt dữ liệu "VNGIoTLab VBLUno nRF51822 Boards" thông qua Trình quản lý boards (Boards Manager) 
    * Từ menu: Tools -> Board -> Boards Manager ...
    * Chọn VNGIoTLab VBLUno nRF51822 Boards và nhấn Install

**_Cách 2: Cài đặt offline_**

  * Bạn cần chắc chắn Arduino IDE không được mở trong quá trình cài đặt offline.
     
  * Tải bản cài đặt phù hợp với hệ điều hành: 
    * [Cho Windows](https://github.com/VNGIoTLab/Arduino_VBLUno_nRF51822/tree/master/Setup_Offline/Windows)
    * [Cho Linux](https://github.com/VNGIoTLab/Arduino_VBLUno_nRF51822/tree/master/Setup_Offline/Linux)
	* [Cho MacOSX](https://github.com/VNGIoTLab/Arduino_VBLUno_nRF51822/tree/master/Setup_Offline/Mac)
	  

  * Giải nén và chạy file cài đặt 
    * Windows: Setup_VBLUno_Windows.exe
    * Linux: 
    `cd Setup_Offline_VBLUno_Linux_xxx`
   `chmod 777 Setup_VBLUno_Linux`
    `sudo ./Setup_VBLUno_Linux` . Chú ý phải sử dụng lệnh sudo
    * Bạn chờ đến khi chương trình thông báo “The installation was successful” là quá trình cài đặt đã hoàn thành.
  
  * Chú ý: Từ bây giờ, tại Preferences->Additional Boards Manager URLs luôn phải có nội dung sau (các packages khác nhau được phân tách bởi dấy phẩy):
  `https://raw.githubusercontent.com/VNGIoTLab/Arduino_VBLUno_nRF51822/master/package_vngiotlab_vbluno_index.json`
## Bootloaders
	
* Bootloader giúp Arduino IDE nạp firmware cho VBLUno thông qua cổng USB gắn trên mạch (USB to UART). Mạch VBLUno khi bán ra đã được nạp sẵn bootloader. **_Thông thường, bạn có thể bỏ qua bước này._**

* Trong thư mục "VBLUno_nRF51822_board\bootloader" có chứa file bootloader_38400.hex và mã nguồn tương ứng. Đây là bootloader cho phép Arduino IDE nạp (upload) firmware xuống VBLUno thông qua cổng nối tiếp.

* Để nạp bootloader, kết nối mạch với PC sử dụng mô đun CMSIS-DAP qua giao tiếp SWD (J5), nó sẽ tạo ra một ổ đĩa ảo (MBED), kéo thả bootloader.hex vào ổ đĩa ảo này.

## Bắt đầu sử dụng

**1. Kết nối mạch VBLUno với PC thông qua cổng USB trên mạch.**

  * Chuyển cầu nối trên jump J7 về vị trí cho phép nạp firmware qua cổng USB bằng bootloader (vị trí 1-2, gần phía Jack nguồn màu đen).
     
  * Sau đó ấn nút Reset. Lúc này quan sát thấy sáng cả 2 led trên mạch.

**2. Mở Arduino IDE trên PC**

**3. Chọn board và cổng nối tiếp**

  * Chọn VNGIoTLab nRF51822 board từ menu của Arduino IDE:
    * Menu > Tools > Board > VBLUno_V1_nRF51822_32KB(v1.0.4)

  * Chọn cổng nối tiếp tương ứng của VBLUno:
    * Menu > Tools > Port > [tên cổng nối tiếp của VBLUno]

**4. Ví dụ nháy led (Blink)**

  * Để kiểm tra mạch, chúng tôi đề nghị bạn sử dụng ví dụ điều khiển nháy led sau.
    * Menu > File > Examples > 01.Basics > Blink

  * Sử dụng chức năng upload (Menu -> Sketch -> Upload) để biên dịch chương trình và nạp firmware xuống mạch VBLUno.
     
  * Nếu biên dịch và nạp thành công, bạn sẽ nhận được thông báo “Device programmed”

  * Chuyển cầu nối trên jump J7 về vị trí cho phép chạy Application (vị trí 2-3, gần phía cổng USB)

**5. Ví dụ cho BLE**
  * Ngoài các ví dụ cơ bản của Arduino, VBLUno hỗ trợ sẵn nhiều ví dụ sử dụng giao tiếp Bluetooth Low Energy (BLE)
  * Bạn có thể thử các ví dụ bằng cách vào Menu > File > BLE_Examples

	*BLE HRM*: This is an Heart Rate Monitor demo, it simulates Heart Rate detection. You can use Nordic nRFToolBox App to play.

	*BLE Beacon*: This is to implement Apple's iBeacon, you can try it with our BeaconTool available in the AppStore for iOS and PlayStore for Android.

	*Simple Controls*: This sample shows how to define your own protocol and to control the I/O of the board from a Central (e.g. iPhone) using the BLE Controller App.

	*Simple Chat*: This sample allows you to send text message from the board to your central device such as iPhone or Android using the BLE Controller App.

	*BLE Controller*: This example allows you to use the BLE Controller App (available for iOS and Android) to control the pin state such as High, Low, PWM, Analog, etc.

	*BLE Serial*: This example allows you to exchange data with your central device (e.g. iPhone 5) and the data will be redirected to the UART.
	
	*.....*



## Các link hữu ích

- [Website: www.iotviet.com.vn](http://iotviet.com.vn/store/detail?id=2)
- [Page Bluetooth Low Energy Vietnam - BLE](https://www.facebook.com/bleviet/?fref=ts)
- [Page Cộng đồng IoT Việt](https://www.facebook.com/iotviet.vn/?fref=ts)

## Các video demo cho VBLUno kit

1. [Ví dụ thực hiện BLE_Serial trên kit VBLUno với Arduino IDE - Ubuntu](https://www.youtube.com/watch?v=U4xNDTFVvXg)

## Giấy phép

Bản quyền (c) 2016 VNGIoTLab

Các tài liệu này được công bố dạng mã nguồn mở nhằm mục đích hỗ trợ cộng đồng phát triển. Ngoài ra cũng mong nhận được sự phản hồi, đóng góp từ cộng đồng.

------------------------------------------------------------------------------------------------------------------------------

# English Language

## Note

**0. DOCUMENTS, USER MANUALS, TUTORIALS FOR THE VBLUNO51 BOARD, PLEASE ACCESS [VBLUNO51 WIKI PAGES](https://vngiotlab.github.io/vbluno/)**

1. [TUTORIALS](https://github.com/VNGIoTLab/Arduino_VBLUno_nRF51822/tree/master/Tutorial)
2. Current version: v2.0.0 (Support for VBLUno version 2, auto upload firmware over DAPLink interface).
Version: v1.0.4 (Add installation for MacOSX). Before update version, you need to remove old versions.
3. [Demo videos for VBLUno kit]( https://github.com/VNGIoTLab/Arduino_VBLUno_nRF51822#video-demos-for-vbluno-kit)
4. All issues you can meet when using Arduino IDE for VBLUno kit, you can post at [HERE](https://github.com/VNGIoTLab/Arduino_VBLUno_nRF51822/issues)

## Features
1. Adds support for the Arduino IDE enables compiling firmwares for the VBLUno_nRF51822 and BLE Nano development boards.
2. Upload sketches over Serial (USB port on VBLUno)
3. Provides BLE API for SoftDevice S130 with concurrent BLE Central and Peripheral role support.
4. Install online and offline.
5. Operating Systems (Current tested versions):
	* Microsoft Windows 7 – 64 bit.
	* Microsoft Windows 10 – 64 bit.
	* Ubuntu 14.04 LTS – 64 bit.
	* Ubuntu 16.04 LTS – 64 bit.
	* MacOSX.

## Hardware
1. [Kit VBLUno nRF51822 of VNGIoTLab](http://iotviet.com.vn/store/detail?id=2)
    * Nordic nRF51822 with Cortex-M0 32bit CPU
    * Bluetooth Low Energy interface
    * Compatible with Arduino Uno pinout
    * I2C, SPI, UART, SWD, 30 GPIOs
    * 256KB Flash
    * 32KB Ram
    * Support Arduino, ARM mbed, Nordic SDK, Apache Mynewt, RIOT-OS…
    * Upload firmware: SWD (CMSIS-DAP), Serial
    * Schematic: [HERE](https://github.com/VNGIoTLab/Arduino_VBLUno_nRF51822/raw/master/Schematic_and_Pinout/VBLUno_V1_BLE_ARDUINO_SCHEMATIC.pdf)
    * Pinout:  ![alt tag](https://github.com/VNGIoTLab/Arduino_VBLUno_nRF51822/blob/master/Schematic_and_Pinout/VBLUno_V1_Pinout.jpg)


## Installation

### 1. Install driver for chip CP210x – USB to UART

* If you installed, you can pass this step

* Download suitable drivers at [HERE](https://www.silabs.com/products/mcu/Pages/USBtoUARTBridgeVCPDrivers.aspx) and then install
          

### 2. Install Arduino IDE

* If you installed, you can pass this step

* Download suitable software at [HERE](http://arduino.cc/en/Main/Software) and then install.

* Note: If you are using a Linux OS (MacOSX), you need to run Arduino IDE with root permission. This can help Arduino can open serial ports to upload firmware for VBLUno kit.
    * Open Terminal (Ctrl + Alt + T)
    * Moving  to directory which is already installed  Arduino by using “cd” command.
                       For example: cd /home/mrABC/arduino-1.6.10
    * Open Arduino IDE by “sudo” command:  sudo ./aduino


### 3. Install packages of VBLUno board for Arduino IDE
You can install by one of two methods following

**_Method 1: Install online_**

  * Open Arduino IDE, at File,select "Preferences", add the following line to "Additional Boards Manager URLs": https://raw.githubusercontent.com/VNGIoTLab/Arduino_VBLUno_nRF51822/master/package_vngiotlab_vbluno_index.json
  (You can add multiple URLs, separating them with commas)
     
  * Install the "VNGIoTLab VBLUno nRF51822 Boards" add-on via Boards Manager
    * From menu bar: Tools -> Board -> Boards Manager ...
    * Select VNGIoTLab VBLUno nRF51822 Boards and then click  Install

**_Method 2: Install offline_**

  * You should be sured Arduino IDE cannot be opened while install offline.
     
  * Download suitable softwares for OS: 
    * [For Windows](https://github.com/VNGIoTLab/Arduino_VBLUno_nRF51822/tree/master/Setup_Offline/Windows)
    * [For Linux](https://github.com/VNGIoTLab/Arduino_VBLUno_nRF51822/tree/master/Setup_Offline/Linux)
	* [For MacOSX](https://github.com/VNGIoTLab/Arduino_VBLUno_nRF51822/tree/master/Setup_Offline/Mac)
	
  * Extract and run setup file
    * Windows: Setup_VBLUno_Windows.exe
    * Linux: 
    `cd Setup_Offline_VBLUno_Linux_xxx`
   `chmod 777 Setup_VBLUno_Linux`
    `sudo ./Setup_VBLUno_Linux` 
    * You have to wait until the program announce “The installation was successful” 
  
  * Note: Preferences->Additional Boards Manager URLs always has this content (You can add multiple URLs, separating them with commas):
  `https://raw.githubusercontent.com/VNGIoTLab/Arduino_VBLUno_nRF51822/master/package_vngiotlab_vbluno_index.json`

## Bootloaders
	
* Bootloader helps Arduino IDE can upload firmware for VBLUno boards via serial ports.  VBLUno boards are sold , bootloaders are preloaded. **_Normally, you can skip this step._**

* In the folder is named "VBLUno_nRF51822_board\bootloader", it contains bootloader_38400.hex and  source code.

* To load bootloader, connect the board with your PC, using a CMSIS-DAP module via SWD interface (J5), it will create a virtual disk (MBED), drag and drop bootloader.hex into this disk.

## How to play

**1. Connect VBLUno board to PC via USB port**

  * Switch bridge at jump J7 to position allow to upload firmware through serial ports (USB ports on VBLUno boards) by bootloaders (position 1-2, near black Power jack).
     
  * Then press Reset button. At this time, two Leds on board are lighting up.

**2. Open Arduino IDE**

**3. Select board and serial port**

  * Select VNGIoTLab nRF51822 board from Arduino IDE menu:
    * Menu > Tools > Board > VBLUno_V1_nRF51822_32KB(v1.0.4)

  * Select the serial port of VBLUno board:
    * Menu > Tools > Port > [you board serial port name]

**4. Blink**

  * To test the board, we suggest you to load the Blink example to see if it works.
    * Menu > File > Examples > 01.Basics > Blink

  * Use the upload icon to load the sketch to your board.
     
  * If it is compiled and uploaded successfully, you will be received the annoucement  “Device programmed”
  
  * Switch bridge at jump J7 to position allow to run Application (position 2-3, near USB port).

**5. BLE Examples**
  * Beside Arduino basic examples, VBLUno packages support some examples use Bluetooth Low Energy (BLE) interface.
  * You can try by select Menu > File > BLE_Examples

	*BLE HRM*: This is an Heart Rate Monitor demo, it simulates Heart Rate detection. You can use Nordic nRFToolBox App to play.

	*BLE Beacon*: This is to implement Apple's iBeacon, you can try it with our BeaconTool available in the AppStore for iOS and PlayStore for Android.

	*Simple Controls*: This sample shows how to define your own protocol and to control the I/O of the board from a Central (e.g. iPhone) using the BLE Controller App.

	*Simple Chat*: This sample allows you to send text message from the board to your central device such as iPhone or Android using the BLE Controller App.

	*BLE Controller*: This example allows you to use the BLE Controller App (available for iOS and Android) to control the pin state such as High, Low, PWM, Analog, etc.

	*BLE Serial*: This example allows you to exchange data with your central device (e.g. iPhone 5) and the data will be redirected to the UART.
	
	*.....*



## Useful links

- [Website: www.iotviet.com.vn](http://iotviet.com.vn/store/detail?id=2)
- [Page Bluetooth Low Energy Vietnam - BLE](https://www.facebook.com/bleviet/?fref=ts)
- [Page IoT Viet Community](https://www.facebook.com/iotviet.vn/?fref=ts)

## Video Demos for VBLUno Kit

1. [ BLE_Serial example on VBLUno kit with Arduino IDE - Ubuntu](https://www.youtube.com/watch?v=U4xNDTFVvXg)

## License

Copyright (c) 2016 VNGIoTLab

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

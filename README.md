#VNGIoTLab VBLUno nRF51822 kit on Arduino IDE
These is packages that help use Arduino IDE for VBLUno_nRF51822 BLE kit

##Lựa chọn ngôn ngữ / Select language:
1. Ngôn ngữ tiếng Việt: https://github.com/VNGIoTLab/Arduino_VBLUno_nRF51822#ngôn-ngữ-tiếng-việt
2. English language. https://github.com/VNGIoTLab/Arduino_VBLUno_nRF51822#english-language

#Ngôn ngữ tiếng Việt

##Chú ý
1. Phiên bản hiện tại: v1.0.1
2. Các video demo sử dụng Arduino cho VBLUno kit: https://github.com/VNGIoTLab/Arduino_VBLUno_nRF51822#các-video-demo-cho-vbluno-kit

##Tính năng
1. Các tài nguyên này cho phép sử dụng Arduino IDE để lập trình, biên dịch chương trình điều khiển (firmware) cho mạch phát triển VBLUno và BLE Nano.
2. Nạp firmware cho mạch qua cổng nối tiếp (Cổng USB trên mạch VBLUno)
3. Cung cấp các hàm API giao tiếp Bluetooth Low Energy (BLE) cho SoftDevice S130, hỗ trợ vai trò BLE Central và BLE Peripheral.
4. Hỗ trợ cài đặt online và offline.
5. Đã kiểm tra chạy tốt trên các hệ điều hành:
	* Microsoft Windows 7 – 64 bit.
	* Microsoft Windows 10 – 64 bit.
	* Ubuntu 14.04 LTS – 64 bit.

##Phần cứng
1. Kit VBLUno nRF51822 (http://iotviet.com.vn/store/detail?id=2)
    * Chip Nordic nRF51822 với lõi Cortex-M0 32bit
    * Giao tiếp Bluetooth Low Energy
    * Tương thích chuẩn pinout của Arduino Uno
    * I2C, SPI, UART, SWD, 30 GPIOs
    * 256KB Flash
    * 32KB Ram
    * Hỗ trợ Arduino, mbed,…
    * Nạp firmware: SWD (CMSIS-DAP), Serial
    * Sơ đồ nguyên lý: https://github.com/VNGIoTLab/Arduino_VBLUno_nRF51822/raw/master/VBLUno_BLE_ARDUINO%20UNO%20SCHEMATIC.pdf
    * Hình ảnh sơ đồ chân: 

2. Mạch BLE_NANO và BLE_NANO_CIRCLE: Sắp giới thiệu

##Cài đặt các thành phần cần thiết

1. Cài đặt trình điều khiển cho chip CP210x – USB to UART
    * Nếu đã cài đặt, bạn có thể  bỏ qua bước này
    * Thực hiện: Tải trình điều khiển phù hợp tại link sau và cài đặt vào máy
          https://www.silabs.com/products/mcu/Pages/USBtoUARTBridgeVCPDrivers.aspx


2. Cài đặt Arduino IDE
    * Nếu đã cài đặt, bạn có thể  bỏ qua bước này
    * Thực hiện: Tải bản cài đặt phù hợp tại link sau và cài đặt vào máy. http://arduino.cc/en/Main/Software
    * Chú ý: Nếu bạn đang sử dụng hệ điều hành Linux, cần chạy Arduino IDE với quyền root. Điều này giúp Arduino IDE có thể mở cổng nối tiếp (UART) để nạp firmware cho mạch VBLUno.
          * Mở Terminal (Ctrl + Alt + T)
          * Chuyển đến thư mục đã cài đặt Arduino bằng cách sử dụng lệnh “cd”. 
                       Ví dụ cd /home/mrABC/arduino-1.6.10
          * Mở Arduino IDE với lệnh sudo: sudo ./aduino


3. Cài đặt gói dữ liệu của mạch VBLUno cho Arduino IDE

* Cách 1: Cài đặt online

     * Chạy Arduino IDE, vào menu File, chọn "Preferences", thêm dòng sau vào ô  "Additional Boards Manager URLs: "https://raw.githubusercontent.com/VNGIoTLab/Arduino_VBLUno_nRF51822/master/package_vngiotlab_vbluno_101_index.json
     
     * Cài đặt dữ liệu "VNGIoTLab VBLUno nRF51822 Boards" thông qua Trình quản lý boards (Boards Manager) 
     	* Từ menu: Tools -> Board -> Boards Manager ...
     	* Chọn VNGIoTLab VBLUno nRF51822 Boards và nhấn Install

* Cách 2: Cài đặt offline

     * Bạn cần chắc chắn Arduino IDE không được mở trong quá trình cài đặt offline.
     
     * Tải bản cài đặt phù hợp với hệ điều hành: 
          * Cho Windows: https://drive.google.com/file/d/0B8JRZY_9qiUgWERKdG1yYXJNQ28/view
          * Cho Linux 32bit: 
          * Cho Linux 64bit: 
	  
     * Giải nén và chạy file cài đặt (Setup_VBLUno_xxxxx.exe)
     	* Bạn chờ đến khi chương trình thông báo “The installation was successful” là quá trình cài đặt đã hoàn thành.

##Bootloaders
	
* Bootloader giúp Arduino IDE nạp firmware cho VBLUno thông qua cổng USB gắn trên mạch (USB to UART). Mạch VBLUno khi bán ra đã được nạp sẵn bootloader. Thông thường, bạn có thể bỏ qua bước này.

* Trong thư mục "VNGIoTLab_VBLUno_nRF51822_board_v101\bootloader" có chứa file bootloader.hex và mã nguồn tương ứng. Đây là bootloader cho phép Arduino IDE nạp (upload) firmware xuống VBLUno thông qua cổng nối tiếp.

* Để nạp bootloader, kết nối mạch với PC sử dụng mô đun CMSIS-DAP qua giao tiếp SWD (J5), nó sẽ tạo ra một ổ đĩa ảo (MBED), kéo thả bootloader.hex vào ổ đĩa ảo này.

##Bắt đầu sử dụng

1. Kết nối mạch VBLUno với PC thông qua cổng USB trên mạch. 
     * Chuyển cầu nối trên jump J7 về vị trí cho phép nạp firmware qua cổng USB bằng bootloader (vị trí 1-2, phía Jack nguồn màu đen).
     
     * Sau đó ấn nút Reset. Lúc này quan sát thấy sáng cả 2 led trên mạch.

2. Mở Arduino IDE trên PC

3. Chọn board và cổng nối tiếp
     * Chọn VNGIoTLab nRF51822 board từ menu của Arduino IDE:
                    Menu > Tools > Board > VBLUno nRF51822 (V1.0 32KB)

     * Chọn cổng nối tiếp tương ứng của VBLUno:
                    Menu > Tools > Port > [tên cổng nối tiếp của VBLUno]

4. Ví dụ nháy led (Blink)
     * Để kiểm tra mạch, chúng tôi đề nghị bạn sử dụng ví dụ điều khiển nháy led sau.
                   Menu > File > Examples > 01.Basics > Blink

     * Sử dụng chức năng upload (Menu -> Sketch -> Upload) để biên dịch chương trình và nạp firmware xuống mạch VBLUno.
     
     * Nếu biên dịch và nạp thành công, bạn sẽ nhận được thông báo “Device programmed”

5. Ngoài các ví dụ cơ bản của Arduino, VBLUno hỗ trợ sẵn nhiều ví dụ sử dụng giao tiếp Bluetooth Low Energy (BLE)
. Bạn có thể thử các ví dụ bằng cách vào Menu > File > BLE_Examples

	* BLE_HRM: This is an Heart Rate Monitor demo, it simulates Heart Rate detection. You can use Nordic nRFToolBox App to play.

	* BLE_Beacon: This is to implement Apple's iBeacon, you can try it with our BeaconTool available in the AppStore for iOS and PlayStore for Android.

	* SimpleControls: This sample shows how to define your own protocol and to control the I/O of the board from a Central (e.g. iPhone) using the BLE Controller App.

	* SimpleChat: This sample allows you to send text message from the board to your central device such as iPhone or Android using the BLE Controller App.

	* BLEController: This example allows you to use the BLE Controller App (available for iOS and Android) to control the pin state such as High, Low, PWM, Analog, etc.

	* BLESerial: This example allows you to exchange data with your central device (e.g. iPhone 5) and the data will be redirected to the UART.
…



##Các link hữu ích

	* http://iotviet.com.vn/store/detail?id=2
	* https://www.facebook.com/bleviet/?fref=ts
	* https://www.facebook.com/iotviet.vn/?fref=ts

##Các video demo cho VBLUno kit

1.	Ví dụ BLE_Serial  với Arduino IDE trên Ubuntu  https://www.youtube.com/watch?v=U4xNDTFVvXg

##Giấy phép

Bản quyền (c) 2016 VNGIoTLab

Các tài liệu này được công bố dạng mã nguồn mở nhằm mục đích hỗ trợ cộng đồng phát triển. Ngoài ra cũng mong nhận được sự phản hồi, đóng góp từ cộng đồng.


#English Language

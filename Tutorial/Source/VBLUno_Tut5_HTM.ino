/*
 * VNGIoTLab VBLUno KIT
 * 
 * SU DUNG CAM BIEN NHIET DO BEN TRONG CHIP nRF51822 DE TAO THIET BI HEATH THERMOMETER (HTM)
 */


#include "nrf_temp.h"
#include <BLE_API.h>

#define DEVICE_NAME       "VBLUno_HTM"
BLE                       ble;

/* Health Thermometer Service */ 
uint8_t             thermTempPayload[5] = { 0, 0, 0, 0, 0 };
GattCharacteristic  thermTemp (GattCharacteristic::UUID_TEMPERATURE_MEASUREMENT_CHAR,thermTempPayload,
                               5, 5, GattCharacteristic::BLE_GATT_CHAR_PROPERTIES_INDICATE);      //Indicate
GattCharacteristic   *thermChar[] = {&thermTemp};
GattService         thermService (GattService::UUID_HEALTH_THERMOMETER_SERVICE, thermChar, sizeof(thermChar)/sizeof(GattCharacteristic *));

/* Battery Level Service */
uint8_t            batt = 100;     /* Battery level */
uint8_t            read_batt = 0; /* Variable to hold battery level reads */
GattCharacteristic battLevel   ( GattCharacteristic::UUID_BATTERY_LEVEL_CHAR, (uint8_t *)&batt, 1, 1,
                                 GattCharacteristic::BLE_GATT_CHAR_PROPERTIES_NOTIFY |          //Notify or Read
                                 GattCharacteristic::BLE_GATT_CHAR_PROPERTIES_READ);
GattCharacteristic   *battChar[] = {&battLevel};                                 
GattService        battService ( GattService::UUID_BATTERY_SERVICE, battChar, sizeof(battChar)/sizeof(GattCharacteristic *));

/* Advertising data and parameters */
GapAdvertisingData   advData;
GapAdvertisingData   scanResponse;
GapAdvertisingParams advParams ( GapAdvertisingParams::ADV_CONNECTABLE_UNDIRECTED ); 
uint16_t             uuid16_list[] = {GattService::UUID_HEALTH_THERMOMETER_SERVICE,
                                      GattService::UUID_BATTERY_SERVICE};
                                      
static volatile bool triggerSensorPolling = false; /* set to high periodically to indicate to the main thread that
                                                    * polling is necessary. */
Ticker tick1s;             
unsigned char led_val=LOW;

void disconnectionCallBack(const Gap::DisconnectionCallbackParams_t *params) {
  Serial.println("Disconnected!");
  Serial.println("Restarting the advertising process");
  ble.startAdvertising();
}

void periodicCallback() {
  if (ble.getGapState().connected) {
    //blink led
    led_val=!led_val;
    digitalWrite(LED, led_val);

    //Thermometer value    
    uint32_t temp_ieee11073 = quick_ieee11073_from_float(read_temp_value());
    memcpy(thermTempPayload+1, &temp_ieee11073, 4);
    ble.updateCharacteristicValue(thermTemp.getValueAttribute().getHandle(), thermTempPayload, sizeof(thermTempPayload));

    //Batt level value
    /* Decrement the battery level. */
    batt <=50 ? batt=100 : batt--;
    ble.updateCharacteristicValue(battLevel.getValueAttribute().getHandle(), (uint8_t*)&batt, sizeof(batt));
  }
}
                   
/*
 * brief    Hàm đọc giá trị nhiệt độ từ cảm biến nhiệt độ nội bộ của nRF51822
 * return   Giá trị nhiệt độ (float)
 */
float read_temp_value(){

  float temp=0;

  /* Bắt đầu quá trình đo nhiệt độ. */
  NRF_TEMP->TASKS_START = 1; 

  /* Chờ đến khi quá trình đo nhiệt độ hoàn thành. */
  while (NRF_TEMP->EVENTS_DATARDY == 0){
    // Do nothing.}
  }
  NRF_TEMP->EVENTS_DATARDY = 0;

  /* Đọc giá trị nhiệt độ từ cảm biến
   * Độ chính xác là 0.25 độ C <=> 1 đơn vị = 0.25 độ C
   * Cần chia cho 4 để nhận được giá trị độ C
   */
  temp = ((float)nrf_temp_read() / 4.);

  /* Hoàn thành quá trình đo. */
  NRF_TEMP->TASKS_STOP = 1; 

  return temp;
}

/**
 * @brief A very quick conversion between a float temperature and 11073-20601 FLOAT-Type.
 * @param temperature The temperature as a float.
 * @return The temperature in 11073-20601 FLOAT-Type format.
 */
uint32_t quick_ieee11073_from_float(float temperature)
{
    uint8_t  exponent = 0xFE; //exponent is -2
    uint32_t mantissa = (uint32_t)(temperature*100);
    return ( ((uint32_t)exponent) << 24) | mantissa;
}
void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  Serial.println("VBLUno - HTM Demo");

  //for Temperature
  nrf_temp_init();

  //ticker 1 s
  tick1s.attach(periodicCallback, 1);

  // Init ble
  ble.init();
  ble.onDisconnection(disconnectionCallBack);

  // setup adv_data and srp_data
  ble.accumulateAdvertisingPayload(GapAdvertisingData::BREDR_NOT_SUPPORTED | GapAdvertisingData::LE_GENERAL_DISCOVERABLE);
  ble.accumulateAdvertisingPayload(GapAdvertisingData::COMPLETE_LIST_16BIT_SERVICE_IDS, (uint8_t*)uuid16_list, sizeof(uuid16_list));
  ble.accumulateAdvertisingPayload(GapAdvertisingData::GENERIC_THERMOMETER);
  ble.accumulateAdvertisingPayload(GapAdvertisingData::COMPLETE_LOCAL_NAME, (uint8_t *)DEVICE_NAME, sizeof(DEVICE_NAME));
  // set adv_type
  ble.setAdvertisingType(GapAdvertisingParams::ADV_CONNECTABLE_UNDIRECTED);
    // add service
  ble.addService(thermService);
  ble.addService(battService);
  // set device name
  ble.setDeviceName((const uint8_t *)DEVICE_NAME);
  // set tx power,valid values are -40, -20, -16, -12, -8, -4, 0, 4
  ble.setTxPower(4);
  // set adv_interval, 100ms in multiples of 0.625ms.
  ble.setAdvertisingInterval(160);
  // set adv_timeout, in seconds
  ble.setAdvertisingTimeout(0);
  // start advertising
  ble.startAdvertising();
}

void loop() {
  // put your main code here, to run repeatedly:
  ble.waitForEvent();
}

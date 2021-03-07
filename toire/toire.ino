#include <M5StickC.h>
#include "FastLED.h"
#include <Wire.h>

// flash light
FASTLED_USING_NAMESPACE

// FastLED "100-lines-of-code" demo reel, showing just a few 
// of the kinds of animation patterns you can quickly and easily 
// compose using FastLED.  
//
// This example also shows one easy way to define multiple 
// animations patterns and have them automatically rotate.
//
// -Mark Kriegsman, December 2014

#if defined(FASTLED_VERSION) && (FASTLED_VERSION < 3001000)
#warning "Requires FastLED 3.1 or later; check github for latest code."
#endif

#define DATA_PIN    26
//#define CLK_PIN   4
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
#define NUM_LEDS    126
CRGB leds[NUM_LEDS];

#define BRIGHTNESS          30
#define FRAMES_PER_SECOND  120

// -- The core to run FastLED.show()
#define FASTLED_SHOW_CORE 0

// tof
#define VL53L0X_REG_IDENTIFICATION_MODEL_ID         0xc0
#define VL53L0X_REG_IDENTIFICATION_REVISION_ID      0xc2
#define VL53L0X_REG_PRE_RANGE_CONFIG_VCSEL_PERIOD   0x50
#define VL53L0X_REG_FINAL_RANGE_CONFIG_VCSEL_PERIOD 0x70
#define VL53L0X_REG_SYSRANGE_START                  0x00
#define VL53L0X_REG_RESULT_INTERRUPT_STATUS         0x13
#define VL53L0X_REG_RESULT_RANGE_STATUS             0x14
#define address 0x29

byte gbuf[16];

void setup() {
  M5.begin();
  delay(3000); // 3 second delay for recovery
  Serial.begin(115200);
  M5.Lcd.setRotation(3);
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextSize(2);
  M5.Lcd.setCursor(10, 0);
  M5.Lcd.setTextColor(TFT_LIGHTGREY);

  M5.Lcd.print("NeoFlash HAT\r\n");
  M5.Lcd.setCursor(60, 30);
  M5.Lcd.setTextColor(TFT_NAVY);
  M5.Lcd.print("RGB");

  M5.Lcd.setCursor(30, 50);
  M5.Lcd.print("EFFICTION");

  // FlashLED
  // tell FastLED about the LED strip configuration
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  //FastLED.addLeds<LED_TYPE,DATA_PIN,CLK_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);

  // set master brightness control
  FastLED.setBrightness(BRIGHTNESS);
  // TOF
  Wire.begin();        // join i2c bus (address optional for master)
}

void DispArrayReset()
{
  CRGB color = CRGB::Black;
  int rowMax = 7;
  int columeMax = 18;
  int indexColume = 0;

  for(int i = 0;i < rowMax * columeMax;i++){
    leds[i] = color;
  }
}

void DispIppo(){
  CRGB color = CRGB::Red;
  int rowMax = 7;
  int columeMax = 18;
  int indexColume = 0;

  DispArrayReset();
  
  // 2行目
  indexColume = 1;
  leds[4 + indexColume * columeMax] = color;
  leds[17 + indexColume * columeMax] = color;
  
  // 3行目
  indexColume = 2;
  leds[2 + indexColume * columeMax] = color;
  leds[3 + indexColume * columeMax] = color;
  leds[15 + indexColume * columeMax] = color;

  // 4行目
  indexColume = 3;
  leds[0 + indexColume * columeMax] = color;
  leds[1 + indexColume * columeMax] = color;
  leds[2 + indexColume * columeMax] = color;
  leds[6 + indexColume * columeMax] = color;
  leds[8 + indexColume * columeMax] = color;
  leds[13 + indexColume * columeMax] = color;
  leds[14 + indexColume * columeMax] = color;
  leds[15 + indexColume * columeMax] = color;
  leds[16 + indexColume * columeMax] = color;
  leds[17 + indexColume * columeMax] = color;

  // 5行目
  indexColume = 4;
  leds[2 + indexColume * columeMax] = color;
  leds[6 + indexColume * columeMax] = color;
  leds[10 + indexColume * columeMax] = color;
  leds[15 + indexColume * columeMax] = color;
  
  // 6行目
  indexColume = 5;
  leds[2 + indexColume * columeMax] = color;
  leds[9 + indexColume * columeMax] = color;
  leds[13 + indexColume * columeMax] = color;
  leds[15 + indexColume * columeMax] = color;
  leds[17 + indexColume * columeMax] = color;

  // 7行目
  indexColume = 6;
  leds[2 + indexColume * columeMax] = color;
  leds[7 + indexColume * columeMax] = color;
  leds[8 + indexColume * columeMax] = color;
  leds[13 + indexColume * columeMax] = color;
  leds[15 + indexColume * columeMax] = color;
  leds[17 + indexColume * columeMax] = color;
  FastLED.show();
}

void DispMaehe(){
  CRGB color = CRGB::Red;
  int rowMax = 7;
  int columeMax = 18;
  int indexColume = 0;

  DispArrayReset();
  
  // 3行目
  indexColume = 2;
  leds[0 + indexColume * columeMax] = color;
  leds[1 + indexColume * columeMax] = color;
  leds[2 + indexColume * columeMax] = color;
  leds[3 + indexColume * columeMax] = color;
  leds[4 + indexColume * columeMax] = color;
  leds[7 + indexColume * columeMax] = color;
  leds[8 + indexColume * columeMax] = color;
  leds[9 + indexColume * columeMax] = color;
  leds[14 + indexColume * columeMax] = color;
  leds[15 + indexColume * columeMax] = color;

  // 4行目
  indexColume = 3;
  leds[4 + indexColume * columeMax] = color;
  leds[8 + indexColume * columeMax] = color;
  leds[13 + indexColume * columeMax] = color;
  leds[14 + indexColume * columeMax] = color;
  leds[15 + indexColume * columeMax] = color;
  leds[16 + indexColume * columeMax] = color;

  // 5行目
  indexColume = 4;
  leds[1 + indexColume * columeMax] = color;
  leds[3 + indexColume * columeMax] = color;
  leds[8 + indexColume * columeMax] = color;
  leds[13 + indexColume * columeMax] = color;
  leds[16 + indexColume * columeMax] = color;
  
  // 6行目
  indexColume = 5;
  leds[2 + indexColume * columeMax] = color;
  leds[8 + indexColume * columeMax] = color;
  leds[16 + indexColume * columeMax] = color;
  leds[17 + indexColume * columeMax] = color;

  // 7行目
  indexColume = 6;
  leds[3 + indexColume * columeMax] = color;
  leds[6 + indexColume * columeMax] = color;
  leds[7 + indexColume * columeMax] = color;
  leds[8 + indexColume * columeMax] = color;
  leds[9 + indexColume * columeMax] = color;
  leds[10 + indexColume * columeMax] = color;
  leds[17 + indexColume * columeMax] = color;
  FastLED.show();
}





void DispOk(){
  CRGB color = CRGB::Blue;
  int rowMax = 7;
  int columeMax = 18;
  int indexColume = 0;

  DispArrayReset();
  // 2行目
  indexColume = 1;
  leds[4 + indexColume * columeMax] = color;
  leds[5 + indexColume * columeMax] = color;
  leds[9 + indexColume * columeMax] = color;
  leds[12 + indexColume * columeMax] = color;
  leds[15 + indexColume * columeMax] = color;
  
  // 3行目
  indexColume = 2;
  leds[3 + indexColume * columeMax] = color;
  leds[6 + indexColume * columeMax] = color;
  leds[9 + indexColume * columeMax] = color;
  leds[11 + indexColume * columeMax] = color;
  leds[15 + indexColume * columeMax] = color;

  // 4行目
  indexColume = 3;
  leds[3 + indexColume * columeMax] = color;
  leds[6 + indexColume * columeMax] = color;
  leds[9 + indexColume * columeMax] = color;
  leds[10 + indexColume * columeMax] = color;
  leds[15 + indexColume * columeMax] = color;

  // 5行目
  indexColume = 4;
  leds[3 + indexColume * columeMax] = color;
  leds[6 + indexColume * columeMax] = color;
  leds[9 + indexColume * columeMax] = color;
  leds[11 + indexColume * columeMax] = color;
  
  // 6行目
  indexColume = 5;
  leds[4 + indexColume * columeMax] = color;
  leds[5 + indexColume * columeMax] = color;
  leds[9 + indexColume * columeMax] = color;
  leds[12 + indexColume * columeMax] = color;
  leds[15 + indexColume * columeMax] = color;

  // 7行目
  FastLED.show();
}

void DispReset()
{
  DispArrayReset();
  FastLED.show();
}

int dist = 0;
bool okChattering = false;
int ippoMaeCounter = 0;

void loop(){
  M5.update();
  
  dist = getDist();

  if((dist <= 20 )||(dist > 1000)){
    DispReset();
    okChattering = false;
  }else if(dist < 125){
    if(okChattering) DispOk();
    else okChattering = true;
  }else{
    okChattering = false;
    ippoMaeCounter++;
    if(((ippoMaeCounter >> 2) % 2) == 0){
      DispIppo();
    }else{
      DispMaehe();
    }
  }

  delay(1000);
}


int getDist() {
  byte val1 = read_byte_data_at(VL53L0X_REG_IDENTIFICATION_REVISION_ID);
  Serial.print("Revision ID: "); Serial.println(val1);

  val1 = read_byte_data_at(VL53L0X_REG_IDENTIFICATION_MODEL_ID);
  Serial.print("Device ID: "); Serial.println(val1);

  val1 = read_byte_data_at(VL53L0X_REG_PRE_RANGE_CONFIG_VCSEL_PERIOD);
  Serial.print("PRE_RANGE_CONFIG_VCSEL_PERIOD="); Serial.println(val1); 
  Serial.print(" decode: "); Serial.println(VL53L0X_decode_vcsel_period(val1));

  val1 = read_byte_data_at(VL53L0X_REG_FINAL_RANGE_CONFIG_VCSEL_PERIOD);
  Serial.print("FINAL_RANGE_CONFIG_VCSEL_PERIOD="); Serial.println(val1);
  Serial.print(" decode: "); Serial.println(VL53L0X_decode_vcsel_period(val1));

  write_byte_data_at(VL53L0X_REG_SYSRANGE_START, 0x01);

  byte val = 0;
  int cnt = 0;
  while (cnt < 100) { // 1 second waiting time max
    delay(10);
    val = read_byte_data_at(VL53L0X_REG_RESULT_RANGE_STATUS);
    if (val & 0x01) break;
    cnt++;
  }
  if (val & 0x01) Serial.println("ready"); else Serial.println("not ready");

  read_block_data_at(0x14, 12);
  uint16_t acnt = makeuint16(gbuf[7], gbuf[6]);
  uint16_t scnt = makeuint16(gbuf[9], gbuf[8]);
  uint16_t dist = makeuint16(gbuf[11], gbuf[10]);
  byte DeviceRangeStatusInternal = ((gbuf[0] & 0x78) >> 3);

  Serial.print("ambient count: "); Serial.println(acnt);
  Serial.print("signal count: ");  Serial.println(scnt);
  Serial.print("distance ");       Serial.println(dist);
  Serial.print("status: ");        Serial.println(DeviceRangeStatusInternal);
  
  M5.Lcd.setCursor(0, 70);
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.print( dist);

  return dist;
}

uint16_t bswap(byte b[]) {
  // Big Endian unsigned short to little endian unsigned short
  uint16_t val = ((b[0] << 8) & b[1]);
  return val;
}

uint16_t makeuint16(int lsb, int msb) {
    return ((msb & 0xFF) << 8) | (lsb & 0xFF);
}

void write_byte_data(byte data) {
  Wire.beginTransmission(address);
  Wire.write(data);
  Wire.endTransmission();
}

void write_byte_data_at(byte reg, byte data) {
  // write data word at address and register
  Wire.beginTransmission(address);
  Wire.write(reg);
  Wire.write(data);
  Wire.endTransmission();
}

void write_word_data_at(byte reg, uint16_t data) {
  // write data word at address and register
  byte b0 = (data &0xFF);
  byte b1 = ((data >> 8) && 0xFF);
    
  Wire.beginTransmission(address);
  Wire.write(reg);
  Wire.write(b0);
  Wire.write(b1);
  Wire.endTransmission();
}

byte read_byte_data() {
  Wire.requestFrom(address, 1);
  while (Wire.available() < 1) delay(1);
  byte b = Wire.read();
  return b;
}

byte read_byte_data_at(byte reg) {
  //write_byte_data((byte)0x00);
  write_byte_data(reg);
  Wire.requestFrom(address, 1);
  while (Wire.available() < 1) delay(1);
  byte b = Wire.read();
  return b;
}

uint16_t read_word_data_at(byte reg) {
  write_byte_data(reg);
  Wire.requestFrom(address, 2);
  while (Wire.available() < 2) delay(1);
  gbuf[0] = Wire.read();
  gbuf[1] = Wire.read();
  return bswap(gbuf); 
}

void read_block_data_at(byte reg, int sz) {
  int i = 0;
  write_byte_data(reg);
  Wire.requestFrom(address, sz);
  for (i=0; i<sz; i++) {
    while (Wire.available() < 1) delay(1);
    gbuf[i] = Wire.read();
  }
}

uint16_t VL53L0X_decode_vcsel_period(short vcsel_period_reg) {
  // Converts the encoded VCSEL period register value into the real
  // period in PLL clocks
  uint16_t vcsel_period_pclks = (vcsel_period_reg + 1) << 1;
  return vcsel_period_pclks;
}

#include <esp_now.h>
#include <WiFi.h>
#include <esp_wifi.h>
#include <string.h>

#include <Adafruit_ADXL343.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>


#include "WindowQuinn.h"
#include "ClassifierQuinn.h"

Window window;
Eloquent::ML::Port::Classifier clf;

#define ADXL343_SCK 6
#define ADXL343_MISO 4
#define ADXL343_MOSI 5
#define ADXL343_CS 10


int total_active = 0;
int total_inactive = 0;

String prev = "Not Brushing";

String currGesture;


Adafruit_ADXL343 accel = Adafruit_ADXL343(ADXL343_SCK, ADXL343_MISO, ADXL343_MOSI, ADXL343_CS, 12345);


// REPLACE WITH THE MAC Address of your receiver 
uint8_t broadcastAddress[] = {0x84, 0xF7, 0x03, 0x1E, 0x05, 0x84};


// Variable to store if sending data was successful
String success;

//Structure example to send data
//Must match the receiver structure
typedef struct struct_message {
    bool validBrushing;
} struct_message;

// Create a struct_message called MPU6050Readings to hold sensor readings
struct_message CurrentState;

esp_now_peer_info_t peerInfo;

// Callback when data is sent
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("\r\nLast Packet Send Status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}


void displayDataRate(void)
{
  Serial.print  ("Data Rate:    ");

  switch(accel.getDataRate())
  {
    case ADXL343_DATARATE_3200_HZ:
      Serial.print  ("3200 ");
      break;
    case ADXL343_DATARATE_1600_HZ:
      Serial.print  ("1600 ");
      break;
    case ADXL343_DATARATE_800_HZ:
      Serial.print  ("800 ");
      break;
    case ADXL343_DATARATE_400_HZ:
      Serial.print  ("400 ");
      break;
    case ADXL343_DATARATE_200_HZ:
      Serial.print  ("200 ");
      break;
    case ADXL343_DATARATE_100_HZ:
      Serial.print  ("100 ");
      break;
    case ADXL343_DATARATE_50_HZ:
      Serial.print  ("50 ");
      break;
    case ADXL343_DATARATE_25_HZ:
      Serial.print  ("25 ");
      break;
    case ADXL343_DATARATE_12_5_HZ:
      Serial.print  ("12.5 ");
      break;
    case ADXL343_DATARATE_6_25HZ:
      Serial.print  ("6.25 ");
      break;
    case ADXL343_DATARATE_3_13_HZ:
      Serial.print  ("3.13 ");
      break;
    case ADXL343_DATARATE_1_56_HZ:
      Serial.print  ("1.56 ");
      break;
    case ADXL343_DATARATE_0_78_HZ:
      Serial.print  ("0.78 ");
      break;
    case ADXL343_DATARATE_0_39_HZ:
      Serial.print  ("0.39 ");
      break;
    case ADXL343_DATARATE_0_20_HZ:
      Serial.print  ("0.20 ");
      break;
    case ADXL343_DATARATE_0_10_HZ:
      Serial.print  ("0.10 ");
      break;
    default:
      Serial.print  ("???? ");
      break;
  }
  Serial.println(" Hz");
}

void displayRange(void)
{
  Serial.print  ("Range:         +/- ");

  switch(accel.getRange())
  {
    case ADXL343_RANGE_16_G:
      Serial.print  ("16 ");
      break;
    case ADXL343_RANGE_8_G:
      Serial.print  ("8 ");
      break;
    case ADXL343_RANGE_4_G:
      Serial.print  ("4 ");
      break;
    case ADXL343_RANGE_2_G:
      Serial.print  ("2 ");
      break;
    default:
      Serial.print  ("?? ");
      break;
  }
  Serial.println(" g");
}


 
void setup() {
  Serial.begin(115200);
  while (!Serial);
  Serial.println("Accelerometer Test"); Serial.println("");

  /* Initialise the sensor */
  if(!accel.begin())
  {
    /* There was a problem detecting the ADXL343 ... check your connections */
    Serial.println("Ooops, no ADXL343 detected ... Check your wiring!");
    while(1);
  }

  /* Set the range to whatever is appropriate for your project */
  accel.setRange(ADXL343_RANGE_16_G);
  // accel.setRange(ADXL343_RANGE_8_G);
  // accel.setRange(ADXL343_RANGE_4_G);
  // accel.setRange(ADXL343_RANGE_2_G);

  /* Display some basic information on this sensor */
  accel.printSensorDetails();
  displayDataRate();
  displayRange();
  Serial.println("");


 
  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  // Once ESPNow is successfully Init, we will register for Send CB to
  // get the status of Transmitted packet
  esp_now_register_send_cb(OnDataSent);
  
  // Register peer
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;
  
  // Add peer        
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    Serial.println("Failed to add peer");
    return;
  }

}
 
void loop() {
  
  sensors_event_t event;
  accel.getEvent(&event);

  
  // Get Accelerometer Data to fill the classifier window
  // event.acceleration.x;
  // event.acceleration.y;
  // event.acceleration.z;

float sample[] = {event.acceleration.x, event.acceleration.y, event.acceleration.z};
  
  if (!window.transform(sample))
      return;

  // predict gesture
  Serial.print("Gesture: ");
  Serial.println(clf.predictLabel(window.features));

  

  currGesture = clf.predictLabel(window.features);

  if (currGesture == "Active Brushing") {
      if(prev == "Active Brushing"){
          total_inactive = 0;
          total_active++;
      }
      if(prev == "Not Brushing"){
          total_inactive = 0;
          total_active++;
          prev = "Active Brushing";
          return;
      }
  }

  if (currGesture == "Not Brushing"){
      if(prev == "Not Brushing"){
          total_active = 0;
          total_inactive++;
      }
      if(prev == "Active Brushing"){
          total_active = 0;
          total_inactive++;
          prev = "Not Brushing";
          return;
      }
        
  }

  Serial.println(total_inactive);
  Serial.println(total_active);
 


  if(total_inactive >= 5){
    CurrentState.validBrushing = false;
    esp_now_send(broadcastAddress, (uint8_t *) &CurrentState, sizeof(CurrentState));
  }

  if(total_active >= 10){
    CurrentState.validBrushing = true;
    esp_now_send(broadcastAddress, (uint8_t *) &CurrentState, sizeof(CurrentState));
  }

   delay(200);
  
}

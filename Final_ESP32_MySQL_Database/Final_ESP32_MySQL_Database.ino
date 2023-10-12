#include <WiFi.h>
#include <HTTPClient.h>
#include <Arduino_JSON.h>
#include "DHT.h"

// DHT sensor settings (DHT).
#define DHTPIN 15 //--> Defines the Digital Pin connected to the DHT11 sensor.
#define DHTTYPE DHT22 //--> Defines the type of DHT sensor used. Here used is the DHT11 sensor.
DHT dht_sensor(DHTPIN, DHTTYPE); //--> Initialize DHT sensor.

// Defines the Digital Pin of the "On Board LED".
#define ON_Board_LED 2 

// Defines GPIO 13 as LED_1.
#define LED_01 13 

// Defines GPIO 12 as LED_2.
#define LED_02 12 

// SSID and Password of your WiFi router.
const char* ssid = "A12";
const char* password = "42117622";

// Variables for HTTP POST request data.
String postData = ""; //--> Variables sent for HTTP POST request data.
String payload = "";  //--> Variable for receiving response from HTTP POST.

// Variables for DHT11 sensor data.
float send_Temp;
int send_Humd;
String send_Status_Read_DHT = "";

void setup() {
  Serial.begin(115200); //--> Initialize serial communications with the PC.
  pinMode(ON_Board_LED,OUTPUT); //--> On Board LED port Direction output.
  pinMode(LED_01,OUTPUT); //--> LED_01 port Direction output.
  pinMode(LED_02,OUTPUT); //--> LED_02 port Direction output.
  
  digitalWrite(ON_Board_LED, HIGH); //--> Turn on Led On Board.
  digitalWrite(LED_01, HIGH); //--> Turn on LED_01.
  digitalWrite(LED_02, HIGH); //--> Turn on LED_02.
  
  delay(2000);
  
  digitalWrite(ON_Board_LED, LOW); //--> Turn off Led On Board.
  digitalWrite(LED_01, LOW); //--> Turn off Led LED_01.
  digitalWrite(LED_02, LOW); //--> Turn off Led LED_02.
  
  // Make WiFi on ESP32 in "STA/Station" mode and start connecting to WiFi Router/Hotspot.
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  
  Serial.println();
  Serial.println("-------------");
  Serial.print("Connecting");

  // The process of connecting the WiFi on the ESP32 to the WiFi Router/Hotspot.
  // The process timeout of connecting ESP32 with WiFi Hotspot / WiFi Router is 20 seconds.
  // If within 20 seconds the ESP32 has not been successfully connected to WiFi, the ESP32 will restart.
  // I made this condition because on my ESP32, there are times when it seems like it can't connect to WiFi, so it needs to be restarted to be able to connect to WiFi.

  int connecting_process_timed_out = 100; //--> 20 = 20 seconds.
  connecting_process_timed_out = connecting_process_timed_out * 2;
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    // Make the On Board Flashing LED on the process of connecting to the wifi router.
    digitalWrite(ON_Board_LED, HIGH);
    delay(250);
    digitalWrite(ON_Board_LED, LOW);
    delay(250);

    // Countdown "connecting_process_timed_out".
    if(connecting_process_timed_out > 0) connecting_process_timed_out--;
    if(connecting_process_timed_out == 0) {
      delay(1000);
      ESP.restart();
    }
  }
  
  digitalWrite(ON_Board_LED, LOW); //--> Turn off the On Board LED when it is connected to the wifi router.
  
  //If successfully connected to the wifi router, the IP Address that will be visited is displayed in the serial monitor
  Serial.println();
  Serial.print("Successfully connected to : ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println("-------------");

  // Setting up the DHT sensor (DHT11).
  dht_sensor.begin();

  delay(2000);
}

void loop() {
  if(WiFi.status()== WL_CONNECTED) {    // Check WiFi connection status.
    HTTPClient http;                    //--> Declare object of class HTTPClient.
    int httpCode;                       //--> Variables for HTTP return code.
    
    // Process to get LEDs data from database to control LEDs.
    postData = "id=esp32_01";
    payload = "";
  
    digitalWrite(ON_Board_LED, HIGH);
    Serial.println();
    Serial.println("---------------getdata.php");
    // In this project I use local server or localhost with XAMPP application.
    // So make sure all PHP files are "placed" or "saved" or "run" in the "htdocs" folder.
    // I suggest that you create a new folder for this project in the "htdocs" folder.
    // The "htdocs" folder is in the "xampp" installation folder.
    // The order of the folders I recommend:
    // xampp\htdocs\your_project_folder_name\phpfile.php
    //
    // ESP32 accesses the data bases at this line of code: 
    // http.begin("http://REPLACE_WITH_YOUR_COMPUTER_IP_ADDRESS/REPLACE_WITH_PROJECT_FOLDER_NAME_IN_htdocs_FOLDER/getdata.php");
    // REPLACE_WITH_YOUR_COMPUTER_IP_ADDRESS = there are many ways to see the IP address, you can google it. 
    //                                         But make sure that the IP address used is "IPv4 address".
    // Example : http.begin("http://192.168.0.0/ESP32_MySQL_Database/Final/getdata.php");
    http.begin("http://192.168.13.191/ESP32MySQL/final/getdata.php");  //--> Specify request destination
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");        //--> Specify content-type header
   
    httpCode = http.POST(postData); //--> Send the request
    payload = http.getString();     //--> Get the response payload
  
    Serial.print("httpCode : ");
    Serial.println(httpCode); //--> Print HTTP return code
    Serial.print("payload  : ");
    Serial.println(payload);  //--> Print request response payload
    
    http.end();  //--> Close connection
    Serial.println("---------------");
    digitalWrite(ON_Board_LED, LOW);

    // Calls the control_LEDs() subroutine.
    control_LEDs();
    
    delay(1000);

    // Calls the get_DHT_sensor_data() subroutine.
    get_DHT_sensor_data();
  
    // The process of sending the DHT11 sensor data and the state of the LEDs to the database.
    String LED_01_State = "";
    String LED_02_State = "";

    if (digitalRead(LED_01) == 1) LED_01_State = "ON";
    if (digitalRead(LED_01) == 0) LED_01_State = "OFF";
    if (digitalRead(LED_02) == 1) LED_02_State = "ON";
    if (digitalRead(LED_02) == 0) LED_02_State = "OFF";
    
    postData = "id=esp32_01";
    postData += "&temperature=" + String(send_Temp);
    postData += "&humidity=" + String(send_Humd);
    postData += "&status_read_sensor_dht=" + send_Status_Read_DHT;
    postData += "&led_01=" + LED_01_State;
    postData += "&led_02=" + LED_02_State;
    payload = "";
  
    digitalWrite(ON_Board_LED, HIGH);
    Serial.println();
    Serial.println("---->updateDHT.php");
    // Example : http.begin("http://192.168.0.0/ESP32_MySQL_Database/Final/updateDHT11data_and_recordtable.php");
    http.begin("http://192.168.13.191/ESP32MySQL/final/updateDHT.php");  //--> Specify request destination
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");  //--> Specify content-type header
   
    httpCode = http.POST(postData); //--> Send the request
    payload = http.getString();     //--> Get the response payload
  
    Serial.print("httpCode : ");
    Serial.println(httpCode);       //--> Print HTTP return code
    Serial.print("payload  : ");
    Serial.println(payload);        //--> Print request response payload
    
    http.end();  //Close connection
    Serial.println("---------------");
    digitalWrite(ON_Board_LED, LOW);
    
    delay(4000);
  }
}

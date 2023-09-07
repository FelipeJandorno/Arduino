/*
 * Rui Santos 
 * Complete Project Details https://randomnerdtutorials.com
 */
 
#include <TinyGPS++.h>
#include <SoftwareSerial.h>

// ---------------------------- GPS struct ---------------------------- // 

struct gps{
  float gps_lat;
  float gps_lng;
  float gps_alt;
};

struct gps gps_data;

// ---------------------------- GPS code ---------------------------- // 

static const int RXPin = 9, TXPin = 8;
static const uint32_t GPSBaud = 9600;

TinyGPSPlus gps; // The TinyGPS++ object
SoftwareSerial ss(RXPin, TXPin); // The serial connection to the GPS device

void get_GPS_data(struct gps *p_gps_data){
  while (ss.available() > 0){
    gps.encode(ss.read());
    if (gps.location.isUpdated()){
      p_gps_data->gps_lat = gps.location.lat();
      p_gps_data->gps_lng = gps.location.lng();
      p_gps_data->gps_alt = gps.altitude.meters();
    }
  }
}

void print_data(struct gps *p_gps_data){
  Serial.print("Lat: ");
  Serial.println(p_gps_data->gps_lat);
  Serial.print("Lng: ");
  Serial.println(p_gps_data->gps_lng);
  Serial.print("Alt: ");
  Serial.println(p_gps_data->gps_alt);
}

void setup(){
  Serial.begin(9600);
  ss.begin(GPSBaud);
}

void loop(){
  get_GPS_data(&gps_data);
}

#include <Ethernet.h>
#include <EthernetUdp.h>

// Enter a MAC address and IP address for your controller below.
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
IPAddress ip(192, 168, 1, 177);

unsigned int udpPort = 8888;      // Your UDP port
//char udpServer[]="myUDPserver"; // uncomment for network name instead of ip address
byte  udpServer[4]={192,168,1,61};// uncomment for IP address instead of network name

// buffers for receiving and sending data
char packetBuffer[UDP_TX_PACKET_MAX_SIZE];  // buffer to hold incoming packet,
char ReplyBuffer[512] ;        // a string to send back

// Sample rate in ms
unsigned int samplerate=3000;
unsigned long timer=0; //sampling rate timer
// Start EthernetUDP instance to let us send and receive packets over UDP
EthernetUDP Udp;

void setup() {
  //Starting Ethernet interface
  Ethernet.init(10);  
  Ethernet.begin(mac, ip);

  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    
  }
  // Check for Ethernet hardware present
  if (Ethernet.hardwareStatus() == EthernetNoHardware) {
    while (true) {
      delay(1); // do nothing, no point running without Ethernet hardware
    }
  } 
  // start UDP
  Udp.begin(udpPort);
  //Change the following to change the initialization string to be send to the sensor
  Serial.print ("HZ:1"); //Temperature and Humiditye reporting rates in Hx (0.5,1,2,5,10)

  //start sampling rate timer
  timer=millis();
  
}

void loop() {
  //Read incoming string from the sensor
  if (Serial.available() > 0) {
    String SerialIn = Serial.readString();
    SerialIn.toCharArray(ReplyBuffer, 512);
    Udp.beginPacket(udpServer, udpPort);
    Udp.write(ReplyBuffer);
    Udp.endPacket();
  }
  //Samplingrate timer
  if (millis()-timer >=samplerate){
    Serial.println("READ"); //send the READ command to the sensor
    timer=millis();
  }

}

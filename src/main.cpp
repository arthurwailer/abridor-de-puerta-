#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <MQTT.h>


const int LED = 2;

const char* mqtt_server = "52.43.42.179";
MQTT myMqtt("esp01", mqtt_server, 1883);


const char* ssid     = "TP-LINK_9C9E";
const char* password = "83803796";

void myConnectedCb()
{
   Serial.println("connected to MQTT server");
}

void myDisconnectedCb()
{
  Serial.println("disconnected. try to reconnect...");
  delay(500);
  myMqtt.connect();
}

void myPublishedCb()
{
  Serial.println("published.");
}

void myDataCb(String& topic, String& data)
{

  Serial.print(topic);
  Serial.print(": ");
  Serial.println(data);
  String abrir = "abrir";
  String cerrar = "cerrar";

  if(data.compareTo(abrir) == 0){
    digitalWrite(LED,HIGH);
  }
  else if(data.compareTo(cerrar) == 0){
    digitalWrite(LED,LOW);
  }


  String  pub = "chao";
  myMqtt.publish("/chao", data);
}

void setup() {

  Serial.begin(115200);
  WiFi.begin(ssid, password);

  pinMode(LED, OUTPUT);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  myMqtt.onConnected(myConnectedCb);
  myMqtt.onDisconnected(myDisconnectedCb);
  myMqtt.onPublished(myPublishedCb);
  myMqtt.onData(myDataCb);

  Serial.println("connect mqtt...");
  myMqtt.connect();
  String sub_topic = "/hola";
  myMqtt.subscribe(sub_topic);
}

void loop() {
    // put your main code here, to run repeatedly:
    //Serial.println("hola mundo");
    Serial.println("imprimiendo mensaje mqtt");
    String pubTopic = "/chao";
    String msg = "adios!";
    //myMqtt.publish(pubTopic, msg);

    delay(1000);
}

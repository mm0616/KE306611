//**********************************************************************************
/*
Project 17.1 ESP8266_Code
*/
// generated by KidsBlock
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiClient.h>
//#include <WiFi.h>

#ifndef STASSID
#define STASSID "ChinaNet_2.4G"  //the name of user's Wifi
#define STAPSK  "ChinaNet@233"       //the password of the user's wifi
#endif
const char* ssid = STASSID;
const char* password = STAPSK;

//IPAddress local_IP(192,168,4,22);
//IPAddress gateway(192,168,4,22);
//IPAddress subnet(255,255,255,0);
//
//const char *ssid = "ESP8266_AP_TEST";
//const char *password = "12345678";

WiFiServer server(80);
String unoData = "";
int ip_flag = 0;
int ultra_state = 1;
String ip_str;


void setup() {
  Serial.begin(9600); 
//   WiFi.mode(WIFI_AP); //设置工作在AP模式
//
//  WiFi.softAPConfig(local_IP, gateway, subnet); //设置AP地址
//  while(!WiFi.softAP(ssid, password)){}; //启动AP
//  Serial.println("AP启动成功");
//
//  Serial.print("IP address: ");
//  Serial.println(WiFi.softAPIP()); // 打印IP地址
//
//  WiFi.softAPsetHostname("myHostName"); //设置主机名
//  Serial.print("HostName: ");
//  Serial.println(WiFi.softAPgetHostname()); //打印主机名
//
//  Serial.print("mac Address: ");
//  Serial.println(WiFi.softAPmacAddress()); //打印mac地址

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.print("IP ADDRESS: ");
  Serial.println(WiFi.localIP());
  if (!MDNS.begin("esp8266")) {
    //Serial.println("Error setting up MDNS responder!");
    while (1) {
      delay(1000);
    }
  }
 // Serial.println("mDNS responder started");
  server.begin();
  //Serial.println("TCP server started");
  MDNS.addService("http", "tcp", 80);
  ip_flag = 1;
}

void loop() {
  //Serial.println(WiFi.softAPgetStationNum()); //打印客户端连接数
  if(ip_flag == 1)
  {
    for(int i=3; i>0; i--)
    {
      Serial.print("IP: ");
      Serial.print(WiFi.localIP());
      Serial.println('#');
      delay(500);
    }
    ip_flag = 0;
    
  }
    MDNS.update();
    WiFiClient client = server.available();
    if (!client) {
      return;
    }
    //Serial.println("");
    while (client.connected() && !client.available()) {
      delay(1);
    }
    String req = client.readStringUntil('\r');
    int addr_start = req.indexOf(' ');
    int addr_end = req.indexOf(' ', addr_start + 1);
    if (addr_start == -1 || addr_end == -1) {
      //Serial.print("Invalid request: ");
      //Serial.println(req);
      return;
    }
    req = req.substring(addr_start + 1, addr_end);
    int len_val = String(req).length();
    String M_req = String(req).substring(0,6);
    //Serial.println(M_req);
    if(M_req == "/btn/u")
    {
      String s_M_req = String(req).substring(5,len_val);
      Serial.print(s_M_req);
      Serial.print("#");
    }
    if(M_req == "/btn/v")
    {
      String s_M_req = String(req).substring(5,len_val);
      Serial.print(s_M_req);
      Serial.print("#");
    }
    client.flush();
    String s;
    if (req == "/") {
      IPAddress ip = WiFi.localIP();
      String ipStr = String(ip[0]) + '.' + String(ip[1]) + '.' + String(ip[2]) + '.' + String(ip[3]);
      s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>Hello from ESP8266 at ";
      s += ipStr;
      s += "</html>\r\n\r\n";
      //Serial.println("Sending 200");
      Serial.println(WiFi.localIP());
      Serial.write('*');
      client.println(WiFi.localIP());
      ip_flag = 0;
    }
    else if(req == "/btn/F")
    {
      Serial.write('F');
      client.println(F("F"));
    }
    else if(req == "/btn/B")
    {
      Serial.write('B');
      client.println(F("B"));
    }
    else if(req == "/btn/L")
    {
      Serial.write('L');
      client.println(F("L"));
    }
    else if(req == "/btn/R")
    {
      Serial.write('R');
      client.println(F("R"));
    }
    else if(req == "/btn/S")
    {
      Serial.write('S');
      client.println(F("S"));
    }
    else if(req == "/btn/a")
    {
      Serial.write('a');
      client.println(F("a"));
    }
    else if(req == "/btn/b")
    {
      Serial.write('b');
      client.println(F("b"));
    }
    else if(req == "/btn/c")
    {
      Serial.write('c');
      client.println(F("c"));
    }
    else if(req == "/btn/d")
    {
      Serial.write('d');
      client.println(F("d"));
    }
    else if(req == "/btn/e")
    {
      Serial.write('e');
      client.println(F("e"));
    }
    else if(req == "/btn/f")
    {
      Serial.write('f');
      client.println(F("f"));
    }
    else if(req == "/btn/g")
    {
      Serial.write('g');
      client.println(F("g"));
    }
    else if(req == "/btn/z")
    {
      Serial.write('z');
      client.println(F("z"));
    }
    else if(req == "/btn/i")
    {
      Serial.write('i');
      client.println(F("i"));
    }
    else if(req == "/btn/j")
    {
      Serial.write('j');
      client.println(F("j"));
    }
    else if(req == "/btn/k")
    {
      Serial.write('k');
      client.println(F("k"));
    }
    else if(req == "/btn/y")
    {
      Serial.write('y');
      client.println(F("y"));
    }
    else if(req == "/btn/l")
    {
      Serial.write('l');
      client.println(F("l"));
    }
    else if(req == "/btn/m")
    {
      Serial.write('m');
      client.println(F("m"));
    }
    else if(req == "/btn/n")
    {
      Serial.write('n');
      client.println("n");
    }
    else if(req == "/btn/o")
    {
      Serial.write('o');
      client.println(F("o"));
    }
    else if(req == "/btn/p")
    {
      Serial.write('p');
      client.println(F("p"));
    }
    else if(req == "/btn/q")
    {
      Serial.write('q');
      client.println("q");
    }
    else if(req == "/btn/x")
    {
      Serial.write('x');
      client.println(F("x"));
    }
    else if(req == "/btn/1")
    {
      Serial.write('1');
      client.println(F("1"));
    }
    else if(req == "/btn/2")
    {
      Serial.write('2');
      client.println("2");
    }
    else if(req == "/btn/3")
    {
      Serial.write('3');
      client.println(F("3"));
    }
    else if(req == "/btn/4")
    {
      Serial.write('4');
      client.println("4");
    }
    else if(req == "/btn/5")
    {
      Serial.write('5');
      client.println(F("5"));
    }
    else if(req == "/btn/0")
    {
      Serial.write('0');
      client.println("0");
    }
    else {
      //s = "HTTP/1.1 404 Not Found\r\n\r\n";
      //Serial.println("Sending 404");
    }

    client.print(F("IP : "));
    client.println(WiFi.localIP());
}
//**********************************************************************************

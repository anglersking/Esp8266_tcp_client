
#include <ESP8266WiFi.h>
 
#define SSID "yu" //这里改成你的wifi名字
#define PASSWD  "51570523"//这里改成你的wifi密码
 
const uint16_t port = 8888;
const char * host = "192.168.0.111"; // ip or dns
WiFiClient client;//创建一个tcp client连接
 
// 复位或上电后运行一次:
void setup() {
    //在这里加入初始化相关代码，只运行一次:
    Serial.begin(115200);
     
    WiFi.mode(WIFI_STA);
    WiFi.begin(SSID,PASSWD);
     
    Serial.println("Wait for WiFi... ");
    //等待wifi连接成功
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(500);
    }
     
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
     
    delay(500);
}
 
//一直循环执行:
void loop() {
    // 在这里加入主要程序代码，重复执行:
    Serial.print("connecting to ");
    Serial.println(host);
     
    if (!client.connect(host, port)) {
        Serial.println("connection failed");
        Serial.println("wait 5 sec...");
        delay(5000);
        return;
    }
     
    // 发送数据到Tcp server
    Serial.println("Send this data to server");
    client.println(String("lingzhilab"));
     
    //读取从server返回到响应数据
    String line = client.readStringUntil('\r');
    Serial.println(line);
     
    Serial.println("closing connection");
    client.stop();
     
    Serial.println("wait 5 sec...");
    delay(5000);
}

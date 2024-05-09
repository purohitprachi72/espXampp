#include <WiFi.h>
#include <HTTPClient.h>

String URL = "http://ip/data_acquisition/test_data.php";

const char* ssid = "ssid";
const char* password = "****"";

int temperature = 48;
int humidity = 84;

void setup() {
  Serial.begin(115200);
  connectWiFi();

}

void loop() {
  if(WiFi.status()!=WL_CONNECTED){
    connectWiFi();
  }

  String postData = "temperature" + String(temperature) + "&humidity" + String(humidity);

  HTTPClient http;
  http.begin(URL);

  int httpCode = http.POST(postData);
  String payload = http.getString();
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  Serial.print("URL: "); Serial.println(URL);
  Serial.print("Data: "); Serial.println(postData);
  Serial.print("httpCode: "); Serial.println(httpCode);
  Serial.print("payload: "); Serial.println(payload);
  Serial.println("-------------------------------------------------------");
  http.end();
  delay(5000);
}

void connectWiFi(){
  WiFi.mode(WIFI_OFF);
  delay(1000);
  //hides viewing of esp as wifi hotspot
  WiFi.mode(WIFI_STA);

  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi");

  // while(WiFi.status()!=WL_CONNECTED){
  //   delay(500);
  //   Serial.print(".");
  //   attempts
  // }
  // Serial.println("connected to: "); Serial.print(ssid);
  // Serial.println("IP address: "); Serial.print(WiFi.localIP());

  int attempts = 0;
  while(WiFi.status() != WL_CONNECTED && attempts < 10){ // Try connecting for a maximum of 10 attempts
    delay(500);
    Serial.print(".");
    attempts++;
  }

  if(WiFi.status() == WL_CONNECTED){
    Serial.println("\nConnected to WiFi: "); Serial.println(ssid);
    Serial.println("IP address: "); Serial.println(WiFi.localIP());
  } else {
    Serial.println("\nFailed to connect to WiFi!");
  }

}

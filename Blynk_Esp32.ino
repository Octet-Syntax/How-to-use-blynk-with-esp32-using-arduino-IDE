#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

#define BLYNK_TEMPLATE_ID "TMPL459tAL5b"
#define BLYNK_DEVICE_NAME "Esp32 Blynk"
#define BLYNK_AUTH_TOKEN "lg7QBpO3lW-p1dbpntVPYBfrqnDoM8Se" 
#define BLYNK_PRINT Serial

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Abc";
char pass[] = "jkokm1234";

BlynkTimer timer;

int value = 8;
int Rvalue;

BLYNK_CONNECTED()
{

}
void myTimerEvent()
{
  Blynk.virtualWrite(V1, value);
  Serial.println(Rvalue);
}

BLYNK_WRITE(V2)
{
  // any code you place here will execute when the virtual pin value changes
  Rvalue = param.asInt();
}

void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);

  timer.setInterval(3780L, myTimerEvent);
  delay(3000);
}

void loop()
{
  Blynk.run();
  timer.run();

}


#include <SPI.h>
#include <Ethernet.h>

#define trigPin 13
#define echoPin 12

int port = 80;

void setup()
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop()
{
  long duration;
  long distance;

  //Trigger signaal verzenden
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29,1;
  send(distance);

  delay(500);
}

void send(long distance)
{
  EthernetClient client;
  char serverString[] = "localhost";
  char userString[] = "root";
  char passwordString[] = "";

  if (client.connect(serverString, port))
  {
    Serial.println(distance);

    // Send distance
    sprintf("POST /retrieve.php HTTP/1.1", distance);

    //Send to client
    client.println("Host:");
    client.println("Connection: close");
    client.println();
    client.print(distance);

    //Check of de server bestaat & beschikbaar is
    while(client.connected())
    {
      while(client.available())
      {
        Serial.write(client.read());
      }
    }
  }

  //Verbreken van verbinding
  if (client.connected())
  {
    client.stop();
  }
}

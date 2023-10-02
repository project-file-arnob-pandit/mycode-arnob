#include <ESP8266WiFi.h>



// Replace with your network credentials
// to create its own wifi network
const char* ssid     = "Samsong j6";
const char* password = "ninetime9";

// Assign output variables to GPIO pins
const int output1 = D0;//relay 1
const int output2 = D1;// relay 2
const int output3 = D2;// relay 3
const int output4 = D3;// relay 4
const int output5 = D5;// relay 5
const int output6 = D6;// relay 6
const int output7 = D7;// relay 7
const int output8 = D8;// relay 8





WiFiServer server(80);

String header;
String output1State = "off";
String output2State = "off";
String output3State = "off";
String output4State = "off";
String output5State = "off";
String output6State = "off";
String output7State = "off";
String output8State = "off";

void setup() {
  Serial.begin(115200);
  // Initialize the output variables as outputs
  pinMode(output1, OUTPUT);
  pinMode(output2, OUTPUT);
  pinMode(output3, OUTPUT);
  pinMode(output4, OUTPUT);
  pinMode(output5, OUTPUT);
  pinMode(output6, OUTPUT);
  pinMode(output7, OUTPUT);
  pinMode(output8, OUTPUT);
  // Set outputs to high because we are using active low type relay module
digitalWrite(output1, LOW);
digitalWrite(output2, LOW);
digitalWrite(output3, LOW);
digitalWrite(output4, LOW);
digitalWrite(output5, LOW);
digitalWrite(output6, LOW);
digitalWrite(output7, LOW);
digitalWrite(output8, LOW);

   connectWiFi();
    while ((!(WiFi.status() == WL_CONNECTED)))
    {
      connectWiFi();
    }
   
   server.begin();
}

void loop()
{
  while ((!(WiFi.status() == WL_CONNECTED)))
    {
      connectWiFi();
    }
    
  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
        
// turns the GPIOs on and off
            //foe GPIO7
            if (header.indexOf("GET /1/on") >= 0) 
           {
             Serial.println("RELAY 1 on");
              output1State = "on";
             digitalWrite(output1, HIGH);
            } 
            else if (header.indexOf("GET /1/off") >= 0) 
            {
             Serial.println("RELAY 1 off");
              output1State = "off";
              digitalWrite(output1, LOW);
           }


    //for GPIO8
          else if (header.indexOf("GET /2/on") >= 0)
           {
             Serial.println("RELAY 2 on");
             output2State = "on";
             digitalWrite(output2, HIGH);
            } 
            else if (header.indexOf("GET /2/off") >= 0)
            {
              Serial.println("RELAY 2 off");
              output2State = "off";
              digitalWrite(output2, LOW);
            }
             
             
//             //for GPIO3
             else if (header.indexOf("GET /3/on") >= 0)
            {
              Serial.println("RELAY 3 on");
              output3State = "on";
              digitalWrite(output3, HIGH);
            } 
            else if (header.indexOf("GET /3/off") >= 0)
            {
              Serial.println("RELAY 3 off");
              output3State = "off";
              digitalWrite(output3, LOW);
            }

          
            
//            
//            //for GPIO4
           else if (header.indexOf("GET /4/on") >= 0)
           {
              Serial.println("RELAY 4 on");
              output4State = "on";
              digitalWrite(output4, HIGH);
            } 
            else if (header.indexOf("GET /4/off") >= 0)
            {
             Serial.println("RELAY 4 off");
              output4State = "off";
             digitalWrite(output4, LOW);
           }
              

            // turns the GPIOs on and off
            //foe GPIO12
            if (header.indexOf("GET /5/on") >= 0) 
            {
              Serial.println("RELAY 5 on");
              output5State = "on";
              digitalWrite(output5, HIGH);
            } 
            else if (header.indexOf("GET /5/off") >= 0) 
            {
              Serial.println("RELAY 5 off");
              output5State = "off";
              digitalWrite(output5, LOW);
            }




            //for GPIO6
            else if (header.indexOf("GET /6/on") >= 0)
            {
              Serial.println("RELAY 6 on");
              output6State = "on";
              digitalWrite(output6, HIGH);
            } 
            else if (header.indexOf("GET /6/off") >= 0)
            {
              Serial.println("RELAY 6 off");
              output6State = "off";
              digitalWrite(output6, LOW);
            }
            
             
             
             //for GPIO7
             else if (header.indexOf("GET /7/on") >= 0)
            {
              Serial.println("RELAY 7 on");
              output7State = "on";
              digitalWrite(output7, HIGH);
            } 
            else if (header.indexOf("GET /7/off") >= 0)
            {
              Serial.println("RELAY 7 off");
              output7State = "off";
              digitalWrite(output7, LOW);
            }

          
            
            
            //for GPIO8
            else if (header.indexOf("GET /8/on") >= 0)
            {
              Serial.println("RELAY 8 on");
              output8State = "on";
              digitalWrite(output8, HIGH);
            } 
            else if (header.indexOf("GET /8/off") >= 0)
            {
              Serial.println("RELAY 8 off");
              output8State = "off";
              digitalWrite(output8, LOW);
            }
          
            
            
            
            
            
            
            
            
            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons 
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<style>html { font-family: Helvetica; display:inline; margin: 0px auto; justify-content: center; text-align: center;}");
            client.println(".button { background-color: #00ccff; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #ee00ff;}</style></head>");
            
            // Web Page Heading
            client.println("<body><h1> smart home </h1>");
            client.println("<style>p{color:white;}</style>");
            client.println("<style>a{color:white;}</style>");
            
                        // Display current state, and ON/OFF buttons for RELAY 1  
            client.println("<p>RELAY 1 - State " + output1State + "</p>");
            // If the output1State is off, it displays the ON button       
            if (output1State=="off") {
              client.println("<p><a href=\"/1/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/1/off\"><button class=\"button button2\">OFF</button></a></p>");
            } 
               
            
            
            
            
            
            
            // Display current state, and ON/OFF buttons for RELAY 2  
            client.println("<p>RELAY 2 - State " + output2State + "</p>");
            // If the output2State is off, it displays the ON button       
            if (output2State=="off") {
              client.println("<p><a href=\"/2/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/2/off\"><button class=\"button button2\">OFF</button></a></p>");
            }


    // Display current state, and ON/OFF buttons for RELAY 3 
            client.println("<p>RELAY 3 - State " + output3State + "</p>");
            // If the output3State is off, it displays the ON button       
            if (output3State=="off") {
              client.println("<p><a href=\"/3/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/3/off\"><button class=\"button button2\">OFF</button></a></p>");
            }

    // Display current state, and ON/OFF buttons for RELAY 4  
            client.println("<p>RELAY 4 - State " + output4State + "</p>");
            // If the output4State is off, it displays the ON button       
            if (output4State=="off") {
              client.println("<p><a href=\"/4/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/4/off\"><button class=\"button button2\">OFF</button></a></p>");
            }


            // Display current state, and ON/OFF buttons for RELAY 5  
            client.println("<p>RELAY 5 - State " + output5State + "</p>");
            // If the output5State is off, it displays the ON button       
            if (output5State=="off") {
              client.println("<p><a href=\"/5/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/5/off\"><button class=\"button button2\">OFF</button></a></p>");
            } 
               
            
            
            
            
            
            
            // Display current state, and ON/OFF buttons for RELAY 6  
            client.println("<p>RELAY 6 - State " + output6State + "</p>");
            // If the output6State is off, it displays the ON button       
            if (output6State=="off") {
              client.println("<p><a href=\"/6/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/6/off\"><button class=\"button button2\">OFF</button></a></p>");
            }


//    // Display current state, and ON/OFF buttons for RELAY 7 
            client.println("<p>RELAY 7 - State " + output7State + "</p>");
            // If the output7State is off, it displays the ON button       
           if (output7State=="off") {
              client.println("<p><a href=\"/7/on\"><button class=\"button\">ON</button></a></p>");
           } else {
             client.println("<p><a href=\"/7/off\"><button class=\"button button2\">OFF</button></a></p>");
           }

//    // Display current state, and ON/OFF buttons for RELAY 8  
            client.println("<p>RELAY 8 - State " + output8State + "</p>");
            // If the output8State is off, it displays the ON button       
           if (output8State=="off") {
             client.println("<p><a href=\"/8/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/8/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
	

          client.println("</body></html>");
            
            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}

void connectWiFi()
{ 
  pinMode(2, OUTPUT);
  WiFi.disconnect();
  WiFi.mode(WIFI_STA);
  Serial.println("Connecting to wifi......");
 
  WiFi.begin(ssid, password);
  while ((!(WiFi.status() == WL_CONNECTED)))
  {
    digitalWrite(2,HIGH);
    delay(300);
    digitalWrite(2,LOW);
    delay(200);
    
    Serial.println(" - ");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("NodeMCU Local IP is : ");
  Serial.print((WiFi.localIP()));

  
  digitalWrite(2,HIGH);
  delay(400);
  digitalWrite(2,LOW);

}

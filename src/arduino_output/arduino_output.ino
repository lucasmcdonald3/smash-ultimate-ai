#include <Gamecube.h>
#include <Nintendo.h>
#include <N64.h>
#include <N64API.h>
#include <GamecubeAPI.h>
#include <Gamecube_N64.h>

/* This code uses the Nicohood Library
 * Use this code at your own risk
 * Code written by Simple Controllers and this code is open source.
 * Meaning its free to share, improve on, or anything you like!
 * Just remember to mention you used my code!
 * Version 2.0 I just suck at github
 */

//This makes the controller bidirection data line on pin number8
//CGamecubeConsole GamecubeConsole(8);      //Defines a "Gamecube Console" sending data to the console on pin 8

//This is needed but you don't need a controller on pin 7
//CGamecubeController GamecubeController1(7);

Gamecube_Data_t d = defaultGamecubeData;   //Structure for data to be sent to console
int incoming_byte = 0;

void setup()
{
  //This is needed to run the code.
  
  //GamecubeController1.read();
  Serial.begin(9600);
}

void loop()
{
    if (Serial.available() > 0) {
        incoming_byte = Serial.read();
        char button_pressed = char(incoming_byte);
        Serial.print(button_pressed);
        switch(button_pressed) {
            case 's': //start
                d.report.start = 1 - d.report.start;
                break;
            case 'y':
                d.report.y = 1 - d.report.y;
                break;
            case 'x':
                d.report.x = 1 - d.report.x;
                break;
            case 'b':
                d.report.b = 1 - d.report.b;
                break;
            case 'a':
                d.report.a = 1 - d.report.a;
                break;
            case 'l':
                d.report.l = 1 - d.report.l;
                break;
            case 'r':
                d.report.r = 1 - d.report.r;
                break;
            case 'z':
                d.report.z = 1 - d.report.z;
                break;
            case 'u': //dup
                d.report.dup = 1 - d.report.dup;
                break;
            case 'd': //ddown
                d.report.ddown = 1 - d.report.ddown;
                break;
            case 't': //dright
                d.report.dright = 1 - d.report.dright;
                break;
            case 'k': //dleft
                d.report.dleft = 1 - d.report.dleft;
                break;
            case 'j': //joystick-x
                d.report.xAxis = Serial.read();
                break;
            case 'i': //joystick-y
                d.report.yAxis = Serial.read();
                break;
            case 'c': //cstick-x
                d.report.cxAxis = Serial.read();
                break;
            case 'v': //cstick-y
                d.report.cyAxis = Serial.read();
                break;
        }

        /*

        // Byte 0
        incoming_byte = Serial.read();
        d.report.start = bitRead(incoming_byte, 3);
        d.report.y = bitRead(incoming_byte, 4);
        d.report.x = bitRead(incoming_byte, 5);
        d.report.b = bitRead(incoming_byte, 6);
        d.report.a = bitRead(incoming_byte, 7);
        // Byte 1
        incoming_byte = Serial.read();
        d.report.l = bitRead(incoming_byte, 1);
        d.report.r = bitRead(incoming_byte, 2);
        d.report.z = bitRead(incoming_byte, 3);
        d.report.dup = bitRead(incoming_byte, 4);
        d.report.ddown = bitRead(incoming_byte, 5);
        d.report.dright = bitRead(incoming_byte, 6);
        d.report.dleft = bitRead(incoming_byte, 7);
        // Byte 2
        incoming_byte = Serial.read();
        d.report.xAxis = incoming_byte;
        // Byte 3
        incoming_byte = Serial.read();
        d.report.yAxis = incoming_byte;
        // Byte 4
        incoming_byte = Serial.read();
        d.report.cxAxis = incoming_byte;
        // Byte 5
        incoming_byte = Serial.read();
        d.report.cyAxis = incoming_byte;
        // Byte 6
        incoming_byte = Serial.read();
        d.report.left = incoming_byte;
        // Byte 7
        incoming_byte = Serial.read();
        d.report.right = incoming_byte;
        */
        //sends the complied data to console when console polls for the input
        //GamecubeConsole.write(d);

        
    }

    Serial.print("abxy");
    Serial.print(int(d.report.a));
    Serial.print(int(d.report.b));
    Serial.print(int(d.report.x));
    Serial.print(int(d.report.y));
    Serial.flush();

    
    
}

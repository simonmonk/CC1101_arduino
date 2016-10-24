# CC1101_arduino
A clone of the ELECHOUSE_CC1101 http://www.elechouse.com library updated for Arduino 1.0 plus.

I made the following changes to the original library.
* Changed imports of WProgram.h to Arduino.h in line with Arduino 1.0+
* Changed the init method so that you have to set the carrier frequency


# Connecting an Arduino to a CC1101
These instructions are for an Arduino Uno.

|Arduino|CC1101|Notes|
|-------|------|-----|
|GND    |GND| |
|3.3V|VCC||
|10|CSN/SS|Must be level shifted to 3.3V|
|11|SI/MOSI|Must be level shifted to 3.3V|
|12|SO/MISO||
|13|SCK|Must be level shifted to 3.3V|
|2|GD0|Signals buffer ready to read|


![alt text](https://github.com/simonmonk/CC1101_arduino/blob/master/F19_10.png?raw=true_ "Connections")


# Installing the Library

To install the library into your IDE:
* click on the Clone or Download button on this Github page and select Download ZIP.
* Start the Arduino IDE and from the Sketch menu do Sketch->Include Library->Add ZIP Library and select the ZIP you just downloaded.


#API Reference

This is a very easy library to use. You may just wish to try out the examples, that send a text message from one Arduino to another using the Serial Monitor. But for completeness, here it is:


## Include File

```
#include <ELECHOUSE_CC1101.h>
```


## Initialisation

Put this in your setup function.

```
ELECHOUSE_cc1101.Init(F_433); // set frequency - F_433, F_868, F_965 MHz
```


## Send/Receive Mode

Put this in your setup function and call again, any time after you have processed a received message.

When a new message arives GD0 on the CC1101 (Arduino pin 2) will be set LOW. You can hook this up to an interrupt or just watch for it in your loop function.


```
 ELECHOUSE_cc1101.SetReceive();
```


## Receiving Data

The maximum data size is 64 bits.

ReceiveData requires a buffer of type byte[] and returns the number of bytes contained in the message.

```
int len = ELECHOUSE_cc1101.ReceiveData(buffer);
```



## Sending Data

The maximum data size is 64 bits.

SendData requires a buffer of type byte[] and the number of bytes contained in the message.

```
ELECHOUSE_cc1101.SendData(buffer, len);
```



#Legal

	This library was originally copyright of Michael at elechouse.com but permision was
    granted by Wilson Shen on 2016-10-23 for me (Simon Monk) to uodate the code for Arduino 1.0+
    and release the code on github under the MIT license.


Wilson Shen <elechouse@elechouse.com>	23 October 2016 at 02:08
To: Simon Monk 
Thanks for your email.
You are free to put it in github and to do and change.

On Oct 22, 2016 10:07 PM, "Simon Monk" <srmonk@gmail.com> wrote:
	Hi,

	I'm Simon Monk, I'm currently writing the Electronics Cookbook for O'Reilly. I use your 
	ELECHOUSE_CC1101 library in a 'recipe'. Your library is by far the easiest to use of 
	the libraries for this device, but the .h and .cpp file both reference WProgram.h which 
	as replaced by Arduino.h in Arduino 1.0.

	Rather than have to talk my readers through applying a fix to your library, I'd like 
	your permission to put the modified lib into Github and add an example from the book. 
	I would of course provide a link to your website in the book and mention that you can buy 
	the modules there. If its ok, I'd give the code an MIT OS license, to clarify its use.

	Thanks for a great library,

	Kind Regards,

	Simon Monk.
#include <Arduino.h>
#include "PushBTN.h"
#include "LED.h"

void btnPush();
void btnHold();
void btnDouble();

PushBTN button(BTN_PIN, BTN_ACT, btnPush, btnHold, btnDouble);

LED led1(LED_PIN1, LED_ACT1);
LED led2(LED_PIN2, LED_ACT2);

bool controlLED1 = true;

void setup()
{
    led1.off();
    led2.off();
}

void loop()
{
    button.loop();
    led1.loop();
    led2.loop();
}

void btnPush()
{
    if (controlLED1) led1.flip();
    else led2.flip();
}

void btnHold(){
    if (controlLED1) led1.blink(200);
    else led2.blink(200);
}

void btnDouble(){
    controlLED1 = !controlLED1;
}
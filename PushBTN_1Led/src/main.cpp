#include <Arduino.h>
#include "PushBTN.h"
#include "LED.h"

void btnPush();
void btnHold();
void btnDouble();

PushBTN button(BTN_PIN, BTN_ACT, btnPush, btnHold, btnDouble);

LED led(LED_PIN, LED_ACT);

void setup()
{
    led.off();
}

void loop()
{
    button.loop();
    led.loop();
}

void btnPush()
{
    led.flip();
}

void btnHold(){
    led.blink(1000);
}

void btnDouble(){
    led.blink(200);
}
#pragma once

#include <Arduino.h>
#include <functional>

class PushBTN {
public:
    PushBTN(const byte pin, const bool push, void (&pushCallback)(), 
            void (&holdCallback)(), void (&doubleClickCallback)(), 
            const int holdTime = 2000, const int debounceTime = 5);

    void loop();

private:
    const byte _pin;
    const bool _active; 
    std::function<void()> _pushCallback{ [](){} };
    std::function<void()> _holdCallback{ [](){} };
    std::function<void()> _doubleClickCallback{ [](){} }; 

    unsigned long holdTimer = 0;
    unsigned long currentTime = 0;  // Thoi gian bam nut
    unsigned long lastPushTime = 0; // Thời gian tha nut
    
    const unsigned int _holdTime = 2000; // Thoi gian giu nut
    const unsigned int _debounceTime = 5; //Thoi gian chong rung
    const unsigned long doubleClickTime = 300; //Thoi gian toi da giua 2 lan bam
    int clickCount = 0; 

    enum States {
        RELEASE = 0,
        PUSH_WAIT = 1,
        HOLD_WAIT = 2,
        PUSH = 3,
        HOLD = 4,
        RELEASE_WAIT = 5,
        DOUBLE_CLICK_WAIT = 6, 
    } state = RELEASE;
};

/***** Implementation: *****/

PushBTN::PushBTN(const byte pin, const bool active, void (&pushCallback)(), 
                 void (&holdCallback)(), void (&doubleClickCallback)(), 
                 const int holdTime, const int debounceTime)
    : _pin(pin), _active(active), 
      _pushCallback(pushCallback), 
      _holdCallback(holdCallback), 
      _doubleClickCallback(doubleClickCallback), 
      _holdTime(holdTime),
      _debounceTime(debounceTime) 
{
    if (active == LOW)
        pinMode(_pin, INPUT_PULLUP);
    else
        pinMode(_pin, INPUT);
}

void PushBTN::loop() {
    switch (state) {
    case RELEASE:
        if (digitalRead(_pin) == _active) {
            holdTimer = millis();
            currentTime = millis();
            clickCount++;
            state = PUSH_WAIT;
        }
        break;

    case PUSH_WAIT:
        if ((millis() - holdTimer) > _debounceTime) {
            if (digitalRead(_pin) == _active) { 
                state = HOLD_WAIT;
            } else { 
                state = RELEASE;
            }
        }
        break;

    case HOLD_WAIT:
        if (digitalRead(_pin) != _active) { 
            if ((millis() - holdTimer) < _holdTime) {
                state = PUSH;
                if (currentTime - lastPushTime <= doubleClickTime) {
                    state = DOUBLE_CLICK_WAIT;
                }
            }
            } else if ((millis() - holdTimer) >= _holdTime){
                state = HOLD; 
            }
        break;
    

    case PUSH:
        _pushCallback();
        clickCount = 0; 
        state = RELEASE_WAIT;
        break;

    case HOLD:
        _holdCallback(); 
        clickCount = 0; 
        state = RELEASE_WAIT;
        break;

    case DOUBLE_CLICK_WAIT:
        _doubleClickCallback(); 
        clickCount = 0; 
        state = RELEASE_WAIT;
        break;

    case RELEASE_WAIT:
        if (digitalRead(_pin) != _active) {
            state = RELEASE; 
            lastPushTime = millis(); 
        }
        break;
    }
}

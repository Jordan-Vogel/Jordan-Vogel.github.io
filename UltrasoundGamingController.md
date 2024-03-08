# Ultrasound Accessible Gaming Controller
Adaptive gaming controllers are designed to enable individuals with limited mobility to play video games. The majority of these devices involve pushing buttons, making this controller inaccessible for people who do not have to use their hands. For my final project in my Bio-signal Processing course, I designed a handsfree device that allowed a user to control four inputs using head movements via an ultrasonic range-finding device.

# Hardware and Circuit Design
The device is built around an Arduino Uno microcontroller. We used two ultrasonic distance sensors to track head movements. To show the inputs, we added four LEDs and also included an OLED module for a clearer display of the inputs. A diagram and image of the circuit is included below.

<img src="/images/ControllerCircuit.png" width="400" height="400"> <img src="/images/GamingController.JPG" width="400" height="400">

# Source Code
The controller's code was developed in C++ using the Arduino IDE. To measure distances, we used ultrasound pulses. The process involves sending out a pulse and measuring the time it takes to bounce back from an object. We calculate the distance by multiplying this time by the speed of sound and then dividing by two, since the pulse travels to the object and back. Based on this distance calculation, we then determine if the object is close enough to trigger a button press. The code is attached below.

For a detailed look at the implementation, [view the Arduino code here](https://github.com/Jordan-Vogel/Jordan-Vogel.github.io/blob/main/assets/GamingController.ino).


[Click here to view the Arduino code](/assets/GamingController.ino)

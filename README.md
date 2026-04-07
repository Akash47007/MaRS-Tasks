# MaRS-Tasks

# Task-1
**Question-1:**
	
I have connected 3 led to pin 2, 3 and 4 with them blinking at 500, 1000, and 1500 ms respectively. The code logic is simple, in each iteration of the loop, we get the current runtime of the board through millis function. We calculate the delta between the last update time, stored separately in a variable (pi, i=1,2,3), and if its is greater or equal to the leds blink time intervals, they blink by turning on and off for a delay of 20ms handled by the same if condition. I have made sure that the delay of 20ms doesn’t propagate or add up to the main delay of 500ms, 1000ms and 1500ms. 

Link: https://www.tinkercad.com/things/8s9ezU0oZun-led-blink?sharecode=pWJluuEiFUNYfU3zl7cAsePRmBrMa7zbi86QGyDJG8w

**Question-2:** 
	
The potentiometer is an analog device. When connected to the analog pin on the Arduino, the movement of the potentiometer can be interpreted by the analogRead() function which returns a value between 0 and 1024. We can use the map() function to translate the change in potentiometer values to the desired pwm duty cycle and milli seconds changes. The blinking of the led is handles using  millis() so that there is no intrusion in changing of the color as we rotate th epotentiometer.

Link: https://www.tinkercad.com/things/cinpAkhd2XW-led?sharecode=MGje-90XqrW1KJXCRnkISf6Fm4Z0WHjLp4lhzZxmQpw

**Question-3:** 
	
The code uses the random() function to get a delay between 2-5 seconds. Then the led comes on after the random amount of time. Then the led stays on until the user presses the button and the delay between the led turning on and the user pressing the button is shown as the reaction time. The reaction time is then printed in serial.  

Link: https://www.tinkercad.com/things/eiIDkg1VYNa-reaction-time?sharecode=CscrUGsr6cRBZgihPXdGKREZ-WzGZwDLHVYZgu9ID1g

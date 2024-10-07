# Arduino_Joystick_Piano

This project was created because of inspiration from a minigame in Final Fantasy 7 Rebirth. It is a joystick attached to an arduino and buzzer which plays notes of differing frequencies depending on where the joystick is positioned. The pad is split into 9 regions - akin to an analog keypad - each of which has their own function. The center region 5 is dead space for when you don't want to play any notes. Regions 8-4 (On a keypad) form a counter clockwise wheel of keys from A to G, and region 7 swaps the notes played from their normal notes to their sharp variants and vise versa.
# A visual representation of the joystick zones:
![image](https://github.com/user-attachments/assets/2f28a67c-af3b-404b-8b0b-e4b22da0f322)
![sample SVG image](https://github.com/RASacker/Arduino_Joystick_Piano/blob/main/diagram.svg)

# A few images of the project:
![20240503_112052](https://github.com/RASacker/Arduino_Joystick_Piano/assets/123014761/5edb0c82-178f-481d-9816-c738d78542f5)
![20240503_112059](https://github.com/RASacker/Arduino_Joystick_Piano/assets/123014761/72583034-4e00-445d-92d9-ad36744de9cd)

# And a link to a youtube video showcasing it:
https://youtube.com/shorts/FbyzZHJ5N-0

The program works by reading the respective X and Y axis of the joystick and storing them in individual ints at the beginning of each loop. It then runs tests on those ints to detirmine in which region it lies. In the lower left, A function is called which inverts a global variable "Sharp." This Sharp is checked everytime just before playNote to ensure the correct note is being played. While the joystick is in an eligible region, depending on the state of sharp, the appropriate note is played via playNote. The function playNote takes a set frequency respective to each note and oscilates the buzzer in tune with the frequency via delays.

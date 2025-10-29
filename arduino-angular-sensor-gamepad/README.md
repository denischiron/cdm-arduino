# Arduino Leonardo as Gamepad

[ArduinoXInput](https://github.com/dmadison/ArduinoXInput)
[ArduinoXInput_AVR](https://github.com/dmadison/ArduinoXInput_AVR)

In Arduino IDE :

1) Menu : File > Preferences : 
Add the following line to the "Additional Boards Manager URLs" list:
https://raw.githubusercontent.com/dmadison/ArduinoXInput_Boards/master/package_dmadison_xinput_index.json

Cf [Add third-party platforms to the Boards Manager in Arduino IDE – Arduino Help Center](https://support.arduino.cc/hc/en-us/articles/360016466340-Add-third-party-platforms-to-the-Boards-Manager-in-Arduino-IDE)

2) Menu Tools > Boards > BoardsManager :
Install "XInput AVR Boards"

Cf [Add boards to Arduino IDE – Arduino Help Center](https://support.arduino.cc/hc/en-us/articles/360016119519-Add-boards-to-Arduino-IDE)

3) In select "Select board", choose : Arduino Leonardo w/ XInput

4) To update sketch on board :
- compile
- upload 
- when IDE displays "Uploading", push the board reset button twice

5) Test :
[GamePad Tester](https://hardwaretester.com/gamepad)
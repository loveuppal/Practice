## Instructions to flash the OS onto the Beaglebone Black.
**Requirements**<br />
- balenaEtcher >> *https://www.balena.io/etcher/* <br />
- Beaglebone OS Image >> *https://beagleboard.org/latest-images* <br />
- SD Card<br />
- Beaglebone<br />
- Micro USB cable.<br />

**Steps**<br />
- Download the Flasher software *balenaEtcher* and install it.<br />
- Download the latest OS Image for your Beaglebone.<br />
- Connect the SD card to PC.
- Open *balenaEtcer* then *Select OS Image > Select SD Card > Flash*<br />
- Remove the SD card.<br />
- Open the SD Card, Navigate to */boot/uEnv.txt, Edit it by *sudo nano uEnv.txt*.*<br />
- Search for *#cmdline=init=/opt/scripts/tools/eMMC/init-eMMC-flasher-v3.sh* and Remove **#** <br />
- Insert the SD into Beaglebone, *Press and Hold* the button beside the *Ethernet Port*, then power-up the Beaglebone.<br />
- *ALL LEDS WILL FLASH AT ONCE* then they blink accordingly.<br />
- *WAIT UNTIL ALL THE LEDS OFF*<br />
- *DONE*<br />

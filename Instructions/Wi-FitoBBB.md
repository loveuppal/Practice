## Intsructions to connect Wi-Fi to BBB.
- Initially check if you have already installed a Wi-Fi driver in your BBB. (probably it is not.) </br>
- Open terminal and type ***iwconfig*** to check if you can see ***wlan0***.</br>
- If you dont have one, it does mean you've no Wi-Fi driver installed.
- Check online if the Wi-Fi adapter you are using has drivers for linux.
### ***T2U Nano*** Wi-fi adpater driver Installation as follows.
- Connect ethernet to your BBB to access the internet.
- Download the latest kernel-headers of your BBB.</br>
   **$ sudo apt install linux-headers-$(uname -r)**
- Update and Upgrade you BBB.</br>
   **$ sudo apt update && sudo apt upgrade**

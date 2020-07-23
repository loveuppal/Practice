# Cross Compilation b/w Eclipse and Beaglebone Black.
## Connect BBB to Eclipse.
- Install Remote Server Systems in your Eclipse.
```
Help >> Install New Software | Work with: All available sites and Search "Remote".
```
- Make sure you have following installed.
```
Remote System Explorer User Actions			4.5.100.202002061858
Terminal (Console) View				4.6.1.202005101600
Remote System Explorer End-User Runtime		4.5.100.202002061858
TM Terminal via Remote API Connector Extensions	4.6.0.202001311822
TM Terminal						4.6.0.202001311822
```
- Get the Remote Server Explorer
```
Window >> Perspective > Open Perspective > Others > Remote System Explorer
```
- You will get the Remote Explorer either Down or on Left side.
- To create a connection do as follows
```
Remote Explorer > Local > right_click > New > Connections. > Next
Linux > | Host: 192.168.6.2 | Connection: Beaglebone. > Next
Check all, ONLY the SSHs, click Nexts and Finish.
```
- You will see *Beaglebone* Connection in the Remote explorer.
```
Click on My home and you will enter the credentials.
```
- You are now connected view all the files in BBB by dropping down menu.

### BBB Terminal View in Eclipse
- You can explore the BBB while in Eclipse by enabling the SSH terminal window.
- If you can't see *Terminal* Tab, go here.
```
Window > Show view > Terminal. 
```
```
On the Terminal Tab, On the right most top, you will see (+).
Choose Terminal	: SSH Terminal
Host 			: 192.168.6.2
User			: debian
Password		: temppwd
OK
```
- Now you can browse the BBB.

## Install the Cross compiler.

- Check the location of GCC on the Beagebone.
```
$ whereis gcc
gcc: /usr/bin/gcc /usr/lib/gcc
$ ls /usr/lib/gcc
```
- You'll see either of these
```
arm-linux-gnueabihf (or) arm-linux-gnueabi
```
- Now on your Host Machine, install the ARM GCC Compiler.

```
$ sudo apt update && sudo apt upgrade
$ sudo apt install arm-linux-gnueabihf
$ sudo apt update && sudo apt upgrade
```
- Replace with **arm-linux-gnueabi** if your BBB has this Compiler.

## Running a sample code.
### Build Settings
- Create a New Project > C/C++ Project > C Managed Build > Executable > Empty Project > Linux GCC > Finish
- Right Clickon Project > Properties
- C/C++ Build > Settings > Tool Settings.
```

GCC Compiler | Command : arm-linux-gnueabihf-gcc 
GCC C Linker | Command : arm-linux-gnueabihf-gcc
GCC Assembler| Command : arm-linux-gnueabihf-as
```
- C/C++ General > Paths and Symbols
```
Includes	| Add : /usr/arm-linux-gnueabihf/include
Libary Paths	| Add : /usr/arm-linux-gnueabihf/lib
```
Replace with **arm-linux-gnueabi** if your BBB has this Compiler.

### Running the code in the BBB.
- Write the code.
- Build the project.
- Copy file under **Debug**
```
Test -[arm/le]
```
- Paste into the Remote server Beaglebone Connection.
- Make it executable file.
```
chmod ugo+x Test
```
- run the file.
```
./Test
```
- You've run.

### Remote debugging the code within the Eclipse.
- Go to the working project ``` > Right-Click > Run As > Run Configuration```
```
C/C++ Remote Application > Double-Click

Main:
Connection > New > Connection Type : SSH
```
```
New Connection:
Remote Name : AnyName
Host        : 192.168.7.2
User        : debian
Password    : ••••••
Finish
```
```
Main: 
Remote Absolye File Path for C/C++ Appliction : Locate where you want to run the code.
```

>> sudo dpkg --configure -a					//checks what dependencies are required
>> sudo apt-get install -f					//installs the listed missing dependencies
 
>> sudo ln -s ../path/../executable_file /usr/local/bin		//To create an application shortcut.

>> sudo chmod +x ../path/executable.bin				//to change .bin to executable
>> sudo dpkg -i ../path/executable.bin				//to install the .deb file

>> sudo dpkg --configure -a    					//checks what dependencies are required
>> sudo apt-get install -f  					//installs the listed missing dependencies
 
>> sudo ln -s ../path/../executable_file /usr/local/bin		//To create an application shortcut.

>> sudo chown $USER -R /targetPath	 			//To change the ownership of the device

>> whereis file     						//to know the location or the path of the file.
>> file filename 						// To know the file type

>> sudo mount /dev/mountFile ../path/..     			//mount a device.
>> sudo umount /dev/mountFile               			//dismount a device
>> lsblk                                  			// lists the devices.
>> ls -l ../path/file                    			//to know ownsership
 
>> sudo su      						//Get into the root
>> Ctrl+D (multiple times until exit) 				// to exit from root
>> su username                           			// to exit from root

>> cat > ../path/..filename.format  				// to create a document file and then can be written.
>> nano ../path/.. filename.format  				// to create a document file and then can be written.

>> gcc filename.c -o filename     				//to compile a C file
>> ./filename                     				//to execute the compiled C file

>>tar xvzf filename.tar.gz       				//to extract .gz file
>>tar xf filename.tar.xz        				//to extract .xz file

>> sudo mkfs.FILEFORMAT /dev/path     				//to change filesystem of drives
>> sudo fdisk -l                     				//to check the drives

/*always move manual installation package into /usr/local*/
>> sudo mv ../path/filefolder /usr/local.
 
 /*to change folders containing multiple sub-folders of files use -r (recursive)*/
 >> cp -r    							//copy folder containg multile files
 >> rm -r    							//delete folders containg multiple files
 
 /*If error like Glob, regex, unable to locate. do not apt install, instead use*/
 >> sudo dpkg -i executablefile
 
 /*If left or right mouse button doesnt work*/
 >> sudo apt install gnome-tweaks >> select "Area"
 
 >> 
 


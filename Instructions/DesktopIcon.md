### Create a Desktop Icon of a missing application.
- Create a *.desktop* file at *~/.local/share/applications*
``` 
 $ nano ~/.local/share/applications/APPNAME.desktop**
```
- Add the following lines onto the file.

```
[Desktop Entry]
Comment=APPNAME 
Terminal=false 
Name=APPNAME
Exec=/path/../application
Type=Application
Icon=/path/../icon.xpm 
StartupWMClass=APPNAME
```

- Make the .desktop file executable.
``` 
 $ chmod a+x ~/.local/share/applications/APPNAME.desktop
```

- Now you'll be able to see the app.

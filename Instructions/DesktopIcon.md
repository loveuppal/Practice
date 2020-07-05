### Create a Desktop Icon of a missing application.
- Create a *.desktop* file at *~/.local/share/applications*
``` 
 $ nano ~/.local/share/applications/APPNAME.desktop**
```
- Add the following lines onto the file.

```
[Desktop Entry]
Comment=Eclipse 
Terminal=false 
Name=Eclipse
Exec=/path/../application
Type=Application
Icon=/path/../icon.xpm 
StartupWMClass=Eclipse
```

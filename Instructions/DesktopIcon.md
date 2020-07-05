### Create a Desktop Icon of a missing application.
- Create a *.desktop* file at *~/.local/share/applications*
 - **:$ nano ~/.local/share/applications/APPNAME.desktop**
- Add the following lines onto the file.
```bash
[Desktop Entry]</ br>
Comment=Eclipse </ br>
Terminal=false </ br>
Name=Eclipse </ br>
Exec=/path/../application</ br>
Type=Application</ br>
Icon=/path/../icon.xpm </ br>
StartupWMClass=Eclipse </ br>
```

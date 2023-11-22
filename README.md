Welcome to the LoL champion search engine manual.

This program is designed to help maintain a note repository for each champion in the game.
Right now it's in a beta state. All feedback appreciated.

Installation:

1. Copy the repository's contents
Currently supported: Linux.
Support will be added for Windows as soon as possible.

This should be enough to make the program run.

Usage:

1. Open your terminal (Linux) or cmd (Windows)
2. Navigate to the folder the binaries are in by either cd (Linux) or dir (Windows)
3. Run the proper binary: ./linux_binary (Linux) or windows_binary.exe (Windows)
4. If this fails, make sure you are in the proper directory/folder as stated by your terminal/cmd
5. If everything works fine you will be greeted with a welcome screen. You can type "help" in the command line to see a list of all commands.


----------------------- 

NOTE: All commands in the "help" command and in the manual will be typed inside quotes. Inside the program, however, the proper usage is to type them without quotes, for example: 

Correct: help 

Incorrect: "help" 

Commands might be case sensitive so be careful about how you input them!
The default way to type is full lowercase so leave capslock alone and you'll be fine.

-----------------------


Description of all commands:

"help" - displays the names of all commands

"search" - prompts you to input a champion name (lowercase)

After you input the name of the champion you will be prompted to input the name of the enemy champion (also lowercase).

Next, if the program locates the file correctly, you will be asked if you want to display the file contents quickly in the terminal, or if you'd rather open the .txt in your default text editor (this depends on your settings, so on Windows it doesn't have to be the "Notepad" app, it could be, say, Notepad++).

Input "d" to display and "o" to open.

Any changes you write and save to the file (after inputting "o") will be saved as if the file was opened by hand.

-----------------------

NOTE: the file paths are NOT hardcoded, so if you follow naming conventions you can add your files to the repository, for example:

aatrox_vs_tips.txt

could contain the tips for playing Aatrox. You'd access the file by inputting, command by command:

"search" >> "aatrox" >> "tips" >> "o" / "d" (The program adds the "__vs__" part automatically).

That way you only have to worry about the naming convention once, during file creation, and essentially create a convenient command to open external files you want to display/edit.

You can look up the debug_notes folder to see how it's done (try searching "debug" >> "enemy")

-----------------------

"quit" - exits the program

"back" - goes back one step, for example from deciding whether to display or open the file to the start of the search. It's kind of shovely right now, as using "back" when typing enemy name would get you back to the main menu. This will be fixed soon.

More will be added here as the program is developed.

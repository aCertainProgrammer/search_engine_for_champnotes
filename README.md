Welcome to the LoL champion search engine manual.

This program is designed to help maintain a note repository for each champion in the game.
Right now it's in a beta state. All feedback appreciated.

Installation:

1. Download the proper ZIP relese
2. Unpack the files
3. Open your terminal (Linux) or cmd (Windows)
4. Navigate to the folder the binaries are in by the `cd` command (for example, ```cd C:\Users\rycerzklanu\Documents\search_engine_for_champions``` in Windows (in linux the "/" is used instead of the "\"). You can also use a relative path.

-----------------------

For example, here's my setup and commands:

The search engine folder containing all the files visible in the repo is placed in the Documents folder. I run Linux.

Therefore, my way of navigating to the proper directory is:

```cd Documents/search_engine_for_champs   <<this is the name of my folder```

-----------------------

5. Run the proper binary: 

```./linux_binary``` (Linux) or 

```windows_binary.exe``` (Windows)

6. If this fails, make sure you are in the proper directory/folder as stated by your terminal/cmd
7. If everything works fine you will be greeted with a welcome screen. You can type 
`help` 
in the command line to see a list of all commands.
8. Execute the 
`createrepo` 
command in order to create all the folders and files. The program will freeze for 20-30 seconds maximum, do not close it, everything will be ok.
9. You are ready to use the program. The steps for opening it are the same as during installation:
    a) navigate to the folder containing the program
    b) execute the binary

----------------------- 

Commands might be case sensitive so be careful about how you input them!
The default way to type is full lowercase so leave capslock alone and you'll be fine.

NOTE2: You can input multiple commands if you separate them with a spacebar, for example (from the main menu): 
```search aatrox akali d renekton camille s poppy riven o```

-----------------------


Description of all commands:

`help` - displays the names of all commands

`search` - prompts you to input a champion name (lowercase)

After you input the name of the champion you will be prompted to input the name of the enemy champion (also lowercase).

Next, if the program locates the file correctly, you will be asked if you want to display the file contents quickly in the terminal, or if you'd rather open the .txt in your default text editor (this depends on your settings, so on Windows it doesn't have to be the "Notepad" app, it could be, say, Notepad++). You can also quickly look up a matchup VOD on Youtube.

Input
`d` to display the contents of the file
`o` to open the file 
`s` to search for the VOD

Any changes you write and save to the file (after inputting `o`) will be saved as if the file was opened manually.

-----------------------

NOTE: the file paths are NOT hardcoded, so if you follow naming conventions you can add your files to the repository, for example:

```aatrox_vs_tips.txt```

could contain the tips for playing Aatrox. You'd access the file by inputting, command by command or all at once:

```search >> aatrox >> tips >> o / d``` (The program adds the "__vs__" part automatically).

That way you only have to worry about the naming convention once, during file creation, and essentially create a convenient command to open external files you want to display/edit.

-----------------------

`quit` - exits the program

`back` - goes back one command. Not implemented fully

`createrepo` - attempts to create champion notes and draft notes folders + files

`draft` - allows you to search draft notes for a champion, in a similar way to the `search` command

More will be added here as the program is developed.

# archlxgger

![nasus-funny-message-to-dumb-arcueid-fans-tsukihime-no-v0-z9kldgq1syqb1](https://github.com/archkr0w/archlxgger/assets/126942746/bbe2d901-2b2f-4dd2-a739-7c935d30b8ee)



### Yo again! 🕊.

this is basically a project created to keep track of your devices, both the word log and the date/time you logged in, which we could call a "keylogger".

### Aspects to be considered 👻

one of the most important purposes is the lack of applications/scripts that can carry this count in a simple and native way in a UNIX/Linux operating system, so I will leave more details to consider for the perfect execution of this program.

in line 52 is one of the quickest ways to get lost, since it is denoted under ' fd = open("/dev/input/event3", O_RDONLY);' , keep in mind that event3 is the device which is your keyboard that can vary different in each of its devices, one of the easiest ways to detect the input device in linux is using the tool "evtest", which if you run it will tell you which event is the device to consider these inputs by the program. (the ideal is to use it with sudo 🫣)

### Execution ⚡

All this was under a linux environment system so follow these commands:
```
 $ locate your file on your's documents with cd respectively.
 $ gcc -o keylogger keylogger.c -std=c99 -I/usr/include/libevdev-1.0/ -levdev
(execute as a superuser)
 $ sudo ./keylogger
 $ easypeasy and is done.
```
### Requeriments to install 🤖
```
note that I use arch btw :xdd: (srry lmao)

 * GCC: GNU Compiler Collection for compiling C programs.
 * libevdev: Library for handling input devices in Linux.
```
- `💉` **`gcc`**<br>
\\___[ gcc important to compile this<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\\\_ `sudo pacman -Syyu`, `sudo pacman -S gcc`

- `🐧` **`libedev`**<br>
\\___[how to install libedev on arch <br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\\\_ `sudo pacman -Syyu`, `sudo pacman -S libedev`







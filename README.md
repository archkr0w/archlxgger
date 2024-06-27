# archlxgger

![nasus-funny-message-to-dumb-arcueid-fans-tsukihime-no-v0-z9kldgq1syqb1](https://github.com/archkr0w/archlxgger/assets/126942746/bbe2d901-2b2f-4dd2-a739-7c935d30b8ee)



### Yo again! 🕊.

**please make use of this program for educational purposes and to become enthusiastic about software knowledge and its practical uses.!!!!!!**

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

### Screenshots to give an idea

 
  *Compilation
     ![f2](https://github.com/archkr0w/archlxgger/assets/126942746/6965db6a-95ec-41fd-ac6b-b18b708b40ef)

  *.txt file generated
 ![f1](https://github.com/archkr0w/archlxgger/assets/126942746/f151d175-2e2f-41f7-a2cf-9d009ab96d56)

  *Example how it works

![f4](https://github.com/archkr0w/archlxgger/assets/126942746/7c4a650c-d2db-4f92-a49a-d60b3acff190)

![f3](https://github.com/archkr0w/archlxgger/assets/126942746/8c38d5fd-f9cc-4a21-a498-027be7cff4e8)


 


**any questions with the program, my ds is in the bio ✧.**


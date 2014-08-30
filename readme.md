# This is a note to learn cs50 course

## install lib

[cs50 manual](https://manual.cs50.net/library/)

    apt-get install gcc
    wget http://mirror.cs50.net/library50/c/library50-c-5.zip
    unzip library50-c-5.zip
    rm -f library50-c-5.zip
    cd library50-c-5
    gcc -c -ggdb -std=c99 cs50.c -o cs50.o
    ar rcs libcs50.a cs50.o
    chmod 0644 cs50.h libcs50.a
    mkdir -p /usr/local/include
    chmod 0755 /usr/local/include
    mv -f cs50.h /usr/local/include
    mkdir -p /usr/local/lib
    chmod 0755 /usr/local/lib
    mv -f libcs50.a /usr/local/lib
    cd ..
    rm -rf library50-c-5

[Where to put new liberary (new to c programming)](http://ubuntuforums.org/showthread.php?t=748771)

    $ gcc -c cs50.c
    $ ar rcs libcs50.a cs50.o
    $ sudo cp libcs50.a /usr/local/lib 

    $ gcc adder.c -I/usr/local/include -L/usr/local/lib -lcs50 -o adder 

## gdb debug tool

[Debugging with GDB （入門篇） ](http://www.study-area.org/goldencat/debug.htm)

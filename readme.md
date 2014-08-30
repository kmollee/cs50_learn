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

## gcc parameter

轉自  http://www.wretch.cc/blog/Geniusking/7263728

※ 使用方式

gcc [option] filename

※ 選項

    -c : 只做編譯(不做連結)
    -S : 輸出組譯碼
    -E : 將預處理結果顯示
    -o filename : 指定輸出檔名
    -ansi : 程式要求依據ansi c標準
    -Dmacro : 使定義巨集(marco)為有效
    -Dmarco=defn : 使定義巨集(marco)為defn
    -Wa,option : 將選項(option)傳給組譯器
    -wl,option : 將選項(option)傳給連結器
    -I : 追加include檔案的搜尋路徑
    -L : 追加library檔案的搜尋路徑
    -l : 指定連結的函式庫
    -Wall : 顯示所有的警告訊息
    -g : 編入除錯資訊(要使用GDB除錯一定要加)
    -O2 : 做最佳化

※ 使用範例

Example:

    gcc -o file a.c b.c c.c
    gcc -Wall -g -o test test.c
    gcc -Iinclude -Llibrary -lmy_lib -o test1 test1.c
    gcc -DDEBUG_ON -o test2 test2.c
    gcc -c -o test3 test.c

### use gdb, gcc need use -g parameter

refer https://gcc.gnu.org/ml/gcc-help/2009-02/msg00130.html

    -g produces debugging information in the OS¹s native format (stabs, COFF,
    XCOFF, or DWARF 2).

    -ggdb produces debugging information specifically intended for gdb.

    -ggdb3 produces extra debugging information, for example: including macro
    definitions.  -ggdb by itself without specifying the level defaults to
    -ggdb2 (i.e., gdb for level 2).

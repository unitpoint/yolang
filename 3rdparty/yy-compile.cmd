@.\re2c-0.13.5\re2c.exe -i -F -b -c -t ..\src\yolang-l.h -o ..\src\yolang-l.cpp ..\src\yy\yolang.l

@.\bison-2.7\win_bison.exe -t -k -l -d -p yo ..\src\yy\yolang.y
@copy /Y .\yolang.tab.c ..\src\yolang-y.cpp
@copy /Y .\yolang.tab.h ..\src\yolang-y.h
@erase .\yolang.tab.c
@erase .\yolang.tab.h

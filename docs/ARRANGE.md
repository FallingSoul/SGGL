# 欢迎使用SGGL库,本指南将指导部署SGGL需要的环境

条件： windows7 SP1及以上

***注：因为团队原因，我们吃了不少win7部署而导致的苦头，所以本指南会特别提出***

## 系统环境部署
请确保您的电脑系统至少在windows7 SP1及以上。如果没有最新的net，请去微软官网下载
- [windows net下载地址](https://dotnet.microsoft.com/zh-cn/download/dotnet-framework)

## msys2下载
因为有大量的库，所以如果没有包管理软件会非常麻烦，因此我们要下载一个msys2
请到这里下载
- [msys2镜像](https://mirrors.tuna.tsinghua.edu.cn/msys2/distrib/)

请根据自己的系统进入1686/x86_64目录。然后选择 msys2-base-i686/x86_64-最新版本时间.sfx.exe

其中i686和x86_64取决于您使用32位还是64位的电脑

## mingw64/32下载
接下来将要下载gcc编译器在windows上。

对于windows7用户 我们建议您使用winlibs，除非您想要放弃调试功能
- [winlibs](https://winlibs.com/)

将其替换掉msys2目录里的mingw64/32记住，名字要一样，直接解压出来即可，不要选择解压到/winlibs目录
mingw64/32取决于您的系统

对于windows10用户，我们推荐您使用msys2直接下载。命令为
``` shell
pacman -S --needed base-devel mingw-w64-x86_64/i686-toolchain
pacman -Syu
pacman -Su
```
如果中间有停顿，按enter就好。其中i686/x86_64取决于您的电脑

## 第三方库下载
恭喜，您已经到这一步了，接下来您要下载我们需要的依赖库

### 下载glfw

``` shell
pacman -Ss glfw
```
应该会出现以下结果：
``` shell
clangarm64/mingw-w64-clang-aarch64-glfw 最新版本号
    A free, open source, portable framework for OpenGL application development (mingw-w64)
mingw32/mingw-w64-i686-glfw 最新版本号
    A free, open source, portable framework for OpenGL application development (mingw-w64)
mingw64/mingw-w64-x86_64-glfw 最新版本号
    A free, open source, portable framework for OpenGL application development (mingw-w64)
ucrt64/mingw-w64-ucrt-x86_64-glfw 最新版本号
    A free, open source, portable framework for OpenGL application development (mingw-w64)
clang32/mingw-w64-clang-i686-glfw 最新版本号
    A free, open source, portable framework for OpenGL application development (mingw-w64)
clang64/mingw-w64-clang-x86_64-glfw 最新版本号
    A free, open source, portable framework for OpenGL application development (mingw-w64)
```
若您是32位，请输入
```shell
pacman -S mingw32/mingw-w64-i686-glfw 最新版本号
```
若您是64位，请输入
```shell
pacman -S mingw64/mingw-w64-x86_64-glfw 最新版本号
```
如果中间有停顿，按enter就好。其中最新版本号请自行替换。

### 下载glew

``` shell
pacman -Ss glew
```
应该会出现以下结果
``` shell
clangarm64/mingw-w64-clang-aarch64-glew 最新版本号
    GLEW, The OpenGL Extension Wrangler Library (mingw-w64)
mingw32/mingw-w64-i686-glew 最新版本号
    GLEW, The OpenGL Extension Wrangler Library (mingw-w64)
mingw64/mingw-w64-x86_64-glew 最新版本号 
    GLEW, The OpenGL Extension Wrangler Library (mingw-w64)
ucrt64/mingw-w64-ucrt-x86_64-glew 最新版本号
    GLEW, The OpenGL Extension Wrangler Library (mingw-w64)
clang32/mingw-w64-clang-i686-glew 最新版本号
    GLEW, The OpenGL Extension Wrangler Library (mingw-w64)
clang64/mingw-w64-clang-x86_64-glew 最新版本号
    GLEW, The OpenGL Extension Wrangler Library (mingw-w64)

```
若您是32位，请输入
```shell
pacman -S mingw32/mingw-w64-i686-glew 最新版本号
```
若您是64位，请输入
```shell
pacman -S mingw64/mingw-w64-x86_64-glew 最新版本号
```
如果中间有停顿，按enter就好。其中最新版本号请自行替换。

## cmake下载
这是最后一步，我们需要用cmake构建项目

如果您是windows7用户，那么我们推荐您使用这个链接下载

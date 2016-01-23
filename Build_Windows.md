#windows编译
##1，需要的依赖库
####ffmpeg
http://ffmpeg.zeranoe.com/builds/ ，选择32位或者64位的[FFmpeg 32-bit Shared Versions]以及[FFmpeg 32-bit Dev Versions]下载；
####vlc 
安装vlc http://www.videolan.org/vlc/index.html ， 安装完成后VLC目录下有VLC的SDK（类似：C:\Program Files (x86)\VideoLAN\VLC\sdk）；  
####openssl
下载openssl源代码https://github.com/openssl/openssl/releases ，依据其文件夹下文档（INSTALL.W32/INSTALL.W64）进行编译安装；

###*windows visual studio 2013 32位的依赖库*
下载地址：http://pan.baidu.com/s/1pKikYJD

##2，修改配置
使用文本编辑器打开BiliLocal.pro，将LIBPATH修改成自己对应的绝对路径（相对路径死活找不到，原因不明）

##3，编译

##4，运行
将vlc和ffmpeg相关的dll复制到运行目录，注意：openssl的dll不要复制，用QT自带的即可；

##5，测试
下载示例视频和弹幕，[下载地址](www.bilibilijj.com/video/av3625944/)

##6，打包发布
将vlc、ffmpeg、QT的相关文件集成到一起压缩打包即可。
  
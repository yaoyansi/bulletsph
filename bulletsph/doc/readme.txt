//--------------------------
Contents
//--------------------------
-Dependences
-Build on Win7(x32) with MSVC2008
-Install
-How to use this plugin
-Reopen the file (or open \test\btsphtest.ma)
-Demo

//--------------------------
Dependences
//--------------------------
-bullet2.78 (http://code.google.com/p/bullet/downloads/list)
 (unzip bullet-2.78.zip to E:\dev\physics\bullet\2.78, and you don't need to build bullet.)
-boost(http://www.boost.org/users/download/)
 (install to E:\dev\boost\1_46_1. I use boost1.46.1, but I think other versions should also work.)
-cuda 4 (http://developer.nvidia.com/cuda-toolkit-40)
  o.Developer Drivers for WinXP/WinVista/Win7
  o.Cuda Toolkit
  o.Cuda Tools SDK
  o.GPU Computing SDK code samples
 (Install all these packages to default directories.)
-Maya2009
(create enviroment MAYA_PATH2009=(your maya directory))

//--------------------------
Build on Win7(x32) with MSVC2008
//--------------------------
This plugin is developed on Win7 x32 with MSVC2008(SP1).Pro.Eng,
and only tested under Maya2009(x32).

- check out the code from https://github.com/yaoyansi/bulletsph to your local directory,
(e.g. E:\dev\myprojects\bulletsph\, and say it $BTSPH_ROOT)
- open $BTSPH_ROOT\bulletsph\bulletsph\build\bulletsph.sln
- choose Debug configuration
- add your boost and bullet directory to "Include Directories"
- build. And the plugin bulletsph_2009x32d.mll will be generated 
  at $BTSPH_ROOT\bulletsph\bulletsph\plugin.


//--------------------------
Install
//--------------------------
For the first time, you need to install this plugin.
-.copy $BTSPH_ROOT/bulletsph/bulletsph/env/*.* to "My Documents\maya\2009\". 
-.open "My Documents\maya\2009\Maya_btsph_only.env", replace
"E:/dev/myprojects/bulletsph" by you local $BTSPH_ROOT. save and close.
-.run "My Documents\maya\2009\btsph_only.bat"
-.copy your cudart32_40_17.dll, freeglut.dll and glew32.dll to $BTSPH_ROOT/bulletsph/bulletsph/plugin

//--------------------------
How to use this plugin
//--------------------------
-.open maya2009, 
-.load bsph_2009x32d.mll, a window named "window1" will popout.
-.select node btSPHMgrNode1, and set Particle Count to 3000.
-.press "create Obstacle and Init boxes",  and two boxes will be generated.
The bigger one is the obstacle box, which defines the obstacle,
and the smaller one is the init box, which defines the particles initial position.
-.Scale the obstacle box 3x3x3 times, and scale the init box 2x2x2 times.

     NOTE: if these boxs are too small, the emitted particles will disappear, 
     and only very few particles can be displayed on the screen.

-.press "create SPH Partilces With Emitter" button, move the emitter and the 
init box anywhere you want inside the obstacle box.
-.select init box and obstacle box,and set the visibility to "off" to hide these two boxes.
-.play the animation.
(-.save the file)
Note: use hardware to render the particles.

//--------------------------
Reopen the file (or open \test\btsphtest.ma)
//--------------------------
-.open the file,
-.execute g_btSPH_InitSPH() in mel script.
(If you don't execute this mel cmd, maya will crash when you play the animation, 
because btSPH is not initilized.)
-.playe the animation.


//--------------------------
Demo
//--------------------------
And here is the demo https://github.com/yaoyansi/bulletsph/blob/master/bulletsph/test/bulletsph.avi.7z
save the url file to your local directory and unzip it.
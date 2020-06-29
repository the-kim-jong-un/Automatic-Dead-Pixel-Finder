# Automatic-Dead-Pixel-Finder
This code will check an image if it contains any imperfection in the color of each pixels, this will help detect and only detect dead pixels on a screen. 

### Further explanations
The main drawback is that the photo of the screen must be of high quality, contains the whole screen, and most importantly only the screen and nothing else.
To correctly detect dead-pixel, the software needs three pictures of a screen (one red, one green, one blue).
If an imperfection is found, the coordinates of the abnormal pixel and the wrong colors will be written in a CSV file contained in *res/* (see next paragraph).




### Image path convention && format && CSV file format
 * an image can be stocked in a file called *data*
 * an image that is supposedly red has to be called "r", a green image must be called "g", a blue image must be called "b"
    * Example : a red image -> *data/r.png*  or  *data/r_whatever.jpg*
 * an image can be either in png, jpg or bmp format 
 * the CSV file will only be created if a pixel is of abnormal color
 * the CSV file will be called by the name of the image minus the image format
    * Example : blue image -> *data/blue.jpg*, therefore the CSV file will be called -> *blue.csv* and will be present in *res/*
    * The convention of the CSV file is "x, y, red_value, green_value, blue_value"
    
    
    
    
### How to use

 * in src/main.cpp, call :  colorSFML::manager(std::string imagePath);
 * change path name to point at the picture which will be analyzed
 * go to root, type in console : *make*, then : *./bin/main*
 
 
 
 
 ### Quick comments
 
To patially compensate for image quality, you can change a value called *balanceValue* line 94. The worse the quality is, the higher that value must be, but still be reasonable because a pixel can only have 255 values (r,g,b). The better the quality, the lower this value can be.
 
 
 
 
### Dependencies 
This code uses SFML library. To download :
https://www.sfml-dev.org/tutorials/2.5/start-linux.php




### Why have I coded something like that when there is better software elsewhere
A company needed an automatic and quick way of finding dead pixels among many computer screens. They therefore needed only 3 pictures, and with that only, the software could figure out "if and where" there were dead pixels among their screens.

#ifndef DEADPIXELFINDER_COLORSFML_H
#define DEADPIXELFINDER_COLORSFML_H

#include <SFML/Graphics.hpp>

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

class colorSFML {
public :
    /**
     * @brief central function
     * @param[in] imgPath : path of the image to analyze
     */
    static void manager(const std::string &);

    /**
     * @brief checks if the path of the image is correct (convention + format)
     * @param[in] imgPath : path of the image to analyze
     * @return c (c is an associated unsigned char value with r == 1,g == 2,b == 3), 0 if convention or format is incorrect
     */
    static unsigned char checkPath(const std::string &);

    /**
     * brief checks if path convention of image is correct
     * @param[in] imgPath : path of the image to analyze
     * @return 1 if image is "red", 2 if "green", 3 if "blue", 0 if convention is not respected
     */
    static unsigned char convention(const std::string &);

    /**
     * @brief checks if image is bmp, jpg or png
     * @param[in] imgPath : path of the image to analyze
     * @return true if it is, false if not
     */
    static bool format(const std::string &);

    /**
     * @brief loads image onto sf::Image structure
     * @param[in] imgPath : the path of the image to load
     * @param[in] img : the image
     * @return true if everything went well, false if not
     */
    static bool loadImage(const std::string &, sf::Image &);

    /**
     * @brief gets size of image (width/height)
     * @param[in] the image to get the size from
     * @param[in] x : the width of the image
     * @param[in] y : the height of the image
     */
    static void getSize(const sf::Image &, unsigned &, unsigned &);

    /**
     * @brief checks if image has any abnormal pixels
     * @param[in] img : the image to check the pixel
     * @param[in] x : the width of the image
     * @param[in] y : the height of the image
     * @param[in] n : the path convention unsigned char associated value
     * @param[in] imgPath : the image path
     * @return true if all the pixels in image are all in-bounds, false if not
     */
    static bool checkImage(const sf::Image &, unsigned &, unsigned &, const unsigned, const std::string &);

    /**
     * @brief call checkPixel
     * @param[in] col : the sf::Color structure which stocks r,g,b values of a single pixel
     * @param[in] n : the path convention unsigned char associated value
     * @return true if pixel is not abnormal, false if not
     */
    static bool checkPixel(const sf::Color, const unsigned);

    /**
     * @brief checks if pixel is of abnormal color, given an offset to compensate for picture quality
     * @param[in] R : the red value of pixel
     * @param[in] G : the red value of pixel
     * @param[in] B : the red value of pixel
     * @param[in] n : the path convention unsigned char associated value
     * @return true if in boundaries, false if not
     */
    static bool inBound(const unsigned, const unsigned, const unsigned, const unsigned);

    /**
     * @brief writes in file if pixel is of abnormal color (the r,b,g values) + position(x,y), opens text file if first time write
     * @param[in] col : the sf::Color structure which stocks r,g,b values of a single pixel
     * @param[in] x : the x axis position of the abnormal pixel
     * @param[in] y : the y axis position of the abnormal pixel
     * @param[in] imgPath : the path of image *
     * @param[in] last : if pixel is the last (x == max and y == max) then close text file
     */
    static void wrongPixel(const sf::Color, const unsigned, const unsigned, const std::string &, const bool);

    /**
     * @brief will create a csv file in "res/" with all the wrong pixel (see "wrongPixel" procedure)
     * @param[in] imgPath : image path
     * @return the ofstream to write in file
     */
    static std::ofstream openFile(const std::string & imgPath);
};

#endif //DEADPIXELFINDER_COLORSFML_H

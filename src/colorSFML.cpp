#include "colorSFML.h"

void colorSFML::manager(const std::string & imgPath){
    unsigned n = int(checkPath(imgPath));
    if(n != 0){
        sf::Image img;
        unsigned x,y;
        if(loadImage(imgPath, img)) {
            getSize(img, x, y);
            if(checkImage(img,x,y,n,imgPath))
                std::cout<<"fine ";
            else
                std::cout<<"not fine ";
        }
    }
    else{
        std::cout<<"Path convention or format is not supported"<<std::endl;
    }
}

unsigned char colorSFML::checkPath(const std::string & imgPath) {
    unsigned c = int(convention(imgPath));
    if(format(imgPath) && c != 0)
        return c;
    else
        return 0;
}

unsigned char colorSFML::convention(const std::string & imgPath){
    unsigned pos = imgPath.find_last_of("/") + 1;
    if(imgPath[pos] == 'r')
        return 1;
    if(imgPath[pos] == 'g')
        return 2;
    if(imgPath[pos] == 'b')
        return 3;
    else
        return 0;
}

bool colorSFML::format(const std::string & imgPath) {
    std::string imgFormat = imgPath.substr(imgPath.find(".") + 1);
    std::vector<std::string> format;
    format.push_back("bmp");
    format.push_back("png");
    format.push_back("jpg");
    if(imgFormat.compare(format.at(0)) != 0 && imgFormat.compare(format.at(1)) != 0 && imgFormat.compare(format.at(2)) != 0)
        return false;
    return true;
}

bool colorSFML::loadImage(const std::string & imgPath, sf::Image & img){
    if(img.loadFromFile(imgPath))
        return true;
    else
        return false;
}

void colorSFML::getSize(const sf::Image & img, unsigned & x, unsigned & y) {
    sf::Vector2u size(img.getSize());
    x = size.x;
    y = size.y;
}

bool colorSFML::checkImage(const sf::Image & img, unsigned int & x, unsigned int & y, const unsigned n, const std::string & imgPath) {
    bool imgGood = true;

    for(unsigned i=0;i<x;++i){
        for(unsigned j=0;j<y;++j){
            sf::Color col = img.getPixel(i,j);
            if(!checkPixel(col,n)){
                if(i != j)
                    wrongPixel(col,i,j,imgPath,false);
                else
                    wrongPixel(col,i,j,imgPath,true);
                imgGood = false;
            }
        }
    }
    return imgGood;
}

bool colorSFML::checkPixel(const sf::Color col, const unsigned n) {
    unsigned R,G,B;
    R = col.r;
    G = col.g;
    B = col.b;
    if(inBound(R,G,B,n))
        return true;
    return false;
}

bool colorSFML::inBound(const unsigned R, const unsigned G, const unsigned B, const unsigned n) {
    unsigned offsetValue = 50;
    unsigned r,g,b;

    switch(n) {
        case 1:
            r = 255, g = 0, b = 0;
            if (R >= r - offsetValue && G <= g + offsetValue && B <= b + offsetValue)
                return true;
            else
                return false;
        case 2:
            r=0,g=255,b=0;
            if(R <= r+offsetValue && G >= g-offsetValue && B <= b+offsetValue)
                return true;
            else
                return false;
        case 3:
            r=0,g=0,b=255;
            if(R <= r+offsetValue && G <= g+offsetValue && B >= b-offsetValue)
                return true;
            else
                return false;
        default:
            return false;
    }
    return false;
}

void colorSFML::wrongPixel(const sf::Color col, const unsigned x, const unsigned y, const std::string & imgPath, const bool last) {
    bool open = false;
    std::ofstream textFile;
    if(!open) {
        textFile = openFile(imgPath);
        open = true;
    }
    textFile << x << "," << y << "," << int(col.r) << "," << int(col.g) << "," << int(col.b) <<"\n";
    if(last)
        textFile.close();
}

std::ofstream colorSFML::openFile(const std::string & imgPath) {
    std::string imgPathForText = imgPath;

    size_t pos = imgPathForText.find_last_of("/") + 1;
    imgPathForText.erase(0, pos);
    pos = imgPathForText.find_last_of(".");
    imgPathForText.erase(pos, imgPathForText.length());
    std::cout<<imgPathForText<<std::endl;

    std::string textFileName = "res/" + imgPathForText + ".csv";
    std::cout<<textFileName<<std::endl;

    std::ofstream textFile(textFileName, std::ios::app);
    return textFile;
}



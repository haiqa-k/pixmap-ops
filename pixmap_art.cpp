#include "ppm_image.h"
#include <iostream>

using namespace std;
using namespace agl;

int main(int argc, char** argv)
{
    ppm_image image;
    image.load("../images/star.ppm");
    image.save("star.ppm");
    cout << "loaded star image: " << image.width() << " " << image.height() << endl;
   
    ppm_image grayscale = image.grayscale(); 
    grayscale.save("star-grayscale.ppm");

    ppm_image flip = image.flip_horizontal(); 
    flip.save("star-flip.ppm");

    ppm_image invert = image.invert();
    invert.save("star-inverted.ppm");

    //swirl color
    ppm_image swirl = image.swirl();
    swirl.save("star-swirl.ppm");

    //lightest extract
    ppm_image lightest = image.lightest(invert);
    lightest.save("star-lightest.ppm");

    //darkest extract
    ppm_image darkest = image.darkest(invert);
    darkest.save("star-darkest.ppm");

    //channel shift
    ppm_image channelShift = image.channelShift();
    channelShift.save("star-channelShift.ppm");

    //blue extract
    ppm_image blueExtract = image.blueExtract();
    blueExtract.save("star-blueExtract.ppm");

    ppm_image blueExtract2 = lightest.blueExtract();
    blueExtract2.save("star-blueExtract-Lightest.ppm");

    ppm_image channelShift2 = blueExtract2.channelShift();
    channelShift2.save("star-channelShift-BlueExtract-Lightest.ppm");

    ppm_image channelShift3 = flip.channelShift();
    channelShift3.save("star-channelShift-flip.ppm");

    ppm_image invert2 = channelShift3.invert();
    invert2.save("star-invert-channelShift-flip.ppm");


    
}


#include <iostream>
#include "ppm_image.h"
using namespace std;
using namespace agl;

int main(int argc, char** argv)
{
   ppm_image image;
 /**  ppm_image image;
   image.load("../images/feep.ppm");
   image.save("feep-test-save.ppm"); // should match original
   
   // should print 4 4
   cout << "loaded feep: " << image.width() << " " << image.height() << endl;

   // test: copy constructor
   ppm_image copy = image; 
   copy.save("feep-test-copy.ppm"); // should match original and load into gimp

   // test: assignment operator
   copy = image; 
   copy.save("feep-test-assignment.ppm"); // should match original and load into gimp

   // should print r,g,b
   ppm_pixel pixel = image.get(1, 1);
   cout << (int) pixel.r << " " << (int) pixel.g << " " << (int) pixel.b << endl;

   // test: setting a color
   pixel.r = 255;
   image.set(1, 1, pixel);
   image.save("feep-test-newcolor.ppm");
*/


   // test a non-trivial image
   image.load("../images/earth-ascii.ppm"); // a real image

   // should print 400 400
   cout << "loaded earth: " << image.width() << " " << image.height() << endl;

   // resize
   ppm_image resize = image.resize(200,300);
   resize.save("earth-200-300.ppm");

   // grayscale
   ppm_image grayscale = image.grayscale(); 
   grayscale.save("earth-grayscale.ppm");

   // flip horizontal
   ppm_image flip = image.flip_horizontal(); 
   flip.save("earth-flip.ppm"); 

   // sub image
   ppm_image sub = image.subimage(200, 200, 100, 100); 
   sub.save("earth-subimage.ppm"); 

   // gamma correction
   ppm_image gamma = image.gammaCorrect(0.6f); 
   gamma.save("earth-gamma-0.6.ppm"); 

   gamma = image.gammaCorrect(2.2f);
   gamma.save("earth-gamma-2.2.ppm"); 

   // alpha blend
   ppm_image soup;
   soup.load("../images/soup-ascii.ppm");

   //inverted image
   ppm_image invert = image.invert();
   invert.save("earth-inverted.ppm");

   //swirl color
   ppm_image swirl = image.swirl();
   swirl.save("earth-swirl.ppm");

   //lightest extract
   ppm_image lightest = image.lightest(invert);
   lightest.save("earth-lightest.ppm");

   //darkest extract
   ppm_image darkest = image.darkest(invert);
   darkest.save("earth-darkest.ppm");

   //channel shift
   ppm_image channelShift = image.channelShift();
   channelShift.save("earth-channelShift.ppm");

   //blue extract
   ppm_image blueExtract = image.blueExtract();
   blueExtract.save("earth-blueExtract.ppm");

   ppm_image blueExtract2 = invert.blueExtract();
   blueExtract2.save("earth-blueExtract-Inverted.ppm");

   ppm_image channelShift2 = blueExtract2.channelShift();
   channelShift2.save("earth-ChannelShift-BlueExtract-Invert.ppm");


   int y = (int) (0.5f * (image.width() - soup.width()));
   int x = (int) (0.5f * (image.height() - soup.height()));
   ppm_image background = image.subimage(x, y, soup.width(), soup.height());
   background.save("background-test.ppm");
   ppm_image blend = background.alpha_blend(soup, 0.5f);
   image.replace(blend, x, y);
   image.save("earth-blend-0.5.ppm");

   

}


//----------------------------------------
// PPM image class
// Author: Bryn Mawr College Basecode 2021
//----------------------------------------

#pragma once
#include <string>

namespace agl
{
  struct ppm_pixel
  {
     unsigned char r;
     unsigned char g;
     unsigned char b;
  };

  class ppm_image
  {
   protected:
      int ht = 0; //number of rows
      int wd = 0; //number of columns
      ppm_pixel **image_A = NULL; //2D array pointer
      void clear();

  public:
     ppm_image(); //default constructor
     ppm_image(int width, int height); //constructor
     ppm_image(const ppm_image& orig); //copy constructor
     ppm_image& operator=(const ppm_image& orig); //assignment operator

     virtual ~ppm_image(); //destructor

     

     // load the given filename
     // returns true if the load is successful; false otherwise
     bool load(const std::string& filename);

     // save the given filename
     // returns true if the save is successful; false otherwise
     bool save(const std::string& filename) const;

     // Returns a copy of this image resized to the given width and height
     ppm_image resize(int width, int height) const;

     // Return a copy of this image flipped around the horizontal midline
     ppm_image flip_horizontal() const;

     // Return a sub-image having the given top,left coordinate and (width, height)
     ppm_image subimage(int x, int y, int w, int h) const;

     // Replace the portion starting at (row, col) with the given image
     // Clamps the image if it doesn't fit on this image
     void replace(const ppm_image& image, int x, int y);

     // Return a copy of this image with the given gamma correction applied to it
     ppm_image gammaCorrect(float gamma) const;

     // Apply the following calculation to the pixels in 
     // our image and the given image:
     //    this.pixels = this.pixels * (1-alpha) + other.pixel * alpha
     // Can assume that the two images are the same size
     ppm_image alpha_blend(const ppm_image& other, float amount) const;

     // Return a copy of this image converted to grayscale
     ppm_image grayscale() const;

     //inverts the image
     ppm_image invert() const;

     //swirl
     ppm_image swirl() const;

     //ppm lightest
     ppm_image lightest(const ppm_image& other) const;

     //ppm darkest 
     ppm_image darkest(const ppm_image& other) const;

     //channel shift
     ppm_image channelShift() const;

     //blue extract
     ppm_image blueExtract() const;

     // Get the pixel at index (row, col)
     ppm_pixel get(int row, int col) const;

     // Set the pixel at index (row, col)
     void set(int row, int col, const ppm_pixel& c);

     // return the width of this image
     int width() const;

     // return the height of the image
     int height() const;

     
  };
}

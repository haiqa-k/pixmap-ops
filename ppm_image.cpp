#include "ppm_image.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <math.h>

#define FORMAT "P3";
#define MAX_VAL 255;
using namespace agl;
using namespace std;

ppm_image::ppm_image() 
{
   wd = 0;
   ht = 0;

}

ppm_image::ppm_image(int w, int h) 
{
   wd = w;
   ht = h;
   image = new ppm_pixel*[ht];
   for (int i = 0; i<ht; i++){
      image[i] = new ppm_pixel[wd];
   }
}

ppm_image::ppm_image(const ppm_image& orig) 
{
   clear();
   wd = orig.wd;
   ht = orig.ht;
   image = new ppm_pixel*[ht];
   
   for(int i = 0; i < ht; i++){
      image[i] = new ppm_pixel[wd];
      for(int j = 0; j< wd; j++){
         image[i][j] = orig.image[i][j];
      }
   }
}

ppm_image& ppm_image::operator=(const ppm_image& orig)
{
   if (&orig == this) // protect against self-assignment
   {
      return *this;
   }

   clear();
   wd = orig.wd;
   ht = orig.ht;
   image = new ppm_pixel*[ht];
   for(int i = 0; i<ht; i++){
      image[i] = new ppm_pixel[wd];
      for(int j = 0; j< wd; j++){
         image[i][j] = orig.image[i][j];
      }
   }

   return *this;   
}

ppm_image::~ppm_image()
{
   clear();
}

void ppm_image::clear()
{
   for(int i = 0; i < ht; i++){
      delete[] image[i];
   }
   delete[] image;
   image = NULL;
}

bool ppm_image::load(const std::string& filename)
{
   clear();
   int nameLength = filename.length();
   if(!(4 < nameLength && filename.substr(nameLength-4) == std::string(".ppm"))){
      cout << "Error: Input file is not a ppm file: " << filename << endl << std::endl;
      return false;
   }
   clear();
   ifstream file(filename); 

   if (!file){
      cout << "Error: unable to open file: " << filename << endl << std::endl;
      return false;
   }
   string format, max;
   file >> format >> wd >> ht >> max;
   image = new ppm_pixel*[ht];
   for(int i = 0; i<ht; i++){
      image[i] = new ppm_pixel[wd];
   }
   int red, green, blue;


   for(int i = 0; i< ht; i++){
      for(int j = 0; j<wd; j++){
         file >> red >> green >> blue;
         image[i][j].r = (unsigned char) red;
         image[i][j].g = (unsigned char) green;
         image[i][j].b = (unsigned char) blue;
      }
   }

   file.close();

   return false;
}

bool ppm_image::save(const std::string& filename) const
{
   int nameLength = filename.length();
   if(!(4 < nameLength && filename.substr(nameLength-4) == std::string(".ppm"))){
      cout << "Error: Input file is not a ppm file: " << filename << endl;
      return false;
   }
   ofstream file(filename);
   if (!file){
      cout << "Error: unable to open file: " << filename << endl;
      return false;
   }
   string format;
   int max=0;
   file << format << endl;
   file << wd << " ";
   file << ht << endl;
   file << max << endl;

   for(int i = 0; i<ht; i++){
      for(int j = 0; j< wd; j++){
         file << (int) image[i][j].r << " " << (int) image[i][j].g << " " << (int) image[i][j].b << std::endl;
      }
   }

   file.close();
   return true;
}

 ppm_image ppm_image::resize(int w, int h) const
{
    int prev_ht;
    int prev_wd;
    ppm_image result = ppm_image(w,h);
    for(int i = 0; i<h; i++){
       for(int j = 0; j<w; j++){
          prev_ht = floor((((double)i)/(h-1))*(ht-1));
          prev_wd = floor((((double)j)/(w-1))*(wd-1));
          result.image[i][j] = image[prev_ht][prev_wd];
       }
    }
    return result;
}

ppm_image ppm_image::flip_horizontal() const
{
    ppm_image result = ppm_image(wd, ht);
    for(int i = 0; i<ht; i++){
       for(int j = 0; j<wd; j++){
          result.image[i][j] = image[(ht -1)-i][j];
          result.image[(ht-1)-i][j] = image[i][j];
       }
    }
    return result;
}

ppm_image ppm_image::subimage(int startx, int starty, int w, int h) const
{
    ppm_image result = ppm_image(wd, ht);
    int x = 0;
    int y = 0;
    for(int i = startx; i<(startx + h); i++){
       for(int j = starty; j <( starty + w); j++){
          result.image[x][y] = image[i][j];
          y++;
       }
       y = 0;
       x++;
    }
    return result;
}

void ppm_image::replace(const ppm_image& image, int startx, int starty)
{
   for(int i = starty; i < starty+image.ht; i++){
      for(int j = startx; j < startx + image.wd; j++){
         image[i][j] = image.image[i-startx][j - startx];
      }
   }
}

ppm_image ppm_image::alpha_blend(const ppm_image& other, float alpha) const
{
   ppm_image result(wd, ht);
   unsigned char red, green, blue;
   for(int i = 0; i<ht; i++){
      for(int j = 0; j < wd; j ++){
         red = image[i][j].r * alpha + other.image[i][j].r *(1-alpha);
         green = image[i][j].g * alpha + other.image[i][j].g *(1-alpha);
         blue = image[i][j].b * alpha + other.image[i][j].b *(1-alpha);
         result.image[i][j] = ppm_pixel {red, green, blue};
      }
   }
   return result;
}

ppm_image ppm_image::gammaCorrect(float gamma) const
{
   ppm_image result(wd, ht); 
   for(int i = 0; i<ht; i++){
      for (int j = 0; j< wd; j++){
         result.image[i][j].r = (unsigned char)255*pow((float)image[i][j].r/255.0, 1.0/gamma);
         result.image[i][j].g = (unsigned char)255*pow((float)image[i][j].g/255.0, 1.0/gamma);
         result.image[i][j].b = (unsigned char)255*pow((float)image[i][j].b/255.0, 1.0/gamma);
      }
   }
   return result;
}

ppm_image ppm_image::grayscale() const
{
   ppm_image result = ppm_image (wd, ht);
   unsigned char pix_color;
   for(int i = 0; i<ht; i++){
      for(int j = 0; j< wd; j++){
         pix_color = (0.3*image[i][j].r) + (0.59*image[i][j].g) + (0.11*image[i][j].b);
         result.image[i][j] = ppm_pixel {pix_color, pix_color, pix_color};
         
      }
   }
 
   return result;
}

ppm_pixel ppm_image::get(int row, int col) const
{
   unsigned char r, g, b;
   for (int i = 0; i <ht; i++){
      for (int j = 0 ; j < wd; j++){
         if (i == row && j == col) {
            r = image[i][j].r;
            b = image[i][j].g;
            g = image[i][j].b;
            
         }
      }
   }
   return ppm_pixel{r, g, b};
}

void ppm_image::set(int row, int col, const ppm_pixel& c)
{
   for(int i = 0; i < ht; i ++){
      for (int j = 0; j< wd; j++){
         if( i == row && j == col){
            image[i][j] = c;
         }
      }  
   }
}

int ppm_image::height() const
{
   return ht;
}

int ppm_image::width() const
{
   return wd;
}

ppm_image ppm_image::invert() const {
   unsigned char red, green, blue;
   ppm_image result(wd, ht);
   for (int i = 0; i < ht; i++){
      for (int j = 0; j< wd; j++){
         red = 255 - image[i][j].r;
         green = 255 - image[i][j].g;
         blue = 255 - image[i][j].b;
         result.image[i][j] = ppm_pixel{red,green,blue};
      }
   }
   return result;
}
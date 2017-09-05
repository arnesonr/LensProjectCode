struct pgm {
  int width;    //Number of pixels in the width
  int height;   //Number of pixels in the height
  int max;
  int* pix;
};
struct pgm pgmread(FILE *fptr);
int pgmprint(struct pgm img,FILE *fptr);
struct pgm optcontrast(struct pgm img,int range);
struct pgm copy(struct pgm img);
struct pgm invert(struct pgm img);

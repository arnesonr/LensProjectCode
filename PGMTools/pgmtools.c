//======================================================================
//======================================================================
struct pgm pgmread(FILE *fptr) {
  //Read a pgm file from the specified stream
  struct pgm rtn;
  char buff[5];
  fscanf(fptr,"%s",buff);
  fscanf(fptr,"%d",&(rtn.width));
  fscanf(fptr,"%d",&(rtn.height));
  fscanf(fptr,"%d",&(rtn.max));
  int p=rtn.width*rtn.height;
  rtn.pix = new int [p];
  for(int i=0;i<p;i++) {
    fscanf(fptr,"%d",&(rtn.pix[i]));
  }
  return rtn;
}
//======================================================================
//======================================================================
int pgmprint(struct pgm img,FILE *fptr){
  //Write a pgm file to the specified stream
  fprintf(fptr,"P2\n");
  fprintf(fptr,"%d %d\n",img.width,img.height);
  fprintf(fptr,"%d\n",img.max);
  int p=img.width*img.height;
  for(int i=0;i<p;i++) {
    fprintf(fptr,"%d\n",img.pix[i]);
  }

  return 0;
}
//======================================================================
//======================================================================
struct pgm optcontrast(struct pgm img, int range){
  //Stretch the image dynamic range [min,max] to the interval [0,range] 
  struct pgm rtn;
  //Set new image parameters
  rtn.width=img.width;
  rtn.height=img.height;
  rtn.max=range;
  int p=img.width*img.height;
  rtn.pix = new int [p];

  //Search for min and max
  int min=img.pix[0];
  int max=img.pix[0];
  for(int i=1;i<p;i++) {
    if(img.pix[i]>max) max=img.pix[i];
    if(img.pix[i]<min) min=img.pix[i];
  }

  //Set pixel values
  float spix;
  for(int i=0;i<p;i++) {
    spix=range*(img.pix[i]-min)/(max-min);
    rtn.pix[i]=(int)floor(spix);
 }

  return rtn;
}
//======================================================================
//======================================================================
struct pgm copy(struct pgm img){
  //produce a copy of the image
  struct pgm rtn;
  //Set new image parameters
  rtn.width=img.width;
  rtn.height=img.height;
  rtn.max=img.max;
  int p=img.width*img.height;
  rtn.pix = new int [p];
  //Copy the pixel values
  for(int i=0;i<p;i++) {
    rtn.pix[i]=img.pix[i];
  }
  return rtn;
}
//======================================================================
//======================================================================
struct pgm invert(struct pgm img){
  //produce an inverted (negative) version of the image
  struct pgm rtn;
  //Set new image parameters
  rtn.width=img.width;
  rtn.height=img.height;
  rtn.max=img.max;
  int p=img.width*img.height;
  rtn.pix = new int [p];
  //Copy the pixel values
  for(int i=0;i<p;i++) {
    rtn.pix[i]=rtn.max-img.pix[i];
  }
  return rtn;
}
//======================================================================
//======================================================================

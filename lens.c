#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "./PGMTools/pgmtools.h"
#include "./PGMTools/pgmtools.c"
#include <iostream.h>
#include <fstream.h>
#define DIMS 250

void quit();

int main(int nbargs, char* args[]){
  //make sure an argument is provided
  if (nbargs!=2) {
    std::cout << "You need to indicate an output file name.\n";
    quit();
  }
  //Define the filename
  char filename[20];
  strcpy(filename,args[1]);
  //Begin program
  std::cout << "***STRONG GRAVITATIONAL LENSING***\n";
  std::cout << "A program to compute the image of a galaxy warpped by gravity!\n";
  std::cout << "You may quit at any time by entering: q\n";
  //ask how many lens galaxies to consider
  int n_gals;
  float input=0;
  std::cout << "How many lens galaxies do you want to consider (1-3)?\n";

  while (scanf("%f", &input) != 1)
  {
    if (getchar() == 'q') quit();
    while (getchar() != '\n');
    printf ("Try again.  How many lens galaxies do you want to consider (1-3)?");
  }
  n_gals = (int)floor(input);
  if (input > 5){
    std::cout << "You may only consider a maximum of 3 galaxies.  Number of galaxies set to 3.\n";
    n_gals = 3;
  }
  if (input < 1) {
    std::cout << "You must consider at least 1 galaxy.  Number of galaxies set to 1.\n";
    n_gals = 1;
  }
  //get the parameters for the galaxies
  //define parameters
  float b[n_gals];
  float ql[n_gals];
  float PAl[n_gals];
  int xcen[n_gals];
  int ycen[n_gals];
  for (int i=0;i<n_gals;i++){
    //get Einstein radii
    std::cout << "Enter the Einstein radius, b, (0-100) of galaxy "<< i+1 << "\n";
    while (scanf("%f", &b[i]) != 1)
      {
	if (getchar() == 'q') quit();
	while (getchar() != '\n');
	printf ("Try again:");
      }
    if (b[i] > 100.){
      std::cout << "You may only consider a maximum Einstein radius of 100.   Einstein radius set to 100.\n";
      b[i] = 100.0;
    }
    if (b[i] < 0) {
      std::cout << "You may only consider a minimum Einstein radius of 0.   Einstein radius set to 0.\n";
      b[i]=0.0;
    }
    //get x positions
    float xinput;
    std::cout << "Enter the x position (-100 to 100) of galaxy "<< i+1 << "\n";
    while (scanf("%f", &xinput) != 1)
      {
	if (getchar() == 'q') quit();
	while (getchar() != '\n');
	printf ("Try again:");
      }
    if (xinput > 100. || xinput < -100.){
      std::cout << "You may only consider a galaxy between [-100, 100].   X position set to 0.\n";
      xcen[i] = 0;
    }
    xcen[i] = (int)floor(xinput);
    //get y positions
    float yinput;
    std::cout << "Enter the y position (-100 to 100) of galaxy "<< i+1 << "\n";
    while (scanf("%f", &yinput) != 1)
      {
	if (getchar() == 'q') quit();
	while (getchar() != '\n');
	printf ("Try again:");
      }
    if (yinput > 100. || yinput < -100.){
      std::cout << "You may only consider a galaxy between [-100, 100].   y position set to 0.\n";
      ycen[i] = 0;
    }
    ycen[i] = (int)floor(yinput);
    //get axis ratios
    std::cout << "Enter the axis ratio (0.0-1.0) of lens galaxy "<< i+1 << "\n";
    while (scanf("%f", &ql[i]) != 1)
      {
	if (getchar() == 'q') quit();
	while (getchar() != '\n');
	printf ("Try again:");
      }
    if (ql[i] > 1.0 || ql[i] < 0.0){
      std::cout << "The axis ratio range is (0.0-1.0).  Axis ratio set to 1.\n";
      ql[i] = 1.0;
    }
    //get position angles
    std::cout << "Enter the position angle (degrees c.c.w from x axis) of galaxy "<< i+1 << "\n";
    while (scanf("%f", &PAl[i]) != 1)
      {
	if (getchar() == 'q') quit();
	while (getchar() != '\n');
	printf ("Try again:");
      }
    if (PAl[i] > 360.0){
      std::cout << "The maximum postion angle is 360.  Position angle set to 0.\n";
      PAl[i] = 0.0;
    }
    if (PAl[i] < 0.0) {
      std::cout << "The minimum positon angle is 0.  Axis ratio set to 0.\n";
      PAl[i]=0.0;
    }
  }
  for(int i=0;i<n_gals;i++){
    fprintf(stdout,"The parameters for galaxy %d are:\n b:%f, x:%d, y:%d, q:%f, PA:%f\n", i+1,b[i],xcen[i],ycen[i],ql[i],PAl[i]);
  }
  //Ask for number of sources
  int n_sources;
  float inputs;
  std::cout << "How many source galaxies do you want to consider (1-3)?\n";

  while (scanf("%f", &inputs) != 1)
  {
    if (getchar() == 'q') quit();
    while (getchar() != '\n');
    printf ("Try again.  How many source galaxies do you want to consider (1-3)?");
  }
  n_sources = (int)floor(inputs);
  if (inputs > 3){
    std::cout << "You may only consider a maximum of 3 galaxies.  Number of source galaxies set to 3.\n";
    n_sources = 3;
  }
  if (inputs < 1) {
    std::cout << "You must consider at least one source galaxy. Number of source galaxies is 1.\n";
    n_sources = 1;
  }
  //Get source parameters
  //define parameters
  float amp[n_sources];
  float sigma[n_sources];
  float PAs[n_sources];
  float qs[n_sources];
  int xcens[n_sources];
  int ycens[n_sources];
  for (int i=0;i<n_sources;i++){
    //get amplitudes
    std::cout << "Enter the amplitude (i.e. brightness) (0-100) of source galaxy "<< i+1 << "\n";
    while (scanf("%f", &amp[i]) != 1)
      {
	if (getchar() == 'q') quit();
	while (getchar() != '\n');
	printf ("Try again:");
      }
    if (amp[i] > 100.){
      std::cout << "You may only consider a maximum amplitude of 100.   Amplitude set to 100.\n";
      amp[i] = 100.0;
    }
    if (amp[i] < 0) {
      std::cout << "You may only consider a minimum amplitude of 0.   Amplitude set to 0.\n";
      amp[i]=0.0;
    }
    //get sigmas
    std::cout << "Enter the radius (0-100) of source galaxy "<< i+1 << "\n";
    while (scanf("%f", &sigma[i]) != 1)
      {
	if (getchar() == 'q') quit();
	while (getchar() != '\n');
	printf ("Try again:");
      }
    if (sigma[i] > 100.){
      std::cout << "You may only consider a maximum radius of 100.   Radius set to 100.\n";
      sigma[i] = 100.0;
    }
    if (sigma[i] < 0) {
      std::cout << "You may only consider a minimum radius of 0.   Radius set to 0.\n";
      sigma[i]=0.0;
    }
    //get x positions
    float xinputs;
    std::cout << "Enter the x position (-100 to 100) of source galaxy "<< i+1 << "\n";
    while (scanf("%f", &xinputs) != 1)
      {
	if (getchar() == 'q') quit();
	while (getchar() != '\n');
	printf ("Try again:");
      }
    if (xinputs > 100. || xinputs < -100.){
      std::cout << "You may only consider a galaxy between [-100, 100].   X position set to 0.\n";
      xcens[i] = 0;
    }
    xcens[i] = (int)floor(xinputs);
    //get y positions
    float yinputs;
    std::cout << "Enter the y position (-100 to 100) of source galaxy "<< i+1 << "\n";
    while (scanf("%f", &yinputs) != 1)
      {
	if (getchar() == 'q') quit();
	while (getchar() != '\n');
	printf ("Try again:");
      }
    if (yinputs > 100. || yinputs < -100.){
      std::cout << "You may only consider a galaxy between [-100, 100].   y position set to 0.\n";
      ycens[i] = 0;
    }
    ycens[i] = (int)floor(yinputs);
    //get axis ratios
    std::cout << "Enter the axis ratio (0.0-1.0) of source galaxy "<< i+1 << "\n";
    while (scanf("%f", &qs[i]) != 1)
      {
	if (getchar() == 'q') quit();
	while (getchar() != '\n');
	printf ("Try again:");
      }
    if (qs[i] > 1.0 || qs[i] < 0.0){
      std::cout << "The axis ratio range is (0.0-1.0).  Axis ratio set to 1.\n";
      qs[i] = 1.0;
    }
    //get position angles
    std::cout << "Enter the position angle (degrees c.c.w from x axis) of source galaxy "<< i+1 << "\n";
    while (scanf("%f", &PAs[i]) != 1)
      {
	if (getchar() == 'q') quit();
	while (getchar() != '\n');
	printf ("Try again:");
      }
    if (PAs[i] > 360.0){
      std::cout << "The maximum postion angle is 360.  Position angle set to 0.\n";
      PAs[i] = 0.0;
    }
    if (PAs[i] < 0.0) {
      std::cout << "The minimum positon angle is 0.  Axis ratio set to 0.\n";
      PAs[i]=0.0;
    }}
  float amp_sum;
  for(int i=0;i<n_sources;i++){
    fprintf(stdout,"The parameters for source galaxy %d are:\n amp:%f, radius:%f, x:%d, y:%d, q:%f, PA:%f\n", i+1,amp[i],sigma[i],xcens[i],ycens[i],qs[i],PAs[i]);
    amp_sum += amp[i];
  }
  //create xy grid
  int ximg[DIMS][DIMS];
  int yimg[DIMS][DIMS];
  //pixel [0][0] is at the top left of the image
  for(int i=0; i<DIMS; i++){
    for(int j=0; j<DIMS; j++){
      ximg[i][j]=(j-DIMS/2);
      yimg[i][j]=(DIMS/2-i);
    }}
  //calculate deflections due to each galaxy

  //set up the image structure
  struct pgm image;
  image.width=DIMS;
  image.height=DIMS;
  image.max = amp_sum;
  image.pix=new int[image.width * image.height];
  //define a limit for sqrt(1/q - q)
  float eps = 0.001;
  //initiallize deflection variables
  float r_ell[DIMS][DIMS][n_gals];
  float xg[DIMS][DIMS][n_gals];
  float yg[DIMS][DIMS][n_gals];
  float phirad[n_gals];
  float qfact[n_gals];
  for(int i=0;i<n_gals;i++){ 
    phirad[i] = (PAl[i]/180.0)*M_PI;
    qfact[i] = sqrt(1.0/ql[i] - ql[i]);
  }
  float xsie[DIMS][DIMS][n_gals];
  float ysie[DIMS][DIMS][n_gals];
  float xtg[DIMS][DIMS][n_gals];
  float ytg[DIMS][DIMS][n_gals];
  //loop over all lens galaxies
  for(int k=0;k<n_gals;k++){ 
    //Transform into shifted coordinats of the potential
    for(int i=0; i<DIMS; i++){
      for(int j=0; j<DIMS; j++){
	xsie[i][j][k] = (ximg[i][j]-xcen[k]) * cos(phirad[k]) + (yimg[i][j]-ycen[k]) * sin(phirad[k]);
	ysie[i][j][k] = (yimg[i][j]-ycen[k]) * cos(phirad[k]) - (ximg[i][j]-xcen[k]) * sin(phirad[k]);
    }}
    //calculate the radius at each pixel
    for(int i=0; i<DIMS; i++){
      for(int j=0; j<DIMS; j++){
	r_ell[i][j][k]=sqrt((ql[k]*pow(xsie[i][j][k],2))+(pow(ysie[i][j][k],2)/ql[k]));
	//keep r_ell==0 (i.e. sigularity) terms from being divided by zero
	if(r_ell[i][j][k]==0) r_ell[i][j][k]=1.0;
      }}
    //calculate the deflections
    if(qfact[k] >= eps){
      for(int i=0; i<DIMS; i++){
	for(int j=0; j<DIMS; j++){
	  xtg[i][j][k] = (b[k]/qfact[k]) * atan(qfact[k] * xsie[i][j][k]/r_ell[i][j][k]);
	  ytg[i][j][k] = (b[k]/qfact[k]) * atanh(qfact[k] * ysie[i][j][k]/r_ell[i][j][k]);
	}}}
    else{
      for(int i=0; i<DIMS; i++){
	for(int j=0; j<DIMS; j++){
	  xtg[i][j][k] = b[k] * xsie[i][j][k] / r_ell[i][j][k];
	  ytg[i][j][k] = b[k] * ysie[i][j][k] / r_ell[i][j][k];
	}}}
    //transform back to un-rotated system
    for(int i=0; i<DIMS; i++){
      for(int j=0; j<DIMS; j++){
	xg[i][j][k] = xtg[i][j][k] * cos(phirad[k]) - ytg[i][j][k] * sin(phirad[k]);
	yg[i][j][k] = ytg[i][j][k] * cos(phirad[k]) + xtg[i][j][k] * sin(phirad[k]);
      }}}
  //add up all the deflections
  float xg_tot[DIMS][DIMS];
  float yg_tot[DIMS][DIMS];
  for(int z=0; z<n_gals; z++){
    for(int i=0; i<DIMS; i++){
      for(int j=0; j<DIMS; j++){
	xg_tot[i][j] += xg[i][j][z];
	yg_tot[i][j] += yg[i][j][z];
    }}}
  //define parameters for source plane
  float psi[n_sources];
  float xnew[DIMS][DIMS][n_sources];
  float ynew[DIMS][DIMS][n_sources];
  //calculate the image of the sources through the potential
  for(int l=0;l<n_sources;l++){
    psi[l] = (PAs[l]/180.0)*M_PI;
    for(int i=0;i<DIMS;i++) {
      for(int j=0;j<DIMS;j++){
	xnew[i][j][l] = (ximg[i][j]-xcens[l]) * cos(psi[l]) + (yimg[i][j]-ycens[l]) * sin(psi[l]);
	ynew[i][j][l] = (yimg[i][j]-ycens[l]) * cos(psi[l]) - (ximg[i][j]-xcens[l]) * sin(psi[l]);
	float r = ((pow(xnew[i][j][l]-xg_tot[i][j],2)*qs[l]+pow(ynew[i][j][l]-yg_tot[i][j],2))/qs[l])/pow(sigma[l],2);
	float val = amp[l] * exp(-0.5 * r);
	image.pix[i*image.height+j]+=(int)floor(val);
      }}}
  //write the image to file
  //remove the given filename incase it already exists
  remove(filename);
  //make the file and write to it
  FILE *fptr;
  fptr = fopen(filename, "w");
  if(fptr ==NULL){
    fprintf(stderr, "Problem encountered while opening the file %s\n",filename);
    quit();
  }
  pgmprint(image,fptr);
  fclose(fptr);
  return (0);
}
//
//======================================================================
//
/*
  PURPOSE: To exit the main function
 */
void quit(){
  std::cout << "Goodbye!\n";
  exit(0);
}
//
//======================================================================
//

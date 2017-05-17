//http://cboard.cprogramming.com/c-programming/156813-histogram-equalization.html
main()
{   
    int i,j,k,l, lines, columns;
     
     
 
    unsigned char   *image_in[2048], *image_out[2048];
    int hist[256];
 
    char    inp_fn[30], 
            out_fn[30];
 
     
    FILE *inp, *out;
 
    printf ("Enter input file name : ");
    gets( inp_fn );
 
    printf ("Enter output file name : ");
    gets( out_fn );
 
    printf ("Enter no. of lines : ");
    scanf("%d", &lines);
 
    printf ("Enter no. of columns : ");
    scanf("%d", &columns);
 
    for  (i=0;i<lines;i++)
        image_in[i]=(unsigned char*)malloc((columns) * sizeof(unsigned char));
 
    for  (i=0;i<lines;i++)
        image_out[i]=(unsigned char*)malloc((columns) * sizeof(unsigned char));
 
    for(int i=0;i<256;i++)
            hist[i]=0;
     
     
    int pixels=lines*columns;
    printf("\nTotal pixels: %d",pixels);
/**********************READ IMAGE ****************************************************/
    if ( ((inp=fopen (inp_fn,"rb")) == NULL))
        printf ("Not a valid input file\n");
    else
    {
 
    for  (i=0;i<lines;i++)
        fread(image_in[i], sizeof(unsigned char), columns, inp);
 
    fclose(inp);
    }
//************************************************************************************/ 
   
  //                          original histogram
    for (i=0; i<lines; i++)
    {  for (j=0; j<columns; j++)
       {
              hist[image_in[i][j]]++;
       }
    }
     
    //                          Histogram stats
    // min max avg
     
    int hsum=0;
    float avg;
    int hmax=-1,hmin=257;
    for(int i=0;i<256;i++)
      {
         if (hist[i]>hmax)
         hmax=hist[i];
         if (hist[i]<hmin)
         hmin=hist[i];
      }
 
    for(int i=0;i<256;i++)
         hsum+=hist[i]*i;
         
        avg=(float)hsum/pixels;
        //                   Dispersion of data for original image (Standar Deviation)
    float cSum=0;
    float cTable[256];
    float avgDev=0;
    for(int i=0;i<256;i++)
    {
            cTable[i]=(abs((i-(int)avg)))*(abs((i-(int)avg)));
            cTable[i]=hist[i]*cTable[i];
            cSum+=cTable[i];
    }        
    cSum=cSum/pixels;
     
     
    avgDev=sqrt(cSum);
         
         
        printf("\nOriginal Histogram statistics");
        printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\nHistogram sum: %d \n Histogram Max: %d\n Histogram Min: %d \n Histogram Avg: %f \n Standar Deviation: %f",hsum,hmax,hmin,avg,avgDev);
  
//                                           Probability table
 
    float prt[256];
               for(int i=0;i<256;i++)
               prt[i]=(float)hist[i]/pixels;     
 
 
//                                 Cumulative Distribution Function
float cdfmax=-1,cdfmin=257;
float cdf[256];
cdf[0]=prt[0];
for(int i=1;i<256;i++)
{
        cdf[i]=prt[i]+cdf[i-1];
        if(cdf[i]>cdfmax)
        cdfmax=cdf[i];
        if(cdf[i]<cdfmin)
        cdfmin=cdf[i];
}
 
//                                            Final Image
for (int i=0;i<lines;i++)
{
    for(int j=0;j<columns;j++)
    {
    image_out[i][j]=cdf[image_in[i][j]]*255;
    }
}
 
//                                       Equalized Histogram
int eHist[256];
for(int i=0;i<256;i++)
for(int j=0;j<256;j++)
eHist[image_out[i][j]]++;
 
//                                 Equalized Histogram stats
    int ehsum=0;
    float eavg;
    int ehmax=-1,ehmin=257;
    for(int i=0;i<256;i++)
      {
         if (eHist[i]>ehmax)
         ehmax=eHist[i];
         if (eHist[i]<ehmin)
         ehmin=eHist[i];
      }
 
    for(int i=0;i<256;i++)
            ehsum+=eHist[i]*i;
 
        eavg=(float)ehsum/pixels;
//                             Dispersion of data for Equalised Histogram  
    float ecSum=0;
    float ecTable[256];
    float eavgDev=0;
    for(int i=0;i<256;i++)
    {
            ecTable[i]=(abs((i-(int)eavg)))*(abs((i-(int)eavg)));
            ecTable[i]=eHist[i]*ecTable[i];
            ecSum+=ecTable[i];
    }        
    ecSum=ecSum/pixels;
     
     
    eavgDev=sqrt(ecSum);
     
         
         
         
         
         
        printf("\n\n Equalised Histogram statistics");
        printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\n EqHistogram sum: %d \n EqHistogram Max: %d \n EqHistogram Min: %d \n EqHistogram Avg: %f \n Standar Deviation: %f",ehsum,ehmax,ehmin,eavg,eavgDev);
     
 
 
 
 
 
 
 
//*********************WRITE IMAGE ****************************************************
    out=fopen (out_fn, "wb");
 
    for  (i=0;i<lines;i++)
        fwrite(image_out[i], sizeof(unsigned char), columns, out);
 
    fclose(out);
 
 
    for (i=0;i<lines;i++)
        free(image_in[i]);
    for (i=0;i<lines;i++)
        free(image_out[i]);
printf("\n");
system("pause");
}

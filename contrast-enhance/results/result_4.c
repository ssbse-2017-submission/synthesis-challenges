int main(int argc, char** argv){

    if(argc != 2){
        printf("Usage: %s image\n", argv[0]);
        exit(-1);
    }

    // read from the input bmp image file
    unsigned char* image = read_bmp(argv[1]);
    unsigned char* output_image = malloc(sizeof(unsigned char) * image_size);

    // create a histogram for the pixel values
    int* histogram = (int*)calloc(sizeof(int), color_depth);
    for(int i = 0; i < image_size; i++){
        histogram[image[i]]++;
    }

    // finding the normalised values using cumulative mass function
    float* transfer_function = (float*)calloc(sizeof(float), color_depth);
    for(int i = 0; i < color_depth; i++){
        for(int j = 0; j < i+1; j++){
            transfer_function[i] += color_depth*((float)histogram[j])/(image_size);
        }
    }


    for(int i = 0; i < image_size; i++){
        output_image[i] = transfer_function[image[i]];
    }

    // write data to output bmp image file
    write_bmp(output_image, image_width, image_height);
}
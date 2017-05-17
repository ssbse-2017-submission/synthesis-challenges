void equalize(unsigned char *data, int size) {
    
    int N = UCHAR_MAX + 1;

    unsigned long *buf = calloc(N, sizeof *buf);

    // Compute histogram buffer
    for(int i = 0; i < size; i++) {
        buf[data[i]] += 1;
    }

    // Scan buffer to compute cumulative distribution function (cdf)
    for(int i = 1; i < N; i++) {
        buf[i] += buf[i - 1];
    }

    // Determine minimum nonzero value of cdf
    int j = 0;
    while(buf[j] == 0) {
        j++;
    }
    
    int cdf_min = buf[j];

    // Equalize cdf over [0, 256)
    for(int i = 0; i < N; i++) {
        buf[i] = round((N - 1) * (buf[i] - cdf_min) / (size - cdf_min));
    }

    // Update data with equalized values
    for(int i = 0; i < size; i++) {
        data[i] = (unsigned char)buf[data[i]];
    }
    
    free(buf);

}

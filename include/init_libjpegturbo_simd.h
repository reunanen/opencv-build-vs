// Allow to explicitly initialize libjpeg-turbo SIMD usage, in order to avoid race conditions.
// (See this note: https://github.com/opencv/opencv/blob/06431655197b1cec869d3291436b0610dd15e1a7/3rdparty/libjpeg-turbo/src/simd/x86_64/jsimd.c#L41)

void init_libjpegturbo_simd();

// Allow to explicitly initialize libjpeg-turbo SIMD usage, in order to avoid race conditions.
// (See this note: https://github.com/opencv/opencv/blob/06431655197b1cec869d3291436b0610dd15e1a7/3rdparty/libjpeg-turbo/src/simd/x86_64/jsimd.c#L41)

#include <opencv2/imgcodecs.hpp>

void init_libjpegturbo_simd()
{
    const auto magicValue = 42;
    const cv::Mat mat1(1, 1, CV_8UC1, cv::Scalar(magicValue));
    std::vector<uchar> encoded;
    cv::imencode(".jpg", mat1, encoded);
    const cv::Mat mat2 = cv::imdecode(encoded, cv::IMREAD_UNCHANGED);
    if (mat2.at<unsigned char>(0, 0) != magicValue) {
        throw std::runtime_error("Problem encoding or decoding a simple JPEG image");
    }
}
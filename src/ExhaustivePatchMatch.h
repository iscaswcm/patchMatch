//
// Created by moser on 02.10.15.
//

#ifndef PATCHMATCH_EXHAUSTIVEPATCHMATCH_H
#define PATCHMATCH_EXHAUSTIVEPATCHMATCH_H

#include "opencv2/core/cuda.hpp"
#include "opencv2/cudaimgproc.hpp"
#include "opencv2/cudaarithm.hpp"

class ExhaustivePatchMatch {

public:
    ExhaustivePatchMatch(cv::Mat &img, cv::Mat &img2);
    cv::Mat match(int patchSize);

private:
    cv::cuda::GpuMat _img, _img2, _temp;
    cv::Ptr<cv::cuda::TemplateMatching> _cuda_matcher;

    void matchSinglePatch(cv::cuda::GpuMat &patch, double *minVal, cv::Point *minLoc);
};


#endif //PATCHMATCH_EXHAUSTIVEPATCHMATCH_H
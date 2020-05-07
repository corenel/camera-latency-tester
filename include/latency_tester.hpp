#pragma once

#include "opencv2/opencv.hpp"

namespace latency_tester {

class LatencyTester {
 public:
  LatencyTester();
  ~LatencyTester();

  void feed(const cv::Mat& frame);

 private:
  int threshold_ = 50;
  int im_width_ = 1280;
  int im_height_ = 720;
  int frame_number_ = 0;
  int prev_change_frame_ = 0;
  bool is_dark_ = true;
  int64 prev_tick_;
};

}  // namespace latency_tester

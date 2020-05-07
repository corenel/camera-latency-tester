#include "latency_tester.hpp"
#include "opencv2/opencv.hpp"

int main() {
  auto tester = latency_tester::LatencyTester();
  auto cap = cv::VideoCapture(0);
  if (!cap.isOpened()) {
    std::cerr << "***Could not initialize capturing...***\n";
    std::cerr << "Current parameter's value: \n";
    return -1;
  }

  cv::Mat frame;
  while (true) {
    cap >> frame;
    if (frame.empty()) {
      std::cerr << "frame is empty" << std::endl;
      continue;
    }
    // cv::imshow("Camera", frame);
    tester.feed(frame);
  }

  cap.release();
  return 0;
}

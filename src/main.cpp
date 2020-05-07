#include "latency_tester.hpp"
#include "opencv2/opencv.hpp"

int main() {
  auto cap = cv::VideoCapture(1);

  if (!cap.isOpened()) {
    std::cerr << "***Could not initialize capturing...***\n";
    std::cerr << "Current parameter's value: \n";
    return -1;
  }
  // auto tester = latency_tester::LatencyTester();
  cv::Mat frame;
  while (true) {
    cap >> frame;
    if (frame.empty()) {
      std::cerr << "frame is empty" << std::endl;
      break;
    }
    cv::imshow("Test", frame);
    cv::waitKey(1);
    // tester.feed(frame);
  }
  return 0;
}

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
    // 1. 강아지 영상 불러오기
    Mat img1 = imread("C:\\Users\\pizza\\Downloads\\dog.bmp", IMREAD_COLOR);
    if (img1.empty()) {
        cerr << "Image load failed!" << endl;
        return -1;
    }

    // 2. 그림판에서 구한 얼굴 좌표로 사각형(Rect) 만들기
    // Rect(x좌표, y좌표, 가로길이, 세로길이)
    // ※ 아래 숫자는 예시입니다. 그림판에서 찾은 숫자로 수정하세요!
    Rect face_rect(100, 100, 150, 150);

    // 3. 원본 이미지에서 얼굴 부분만 떼어내기 (부분 행렬 추출)
    // 얕은 복사 원리를 이용하기 때문에 face를 수정하면 img1도 바뀝니다.
    Mat face = img1(face_rect);

    // 4. 얼굴 부분을 파란색(BGR: 255, 0, 0)으로 칠하기
    face.setTo(Scalar(255, 0, 0));

    // 5. 결과 확인하기
    imshow("img1", img1); // 원본의 얼굴 부분이 파랗게 변한 것을 확인
    waitKey();

    return 0;
}
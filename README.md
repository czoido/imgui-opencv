## imgui - opencv

Just a simple demo to add opencv, imgui and poco libraries to a project using Conan.io
The program will download a picture from the Internet and apply a threshold to the image with the desired level through an slider.

![use](https://raw.githubusercontent.com/czoido/imgui-opencv/master/data/screen-capture.gif)

## How to use:

1. Install conan: https://docs.conan.io/en/latest/installation.html
2. Clone this repo: `git clone https://github.com/czoido/imgui-opencv.git`
3. `cd imgui-opencv`
4. `mkdir build && cd build`
5. `conan install ..`
6. `conan build ..`
7. `./bin/imgui-opencv`
8. You can use a custom url to load your image
9. Click 'Open' to open the image
10. Apply a threshold with the slider

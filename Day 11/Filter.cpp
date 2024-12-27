#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "./stb/stb_image.h"
#include "./stb/stb_image_write.h"

#include <iostream>
#include <vector>

using namespace std;

struct RGB {
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

class Filter {

public:
    Filter() {
        // default constructor
    }

    std::vector<std::vector<RGB>> createCanvas(int width, int height) {
        std::vector<std::vector<RGB>> canvas(height, std::vector<RGB>(width));
        for (int row = 0; row < height; row++) {
            for (int col = 0; col < width; col++) {
                canvas[row][col].r = 255;
                canvas[row][col].g = 255;
                canvas[row][col].b = 0;
            }
        }
        return canvas;
    }

    void saveToPNG(const std::vector<std::vector<RGB>>& imageData, int width, int height, const char* filename) {
        std::vector<unsigned char> imageFlat;
        imageFlat.reserve(width * height * 3);

        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                const RGB& color = imageData[i][j];
                imageFlat.push_back(color.r);  
                imageFlat.push_back(color.g);  
                imageFlat.push_back(color.b);  
            }
        }

        if (stbi_write_png(filename, width, height, 3, imageFlat.data(), width * 3)) {
            std::cout << "Image saved successfully to " << filename << std::endl;
        } else {
            std::cout << "Failed to save image!" << std::endl;
        }
    }

    std::vector<std::vector<RGB>> convertTo2D(const unsigned char* imageData, int width, int height) {
        std::vector<std::vector<RGB>> output;
        int length = width * height * 3;
        RGB color;

        for (int i = 0; i < height; ++i) {
            std::vector<RGB> row;
            for (int j = 0; j < width * 3; j += 3) {
                color.r = imageData[i * width * 3 + j + 0];
                color.g = imageData[i * width * 3 + j + 1];
                color.b = imageData[i * width * 3 + j + 2];
                row.emplace_back(color);
            }
            output.emplace_back(row);
        }

        return output;
    }

    void placeTileOnCanvas(std::vector<std::vector<RGB>>& canvas,
                           const std::vector<std::vector<RGB>>& tileImage,
                           int xPos, int yPos, int tileWidth, int tileHeight) {
        for (int i = 0; i < tileHeight; ++i) {
            for (int j = 0; j < tileWidth; ++j) {
                int canvasY = yPos + i;
                int canvasX = xPos + j;

                if (canvasY < canvas.size() && canvasX < canvas[0].size()) {
                    canvas[canvasY][canvasX] = tileImage[i][j];
                }
            }
        }
    }
};

int main() {
    int width, height, channels;
    Filter filter;
    int canvasWidth = 1100;
    int canvasHeight = 1100;

    // Load the image file
    unsigned char* smallImage = stbi_load("./images/tile1.jpg", &width, &height, &channels, 3);

    if (smallImage == nullptr) {
        std::cout << "Failed to load image!" << std::endl;
        return -1;
    }

    cout << "small image: " << smallImage << endl;

    // Convert the loaded image to a 2D vector of RGB values
    auto tileImage = filter.convertTo2D(smallImage, width, height);

    // Free the loaded image data
    stbi_image_free(smallImage);

    // Create canvas and place tiles
    std::vector<std::vector<RGB>> canvas = filter.createCanvas(1100, 1100);
    int padding = 20;
    int tilesPerRow = (canvasWidth + padding) / (width + padding);
    int tilesPerColumn = (canvasHeight + padding) / (height + padding);

    // Place tiles on the canvas
    for (int row = 0; row < tilesPerColumn; ++row) {
        for (int col = 0; col < tilesPerRow; ++col) {
            int xPos = col * (width + padding);
            int yPos = row * (height + padding);
            filter.placeTileOnCanvas(canvas, tileImage, xPos, yPos, width, height);
        }
    }

    // Save the resulting image to a file
    filter.saveToPNG(canvas, canvasWidth, canvasHeight, "output.png");

    return 0;
}

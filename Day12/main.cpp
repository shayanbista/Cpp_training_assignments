#include <iostream>
#include <vector>
#include <queue>  

using namespace std;

struct RGB {
    unsigned char r, g, b;
};

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "./stb/stb_image.h"
#include "./stb/stb_image_write.h"

class Color{
    public:
    Color(){ 
        // default constructor
    }
    bool detectColor(std::vector<std::vector<RGB>>&image, int& height, int& width, int& startX, int& startY) {
        bool found = false;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (image[i][j].r >= 200 && image[i][j].g <= 90 && image[i][j].b <= 90) {
                    image[i][j].r = 0;
                    image[i][j].g = 226;
                    image[i][j].b = 20;
                    startX = i; 
                    startY = j; 
                    found = true;
                }
            }
        }
        return found;
    }

    bool detectBlueBox(std::vector<std::vector<RGB>>& image, int& height, int& width, int& startX, int& startY, int& goalX, int& goalY) {
        bool found = false;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (image[i][j].b > 150 && image[i][j].r < 100 && image[i][j].g < 100) {
                    goalX = i;  
                    goalY = j;  
                    found=true;
                }
            }
        }
        return found;
    }


};

class Maze{    
    public:
    Maze() {
        // default constructor
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

    bool bfs(std::vector<std::vector<RGB>>& image, int startX, int startY, int goalX, int goalY, int width, int height) {
        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};  
        std::queue<std::pair<int, int>> q;
        q.push({startX, startY});
        
        std::vector<std::vector<bool>> visited(height, std::vector<bool>(width, false));
        visited[startX][startY] = true;
        
        std::vector<std::vector<std::pair<int, int>>> parent(height, std::vector<std::pair<int, int>>(width, {-1, -1}));
        
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
        
            if (x == goalX && y == goalY) {
                std::pair<int, int> current = {x, y};
                while (current != std::make_pair(startX, startY)) {
                    int prevX = current.first;
                    int prevY = current.second;
                
                    image[prevX][prevY].r = 0;
                    image[prevX][prevY].g = 255;
                    image[prevX][prevY].b = 0;
                    
                    current = parent[prevX][prevY];
                }
            
                image[startX][startY].r = 0;
                image[startX][startY].g = 255;
                image[startX][startY].b = 0;
                
                return true;
            }
            
            for (const auto& dir : directions) {
                int newX = x + dir[0];
                int newY = y + dir[1];
            
                if (newX >= 0 && newX < height && newY >= 0 && newY < width &&
                    !visited[newX][newY] &&
                    !(image[newX][newY].r == 255 && image[newX][newY].g == 255 && image[newX][newY].b == 255)) {
                    
                    visited[newX][newY] = true;
                    parent[newX][newY] = {x, y};
                    
                    image[newX][newY].r = 0;
                    image[newX][newY].g = 255;
                    image[newX][newY].b = 0;
                    
                    q.push({newX, newY});
                }
            }
        }
        
        return false; 
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
};

int main() {
    Maze maze;
    int height, width, channels;

    unsigned char* smallImage = stbi_load("./images/maze.jpg", &width, &height, &channels, 3);
    if (!smallImage) {
        cout << "Failed to load image!" << endl;
        return -1;
    }

    auto image = maze.convertTo2D(smallImage, height, width);
    stbi_image_free(smallImage); 

    int imageHeight = image.size();
    int imageWidth = image[0].size();
    Color color;

    int startX = -1, startY = -1;
    int goalX = -1, goalY = -1;

    if (!color.detectColor(image, imageHeight, imageWidth, startX, startY)) {
        cout << "No starting point found!" << endl;
        return -1;
    }

    cout << "Starting point found at (" << startX << ", " << startY << ")" << endl;


    if (!color.detectBlueBox(image, imageHeight, imageWidth, startX, startY, goalX, goalY)) {
        cout << "No goal point found (blue box)!" << endl;
        return -1;
    }

    cout << "Goal point (blue box) found at (" << goalX << ", " << goalY << ")" << endl;

    if (maze.bfs(image, startX, startY, goalX, goalY, imageWidth, imageHeight)) {
        cout << "Path found!" << endl;
    } else {
        cout << "No path found!" << endl;
    }

    maze.saveToPNG(image, width, height, "maze_modified.png");

    return 0;
}

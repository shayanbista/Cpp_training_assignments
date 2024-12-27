#include <iosteam>

using namespace std;

int main() {
    int width, height, channels;
    unsigned char* smallImage = stbi_load("./images/tile.jpg", &width, &height, &channels, 3);
    if (smallImage == nullptr) {
        std::cout << "Failed to load image!" << std::endl;
        return -1;
    }


}
// Brenda Romero
// Ashley Garcia
// 1/22/2026

#include <iostream>
#include <fstream>

// added palette_size
const int PALETTE_SIZE = 5;

int red[PALETTE_SIZE]   = { 66, 25,  9,   0, 255 };
int green[PALETTE_SIZE] = { 30,  7,  1,   100, 255 };
int blue[PALETTE_SIZE]  = { 15, 26, 47, 100, 255 };

int main() {
    const int WIDTH = 800;
    const int HEIGHT = 600;
    const int MAX_ITER = 300;

    std::ofstream out("mandelbrot.html");
    if (!out) {
        std::cerr << "Error opening HTML output file\n";
        return 1;
    }

    out << "<!DOCTYPE html>\n<html>\n<body>\n";
    out << "<canvas id='c' width='" << WIDTH << "' height='" << HEIGHT << "'></canvas>\n";
    out << "<script>\n";
    out << "const red = [" << red[0];
    for(int i=1; i<PALETTE_SIZE; i++) out << ", " << red[i];
    out << "];\n";
    out << "const green = [" << green[0];
    for(int i=1; i<PALETTE_SIZE; i++) out << ", " << green[i];
    out << "];\n";
    out << "const blue = [" << blue[0];
    for(int i=1; i<PALETTE_SIZE; i++) out << ", " << blue[i];
    out << "];\n";
    out << "const canvas = document.getElementById('c');\n";
    out << "const ctx = canvas.getContext('2d');\n";
    out << "const img = ctx.createImageData(" << WIDTH << ", " << HEIGHT << ");\n";

    // Push Mandelbrot data into JS arrays
    out << "let data = img.data;\n";

    out << "let i = 0;\n";
    out << "for (let y = 0; y < " << HEIGHT << "; y++) {\n";
    out << "  for (let x = 0; x < " << WIDTH << "; x++) {\n";
    out << "    let zx = 0, zy = 0;\n";
    out << "    let cX = (x - " << WIDTH / 2 << ") / 150;\n";
    out << "    let cY = (y - " << HEIGHT / 2 << ") / 150;\n";
    out << "    let iter = " << MAX_ITER << ";\n";
    out << "    while (zx*zx + zy*zy < 4 && iter > 0) {\n";
    out << "      let tmp = zx*zx - zy*zy + cX;\n";
    out << "      zy = 2*zx*zy + cY;\n";
    out << "      zx = tmp;\n";
    out << "      iter--;\n";
    out << "    }\n";

    // Sets the color in the image
    out << "    let index = iter % " << PALETTE_SIZE << ";\n";
    out << "    data[i++] = red[index];\n";
    out << "    data[i++] = green[index];\n";
    out << "    data[i++] = blue[index];\n";
    out << "    data[i++] = 255;\n";   // alpha
    out << "  }\n";
    out << "}\n"; 

    out << "ctx.putImageData(img, 0, 0);\n";
    out << "</script>\n</body>\n</html>\n";

    out.close();
    std::cout << "mandelbrot.html generated — open it in your cloud IDE's browser preview.\n";
    return 0;
}

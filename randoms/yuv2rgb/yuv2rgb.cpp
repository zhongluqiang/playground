/**
 * @file yuv2rgb.cpp
 * @author your name (you@domain.com)
 * @brief 查表法实现yuv2rgb，参考https://blog.csdn.net/liyuanbhu/article/details/68951683
 *        在线验证：https://www.mikekohn.net/file_formats/yuv_rgb_converter.php
 * @version 0.1
 * @date 2021-07-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <cstdio>
#include <climits>
#include <algorithm>
#include <cstdint>

static uint8_t yv2r[256][256];
static uint8_t yu2b[256][256];
static uint16_t uv2t[256][256];
static uint8_t yt2g[256][270];

int max_t = INT_MIN;
int min_t = INT_MAX;

static void init_yuv2rgb_table() {
    int r, g, b, t;
    int y, u, v;
    for (y = 0; y < 256; y++) {
        for (int v = 0; v < 256; v++) {
            u = v;

            r = y + 1.403 * (v - 128);
            r = r > 255 ? 255 : (r < 0 ? 0 : r);

            b = y + 1.770 * (u - 128);
            b = b > 255 ? 255 : (b < 0 ? 0 : b);

            yv2r[y][v] = r;
            yu2b[y][u] = b;
        }
    }
    for (u = 0; u < 256; u++) {
        for (v = 0; v < 256; v++) {
            t          = 0.343 * (u - 128) + 0.714 * (v - 128);

            max_t = std::max(t, max_t);
            min_t = std::min(t, min_t);

            uv2t[u][v] = t + 135; // 0 ~ 269
        }
    }
    
    printf("max_t:%d, min_t:%d\n", max_t, min_t); // -135 ~ 134

    for(y = 0; y < 256; y++) {
        for(t = 0; t < 270; t++) {
            g = y - t + 135;
            g = g > 255 ? 255 : (g < 0 ? 0 : g);
            yt2g[y][t] = g;
        }
    }
}

int main(int argc, char *argv[]) {
    if(argc < 4) {
        printf("Usage: %s y u v\n", argv[0]);
        return 0;
    }

    init_yuv2rgb_table();

    int y, u, v;
    y = atoi(argv[1]);
    u = atoi(argv[2]);
    v = atoi(argv[3]);

    // 查表法
    printf("table lookup: r=%d, g=%d, b=%d\n", yv2r[y][v], yt2g[y][uv2t[u][v]], yu2b[y][u]);

    // 公式法
    int r = y + 1.403 * (v - 128);
    int g = y - 0.343 * (u - 128) - 0.714 * (v - 128);
    int b = y + 1.770 * (u - 128);
    printf("matrix convert: r=%d, g=%d, b=%d\n", r, g, b);
    return 0;
}

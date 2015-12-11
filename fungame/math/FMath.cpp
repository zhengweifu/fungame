//
//  math.cpp
//  fungame_libs
//
//  Created by zwf on 11/12/2015.
//  Copyright © 2015 com.zwf. All rights reserved.
//

#include "fungame/math/FMath.h"

#define NEAR_ZERO_FLOAT_32 0.0000000000000000001f
#define MATH_PI 3.1415926535897932384f
#define MATH_LN2 0.6931471805599453094f
#define MATH_DEG_TO_RAD_FACTOR (3.1415926535897932384f/180)
#define MATH_RAD_TO_DEG_FACTOR (180.f/MATH_PI)

namespace fungame { namespace math {
    
    std::string generateUUID() {
        
        char chars[63] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        
        std::stringstream uuid;
        
        int rnd = 0, r;
        
        for (auto i = 0; i < 36; i++) {
            
            if (i == 8 || i == 13 || i == 18 || i == 23) {
                
                uuid << "-";
                
            }
            else if (i == 14) {
                
                uuid << "4";
                
            }
            else {
                
                if (rnd <= 0x02) rnd = 0x2000000 + ( (std::rand() * 0x1000000) | 0);
                r = rnd & 0xf;
                rnd = rnd >> 4;
                uuid << chars[(i == 19) ? (r & 0x3) | 0x8 : r];
                
            }
        }
        
        return uuid.str();
    }
}}

//
//  Vector2.h
//  fungame_libs
//
//  Created by zwf on 11/12/2015.
//  Copyright © 2015 com.zwf. All rights reserved.
//

#ifndef __VECTOR2_H__
#define __VECTOR2_H__

#include <stdio.h>
#include <ostream>

namespace fungame { namespace math {
    class Vector2 {
    public:
        double x;
        double y;
        
    public:
        inline Vector2() : x(0), y(0) {}
        
        inline Vector2(double _x, double _y): x(_x), y(_y) {}
        
        inline Vector2& copy(const Vector2 &v2);
        
        Vector2& add(const Vector2 &v2);
        
        Vector2& sub(const Vector2 &v2);
        
        Vector2& multiply(const Vector2 &v2);
        
        Vector2& divide(const Vector2 &v2);
        
        
        friend std::ostream& operator<<(std::ostream &ostream, const Vector2 &v2);
        
        friend Vector2& operator+(Vector2 & left, const Vector2 &right);
        
        friend Vector2& operator-(Vector2 & left, const Vector2 &right);
        
        friend Vector2& operator*(Vector2 & left, const Vector2 &right);
        
        friend Vector2& operator/(Vector2 & left, const Vector2 &right);
        
        Vector2& operator+=(const Vector2 & v2);
        
        Vector2& operator-=(const Vector2 & v2);

        Vector2& operator*=(const Vector2 & v2);
        
        Vector2& operator/=(const Vector2 & v2);
        
        bool operator==(const Vector2 &v2) const;
        
        bool operator!=(const Vector2 &v2) const;
        
    };
}}

#endif /* __VECTOR2_H__ */

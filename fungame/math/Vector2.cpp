//
//  Vector2.cpp
//  fungame_libs
//
//  Created by zwf on 11/12/2015.
//  Copyright © 2015 com.zwf. All rights reserved.
//

#include "fungame/math/Vector2.h"

namespace fungame { namespace math {
    Vector2& Vector2::copy(const Vector2 &v2) {
        x = v2.x;
        y = v2.y;
        
        return *this;
    }
    
    Vector2& Vector2::add(const Vector2 &v2) {
        x += v2.x;
        y += v2.y;
        
        return *this;
    }
    
    Vector2& Vector2::sub(const Vector2 &v2) {
        x -= v2.x;
        y -= v2.y;
        
        return *this;
    }
    
    Vector2& Vector2::multiply(const Vector2 &v2) {
        x *= v2.x;
        y *= v2.y;
        
        return *this;
    }
    
    Vector2& Vector2::divide(const Vector2 &v2) {
        x /= v2.x;
        y /= v2.y;
        
        return *this;
    }
    
    std::ostream& operator<<(std::ostream &ostream, const Vector2 &v2) {
        ostream << "Vector2(" << v2.x << ", " << v2.y << ")";
        return ostream;
    }
    
    Vector2& operator+(Vector2 & left, const Vector2 &right) {
        return left.add(right);
    }
    
    Vector2& operator-(Vector2 & left, const Vector2 &right) {
        return left.sub(right);
    }
    
    Vector2& operator*(Vector2 & left, const Vector2 &right) {
        return left.multiply(right);
    }
    
    Vector2& operator/(Vector2 & left, const Vector2 &right) {
        return left.divide(right);
    }
    
    Vector2& Vector2::operator+=(const Vector2 & v2) {
        return this->add(v2);
    }
    
    Vector2& Vector2::operator-=(const Vector2 & v2) {
        return this->sub(v2);
    }
    
    Vector2& Vector2::operator*=(const Vector2 & v2) {
        return this->multiply(v2);
    }
    
    Vector2& Vector2::operator/=(const Vector2 & v2) {
        return this->divide(v2);
    }
    
    bool Vector2::operator==(const Vector2 &v2) const {
        return x == v2.x && y == v2.y;
    }
    
    bool Vector2::operator!=(const Vector2 &v2) const {
        return !(*this == v2);
    }

}}
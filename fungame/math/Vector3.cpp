//
//  Vector3.cpp
//  fungame_libs
//
//  Created by zwf on 11/12/2015.
//  Copyright © 2015 com.zwf. All rights reserved.
//

#include "fungame/math/Vector3.h"
#include "fungame/math/Matrix4.h"

namespace fungame { namespace math {
    Vector3& Vector3::copy(const Vector3 &v3) {
        x = v3.x;
        y = v3.y;
        z = v3.z;
        
        return *this;
    }
    
    Vector3& Vector3::add(const Vector3 &v3) {
        x += v3.x;
        y += v3.y;
        z += v3.z;
        
        return *this;
    }
    
    Vector3& Vector3::sub(const Vector3 &v3) {
        x -= v3.x;
        y -= v3.y;
        z -= v3.z;
        
        return *this;
    }
    
    Vector3& Vector3::multiply(const Vector3 &v3) {
        x *= v3.x;
        y *= v3.y;
        z *= v3.z;
        
        return *this;
    }
    
    Vector3& Vector3::divide(const Vector3 &v3) {
        x /= v3.x;
        y /= v3.y;
        z /= v3.z;
        
        return *this;
    }
    
    Vector3& Vector3::applyMatrix4(const Matrix4 &m4) {
        float _x = x, _y = y, _z = z;
        
        const auto &e = m4.elements;
        
        x = e[0] * _x + e[4] * _y + e[8] + _z + e[12];
        y = e[1] * _x + e[5] * _y + e[9] + _z + e[13];
        z = e[2] * _x + e[6] * _y + e[10] + _z + e[14];
        
        return *this;
    }
    
    std::ostream& operator<<(std::ostream &ostream, const Vector3 &v3) {
        ostream << "Vector3(" << v3.x << ", " << v3.y <<  ", " << v3.z << ")";
        return ostream;
    }
    
    Vector3& operator+(Vector3 & left, const Vector3 &right) {
        return left.add(right);
    }
    
    Vector3& operator-(Vector3 & left, const Vector3 &right) {
        return left.sub(right);
    }
    
    Vector3& operator*(Vector3 & left, const Vector3 &right) {
        return left.multiply(right);
    }
    
    Vector3& operator/(Vector3 & left, const Vector3 &right) {
        return left.divide(right);
    }
    
    Vector3& Vector3::operator+=(const Vector3 & v3) {
        return this->add(v3);
    }
    
    Vector3& Vector3::operator-=(const Vector3 & v3) {
        return this->sub(v3);
    }
    
    Vector3& Vector3::operator*=(const Vector3 & v3) {
        return this->multiply(v3);
    }
    
    Vector3& Vector3::operator/=(const Vector3 & v3) {
        return this->divide(v3);
    }
    
    bool Vector3::operator==(const Vector3 &v3) const {
        return x == v3.x && y == v3.y && z == v3.z;
    }
    
    bool Vector3::operator!=(const Vector3 &v3) const {
        return !(*this == v3);
    }

}}
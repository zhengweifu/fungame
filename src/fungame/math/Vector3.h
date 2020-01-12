//
//  Vector3.h
//  fungame_libs
//
//  Created by zwf on 11/12/2015.
//  Copyright © 2015 com.zwf. All rights reserved.
//

#ifndef __VECTOR3_H__
#define __VECTOR3_H__

#include <stdio.h>
#include <ostream>

namespace fungame { namespace math {
    class Matrix4;
    
    class Vector3 {
    public:
        float x;
        float y;
        float z;
        
    public:
        inline Vector3() : x(0), y(0), z(0) {}
        
        inline Vector3(float _x, float _y, float _z): x(_x), y(_y), z(_z) {}
        
        inline Vector3& copy(const Vector3 &v3);
        
        Vector3& add(const Vector3 &v3);
        
        Vector3& sub(const Vector3 &v3);
        
        Vector3& multiply(const Vector3 &v3);
        
        Vector3& divide(const Vector3 &v3);
        
        Vector3& applyMatrix4(const Matrix4 &m4);
        
        friend std::ostream& operator<<(std::ostream &ostream, const Vector3 &v3);
        
        friend Vector3& operator+(Vector3 & left, const Vector3 &right);
        
        friend Vector3& operator-(Vector3 & left, const Vector3 &right);
        
        friend Vector3& operator*(Vector3 & left, const Vector3 &right);
        
        friend Vector3& operator/(Vector3 & left, const Vector3 &right);
        
        Vector3& operator+=(const Vector3 & v3);
        
        Vector3& operator-=(const Vector3 & v3);

        Vector3& operator*=(const Vector3 & v3);
        
        Vector3& operator/=(const Vector3 & v3);
        
        bool operator==(const Vector3 &v3) const;
        
        bool operator!=(const Vector3 &v3) const;
        
    };
}}

#endif /* __VECTOR3_H__ */

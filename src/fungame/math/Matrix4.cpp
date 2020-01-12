//
//  Matrix4.cpp
//  fungame_libs
//
//  Created by zwf on 11/12/2015.
//  Copyright © 2015 com.zwf. All rights reserved.
//

#include "fungame/math/Matrix4.h"
#include "fungame/math/Vector3.h"
#include <math.h>

namespace fungame { namespace math {
    
    Matrix4::Matrix4() {
        identity();
    }
    
    
    Matrix4& Matrix4::set(float n11, float n12, float n13, float n14,
                 float n21, float n22, float n23, float n24,
                 float n31, float n32, float n33, float n34,
                 float n41, float n42, float n43, float n44) {
        elements[0]  = n11;
        elements[4]  = n12;
        elements[8]  = n13;
        elements[12] = n14;
        
        elements[1]  = n21;
        elements[5]  = n22;
        elements[9]  = n23;
        elements[13] = n24;
        
        elements[2]  = n31;
        elements[6]  = n32;
        elements[10] = n33;
        elements[14] = n34;
        
        elements[3]  = n41;
        elements[7]  = n42;
        elements[11] = n43;
        elements[15] = n44;
        
        
        return *this;
    }
    
    Matrix4& Matrix4::identity() {
        set(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
        
        return *this;
    }
    
    Matrix4& Matrix4::copy(const Matrix4 &m4) {
        std::copy_n(m4.elements, 16, elements);
        return *this;
    }
    
    Matrix4 Matrix4::clone() {
        Matrix4 m4;
        m4.copy(*this);
        return m4;
    }
    
    Matrix4& Matrix4::multiply(const Matrix4 &m4) {
        auto& ae = elements;
        const auto& be = m4.elements;
        
        float a11 = ae[0], a12 = ae[4], a13 = ae[8],  a14 = ae[12];
        float a21 = ae[1], a22 = ae[5], a23 = ae[9],  a24 = ae[13];
        float a31 = ae[2], a32 = ae[6], a33 = ae[10], a34 = ae[14];
        float a41 = ae[3], a42 = ae[7], a43 = ae[11], a44 = ae[15];
        
        float b11 = be[0], b12 = be[4], b13 = be[8],  b14 = be[12];
        float b21 = be[1], b22 = be[5], b23 = be[9],  b24 = be[13];
        float b31 = be[2], b32 = be[6], b33 = be[10], b34 = be[14];
        float b41 = be[3], b42 = be[7], b43 = be[11], b44 = be[15];
        
        ae[0]  = a11 * b11 + a12 * b21 + a13 * b31 + a14 * b41;
        ae[4]  = a11 * b12 + a12 * b22 + a13 * b32 + a14 * b42;
        ae[8]  = a11 * b13 + a12 * b23 + a13 * b33 + a14 * b43;
        ae[12] = a11 * b14 + a12 * b24 + a13 * b34 + a14 * b44;
        
        ae[1]  = a21 * b11 + a22 * b21 + a23 * b31 + a24 * b41;
        ae[5]  = a21 * b12 + a22 * b22 + a23 * b32 + a24 * b42;
        ae[9]  = a21 * b13 + a22 * b23 + a23 * b33 + a24 * b43;
        ae[13] = a21 * b14 + a22 * b24 + a23 * b34 + a24 * b44;
        
        ae[2]  = a31 * b11 + a32 * b21 + a33 * b31 + a34 * b41;
        ae[6]  = a31 * b12 + a32 * b22 + a33 * b32 + a34 * b42;
        ae[10] = a31 * b13 + a32 * b23 + a33 * b33 + a34 * b43;
        ae[14] = a31 * b14 + a32 * b24 + a33 * b34 + a34 * b44;
        
        ae[3]  = a41 * b11 + a42 * b21 + a43 * b31 + a44 * b41;
        ae[7]  = a41 * b12 + a42 * b22 + a43 * b32 + a44 * b42;
        ae[11] = a41 * b13 + a42 * b23 + a43 * b33 + a44 * b43;
        ae[15] = a41 * b14 + a42 * b24 + a43 * b34 + a44 * b44;
        
        return *this;
    }
    
    Matrix4& Matrix4::operator*=(const Matrix4 &right) {
        return multiply(right);
    }
    
    
    Matrix4& operator*(Matrix4 &left, const Matrix4 &right) {
        return left.multiply(right);
    }
    
    Matrix4& makeTranslate(Matrix4 &m4, const Vector3 &position) {
        m4.set(1, 0, 0, position.x,
            0, 1, 0, position.y,
            0, 0, 1, position.z,
            0, 0, 0, 1);
        
        return m4;
    }
    
    Matrix4& makeRotate(Matrix4 &m4, float angle, const Vector3 &axis) {
        float c = cos(angle);
        float s = sin(angle);
        
        float t = 1 - c;
        float x = axis.x, y = axis.y, z = axis.z;
        
        float tx = t * x, ty = t * y;
        
        m4.set(
            tx * x + c,     tx * y - s * z, tx * z + s * y, 0,
            tx * y + s * z, ty * y + c,     ty * z - s * x, 0,
            tx * z - s * y, ty * z + s * x, t * z * z + c,  0,
            0,              0,              0,              1);
        
        return m4;
    }
    
    Matrix4& makeScale(Matrix4 &m4, const Vector3 &scale) {
        m4.set(scale.x, 0, 0, 0,
            0, scale.y, 0, 0,
            0, 0, scale.z, 0,
            0, 0, 0, 1);
        
        return m4;
    }
    
    Matrix4& makeOrthographic(Matrix4 &m4, float left, float right, float top, float bottom, float near, float far) {
        
        float RsubtractL = right - left;
        float RaddL = right + left;
        float TsubtractB = top - bottom;
        float TaddB = top + bottom;
        float FsubtractN = far - near;
        float FaddN = far + near;
        
        m4.set(2/RsubtractL, 0,             0,             -RaddL/RsubtractL,
               0,            2/TsubtractB,  0,             -TaddB/TsubtractB,
               0,            0,            -2/FsubtractN,  -FaddN/FsubtractN,
               0,            0,             0,              1);
        
        
        return m4;
    }
    
    Matrix4& makePerspective(Matrix4 &m4, float fov, float aspect, float far, float near) {
        
        float t = tan(fov/2);
        
        float FSN = far - near;
        float FAN = far + near;
        float FMN_2 = 2 * far * near;
        
        m4.set(1/(aspect * t), 0,    0,       0,
               0,              1/t,  0,       0,
               0,              0,   -FAN/FSN, FMN_2/FSN,
               0,              0,   -1,       0);
        
        return m4;
    }
    
    
    std::ostream& operator<<(std::ostream &ostream, const Matrix4 &m4) {
        ostream << "Matrix4(" << m4.elements[0] << ", " << m4.elements[1] << ", "
        << m4.elements[2]  << ", " << m4.elements[3]  << ", " << m4.elements[4]  << ", "
        << m4.elements[5]  << ", " << m4.elements[6]  << ", " << m4.elements[7]  << ", "
        << m4.elements[8]  << ", " << m4.elements[9]  << ", " << m4.elements[10] << ", "
        << m4.elements[11] << ", " << m4.elements[12] << ", " << m4.elements[13] << ", "
        << m4.elements[14] << ", " << m4.elements[15] << ")";
        
        return ostream;
    }
    
}}
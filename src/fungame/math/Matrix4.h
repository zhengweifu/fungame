//
//  Matrix4.h
//  fungame_libs
//
//  Created by zwf on 11/12/2015.
//  Copyright © 2015 com.zwf. All rights reserved.
//

#ifndef __MATRIX4_H__
#define __MATRIX4_H__

#include <ostream>

namespace fungame { namespace math {
    class Vector3;

    class Matrix4 {
        
    public:
        float elements[16];
        
        Matrix4();
        
        Matrix4& set(float n11, float n12, float n13, float n14,
                     float n21, float n22, float n23, float n24,
                     float n31, float n32, float n33, float n34,
                     float n41, float n42, float n43, float n44);
        
        Matrix4& identity();
        
        Matrix4& copy(const Matrix4 &m4);
        
        Matrix4 clone();
        
        Matrix4& multiply(const Matrix4 &m4);
        
        Matrix4& operator*=(const Matrix4 &right);
        
        
        friend Matrix4& operator*(Matrix4 &left, const Matrix4 &right);
        
        friend Matrix4& makeTranslate(Matrix4 &m4, const Vector3 &position);
        
        friend Matrix4& makeRotate(Matrix4 &m4, float angle, const Vector3 &axis);
        
        friend Matrix4& makeScale(Matrix4 &m4, const Vector3 &scale);
        
        friend Matrix4& makeOrthographic(Matrix4 &m4, float left, float right, float top, float bottom, float near, float far);
        
        friend Matrix4& makePerspective(Matrix4 &m4, float fov, float aspect, float far, float near);
        
        friend std::ostream& operator<<(std::ostream &ostream, const Matrix4 &m4);
    };

}}

#endif /* __MATRIX4_H__ */

#pragma once

#include <array>

#include "math/Vector.hpp"

namespace p2d { namespace math {
    class Transform3 {
    public:
        Transform3();
        Transform3(float m00, float m01, float m02, float m03,
                  float m10, float m11, float m12, float m13,
                  float m20, float m21, float m22, float m23,
                  float m30, float m31, float m32, float m33);

        Transform3(const Transform3& rhs);
        Transform3(Transform3&& rhs);

        Vector4f transformPoint(const float& x, const float& y, const float& z, const float& w) const;
        Vector4f transformVector(const Vector4f& vec) const;
        
        Vector3f transformPoint(const float& x, const float& y, const float& z) const;
        Vector3f transformVector(const Vector3f& vec) const;

        static Transform3 Translation(const float& dx, const float& dy, const float& dz);
        static Transform3 Translation(const Vector3f& vec);
        static Transform3 Scaling(const Vector3f& vec);
        static Transform3 Scaling(const float& sx, const float& sy, const float& sz);
        static Transform3 RotationAboutX(const float& theta);
        static Transform3 RotationAboutY(const float& theta);
        static Transform3 RotationAboutZ(const float& theta);
        static Transform3 Rotation(const float& yaw, const float& pitch, const float& roll);
        static Transform3 Identity();

        Transform3 operator = (const Transform3& rhs);

        friend bool operator == (const Transform3& lhs, const Transform3& rhs); 
        friend float determinant(const Transform3& t);
        friend Transform3 composition(const Transform3& lhs, const Transform3& rhs);
        friend Transform3 operator * (const Transform3& lhs, const Transform3& rhs);
        
        friend Vector3f operator * (const Transform3& lhs, const Vector3f& rhs);

        std::array<float, 16> mat;
    }; // class Transform

    float determinant(const Transform3& t);

    Transform3 composition(const Transform3& lhs, const Transform3& rhs);
    Transform3 operator * (const Transform3& lhs, const Transform3& rhs);

    bool operator == (const Transform3& lhs, const Transform3& rhs);
    
/* 

    Transform operator * (const Transform& lhs, const float& rhs);
    Transform operator * (const float& lhs, const Transform& rhs);
    Transform operator * (const Transform& lhs, const Transform& rhs);
    Vector3f operator * (const Transform& lhs, const Vector2f& rhs);
 */
} // namespace math
} // namespace p2d


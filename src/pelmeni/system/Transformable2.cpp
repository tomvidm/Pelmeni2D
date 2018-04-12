#include "system/Transformable2.hpp"

namespace p2d { namespace system {
    Transformable2::Transformable2()
    : needsUpdate(true),
      position(math::Vector2f(0.f, 0.f)),
      origin(math::Vector2f(0.f, 0.f)),
      scale(math::Vector2f(1.f, 1.f)),
      rotation(math::Radian(0.f)),
      transform(math::Transform::Identity()) {;}

      void Transformable2::setPosition(const math::Vector2f& vec) {
          position = vec;
          needsUpdate = true;
      } // setPosition

      void Transformable2::setOrigin(const math::Vector2f& vec) {
          origin = vec;
          needsUpdate = true;
      } // setOrigin

      void Transformable2::setScale(const math::Vector2f& vec) {
          scale = vec;
          needsUpdate = true;
      } // setScale

      void Transformable2::setRotation(const math::Radian& rads) {
          rotation = rads.toRadians();
          needsUpdate = true;
      } // setRotation

      math::Vector2f Transformable2::getPosition() const {
          return position;
      } // getPosition

      math::Vector2f Transformable2::getOrigin() const {
          return origin;
      } // getPosition

      math::Vector2f Transformable2::getScale() const {
          return scale;
      } // getPosition

      math::Radian Transformable2::getRotation() const {
          return rotation;
      } // getRotation

      void Transformable2::move(const math::Vector2f& vec) {
          position += vec;
          needsUpdate = true;
      } // move

      void Transformable2::rotate(const math::Radian& rads) {
          rotation += rads;
          needsUpdate = true;
      } // rotate

      math::Transform Transformable2::getTransform() {
          if (needsUpdate) {
              transform = math::Transform::Translate(position) *
                          math::Transform::Rotation(rotation.toRadians()) *
                          math::Transform::Scale(scale) *
                          math::Transform::Translate(-origin);
          }

          return transform;
      }
} // namespace system
} // namespace p2d
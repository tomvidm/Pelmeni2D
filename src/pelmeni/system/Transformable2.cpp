#include "system/Transformable2.hpp"

namespace p2d { namespace system {
    Transformable2::Transformable2(
        const math::Vector2f& initialPosition,
        const math::Vector2f& initialOrigin,
        const math::Vector2f& initialScale,
        const math::Radian& initialRotation)
    : _needsUpdate(true),
      position(initialPosition),
      origin(initialOrigin),
      scale(initialScale),
      rotation(initialRotation),
      transform(math::Transform::Identity()) {
        ;
    }

    Transformable2::Transformable2()
    : Transformable2(math::Vector2f(0.f, 0.f),
                     math::Vector2f(0.f, 0.f),
                     math::Vector2f(1.f, 1.f),
                     math::Radian(0.f)) {
        ;
    }

    Transformable2::Transformable2(const math::Vector2f& initialPosition)
    : Transformable2(initialPosition,
                     math::Vector2f(0.f, 0.f),
                     math::Vector2f(0.f, 0.f),
                     math::Radian(0.f)) {
        ;
    }

      void Transformable2::setPosition(const math::Vector2f& vec) {
          position = vec;
          _needsUpdate = true;
      } // setPosition

      void Transformable2::setOrigin(const math::Vector2f& vec) {
          origin = vec;
          _needsUpdate = true;
      } // setOrigin

      void Transformable2::setScale(const math::Vector2f& vec) {
          scale = vec;
          _needsUpdate = true;
      } // setScale

      void Transformable2::setRotation(const math::Radian& rads) {
          rotation = rads.toRadians();
          _needsUpdate = true;
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
          _needsUpdate = true;
      } // move

      void Transformable2::rotate(const math::Radian& rads) {
          rotation += rads;
          _needsUpdate = true;
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
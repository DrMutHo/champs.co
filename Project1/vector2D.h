#pragma once
#include <cmath>
#include <iostream>

class Vector2D {
private:
    float x;
    float y;

public:
    Vector2D(float x = 0, float y = 0) : x(x), y(y) {}
    Vector2D(SDL_Point point1, SDL_Point point2) {
        this->x = point2.x - point1.x;
        this->y = point2.y - point1.y;
    }
    float getX() { return x; }
    float getY() { return y; }

    float length() const {
        return sqrt(x * x + y * y);
    }

    void normalize() {
        float len = length();
        if (len != 0) {
            x /= len;
            y /= len;
        }
    }

    void reverse() {
        x = -x;
        y = -y;
    }

    float dot(const Vector2D& other) const {
        return x * other.x + y * other.y;
    }

    float angle(const Vector2D& other) const {
        float lenProduct = length() * other.length();
        if (lenProduct != 0) {
            float dotProduct = dot(other);
            return acos(dotProduct / lenProduct);
        }
        return 0.0f;
    }

    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }

    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x - other.x, y - other.y);
    }

    Vector2D operator*(float scalar) const {
        return Vector2D(x * scalar, y * scalar);
    }

    Vector2D operator/(float scalar) const {
        if (scalar != 0) {
            return Vector2D(x / scalar, y / scalar);
        }
        return *this;
    }

    void print() const {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};
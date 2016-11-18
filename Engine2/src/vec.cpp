#include "vec.h"

namespace Engine2 {

	/*-----------  VEC2 ------------*/

	vec2::vec2() {
		x = 0;
		y = 0;
	}

	vec2::~vec2(){}

	vec2::vec2(const float xI, const float yI) {
		x = xI;
		y = yI;
	}

	vec2::vec2(const vec2 & v)
	{
		x = v.x;
		y = v.y;
	}
	vec2 & vec2::operator= (const vec2 & v)
	{
		x = v.x;
		y = v.y;
		return *this;
	}

	const vec2 operator+ (const vec2 & v1, const vec2 & v2) {
		return vec2(v1.x + v2.x, v1.y + v2.y);
	}

	const vec2 operator- (const vec2 & v1, const vec2 & v2) {
		return vec2(v1.x - v2.x, v1.y - v2.y);
	}

	const vec2 operator* (const vec2 & v, const float k) {
		return vec2(v.x * k, v.y * k);
	}

	const vec2 operator* (const float k, const vec2 & v) {
		return vec2(v.x * k, v.y * k);
	}

	void operator+= (vec2 & v1, const vec2 & v2)
	{
		v1 = v1 + v2;
	}

	void operator-= (vec2 & v1, const vec2 & v2)
	{
		v1 = v1 - v2;
	}

	void operator*= (vec2 & v, const float k)
	{
		v = v * k;
	}

	const bool operator== (const vec2 & v1, const vec2 & v2)
	{
		return equalFloats(v1.x, v2.x) && equalFloats(v1.y, v2.y);
		//return v1.x == v2.x && v1.y == v2.y;
	}

	const bool operator!= (const vec2 & v1, const vec2 & v2)
	{
		return !(v1 == v2);
	}

	float vec2::quadrance() const{
		return pow(x, 2) + pow(y, 2);
	}

	float vec2::norm() const{
		return float(sqrt(x*x + y*y));
	}
	const vec2 vec2::normalize() const{
		float n = norm();
		vec2 v = vec2();
		if (n != 0) {
			v.x = x / n;
			v.y = y / n;
		}
		return v;
	}

	float vec2::dot(const vec2 & other) const{
		return (x * other.x + y * other.y);
	}

	std::ostream & operator<< (std::ostream & os, const vec2 & other) {
		os << '(' << other.x << ',' << other.y << ')';
		return os;
	}

	std::istream & operator>> (std::istream & is, vec2 & other) {
		is >> other.x;
		is >> other.y;
		return is;
	}

	std::stringstream & operator>> (std::stringstream & is, vec2 & other) {
		is >> other.x;
		is >> other.y;
		return is;
	}

	void vec2::clean() {
		if (x > -1e-5 && x < 1e-5) x = 0;
		if (y > -1e-5 && y < 1e-5) y = 0;
	}

	/*-----------  VEC3 ------------*/

	vec3::vec3() {
		x = 0;
		y = 0;
		z = 0;
	}

	vec3::~vec3() {}

	vec3::vec3(const float xI, const float yI, const float zI) {
		x = xI;
		y = yI;
		z = zI;
	}

	vec3::vec3(const vec3 & v) 
	{
		x = v.x;
		y = v.y;
		z = v.z;
	}
	vec3 & vec3::operator= (const vec3 & v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
		return *this;
	}

	const vec3 operator+ (const vec3 & v1, const vec3 & v2) {
		return vec3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
	}

	const vec3 operator- (const vec3 & v1, const vec3 & v2) {
		return vec3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
	}

	const vec3 operator* (const vec3 & v, const float k) {
		return vec3(v.x * k, v.y * k, v.z * k);
	}

	const vec3 operator* (const float k, const vec3 & v) {
		return vec3(v.x * k, v.y * k, v.z * k);
	}

	void operator+= (vec3 & v1, const vec3 & v2) 
	{
		v1 = v1 + v2;
	}
	
	void operator-= (vec3 & v1, const vec3 & v2)
	{
		v1 = v1 - v2;
	}

	void operator*= (vec3 & v, const float k)
	{
		v = v * k;
	}

	const bool operator== (const vec3 & v1, const vec3 & v2) 
	{
		return equalFloats(v1.x, v2.x) && equalFloats(v1.y, v2.y) && equalFloats(v1.z, v2.z);
		//return v1.x == v2.x && v1.y == v2.y && v1.z == v2.z;
	}

	const bool operator!= (const vec3 & v1, const vec3 & v2)
	{
		return !(v1 == v2);
	}

	const vec3 lerp(const vec3 & v0, const vec3 & v1, const float k)
	{
		return (1 - k)*v0 + k*v1;
	}

	const vec3 slerp(const vec3 & v0, const vec3 & v1, const float k)
	{
		vec3 vn0 = v0.normalize();
		vec3 vn1 = v1.normalize();

		float angle = acos(vn0.dot(vn1));
		float k0 = sin((1 - k)*angle) / sin(angle);
		float k1 = sin(k*angle) / sin(angle);
		
		return k0 * v0 + k1 * v1;
	}

	float vec3::quadrance() const{
		return x*x + y*y + z*z; 
	}

	float vec3::norm() const{
		return sqrt(quadrance());
	}
	const vec3 vec3::normalize() const{
		float n = norm();
		vec3 v = vec3();
		if (n != 0) {
			v.x = x / n;
			v.y = y / n;
			v.z = z / n;
		}
		return v;
	}

	const vec3 vec3::cross(const vec3 & other) const {
		return vec3(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
	}

	float vec3::dot(const vec3 & other) const {
		return (x * other.x + y * other.y + z * other.z);
	}

	std::ostream & operator<< (std::ostream & os, const vec3 & other) {
		os << '(' << other.x << ',' << other.y << ',' << other.z << ')';
		return os;
	}

	std::istream & operator>> (std::istream & is, vec3 & other) {
		is >> other.x;
		is >> other.y;
		is >> other.z;
		return is;
	}

	std::stringstream & operator>> (std::stringstream & is, vec3 & other) {
		is >> other.x;
		is >> other.y;
		is >> other.z;
		return is;
	}

	void vec3::clean() {
		if( x > -1e-5 && x < 1e-5) x = 0;
		if (y > -1e-5 && y < 1e-5) y = 0;
		if (z > -1e-5 && z < 1e-5) z = 0;
	}

	/*-----------  VEC4 ------------*/

	vec4::vec4() {
		x = 0;
		y = 0;
		z = 0;
		w = 0;
	}

	vec4::~vec4() {}

	vec4::vec4(const float xI, const float yI, const float zI, const float wI) {
		x = xI;
		y = yI;
		z = zI;
		w = wI;
	}

	vec4::vec4(const vec4 & v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
		w = v.w;
	}
	vec4 & vec4::operator= (const vec4 & v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
		w = v.w;
		return *this;
	}

	const vec4 operator+ (const vec4 & v1, const vec4 & v2) {
		return vec4(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w);
	}

	const vec4 operator- (const vec4 & v1, const vec4 & v2) {
		return vec4(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w);
	}

	const vec4 operator* (const vec4 & v, const float k) {
		return vec4(v.x * k, v.y * k, v.z * k, v.w * k);
	}

	const vec4 operator* (const float k, const vec4 & v) {
		return v * k;
	}

	void operator+= (vec4 & v1, const vec4 & v2)
	{
		v1 = v1 + v2;
	}

	void operator-= (vec4 & v1, const vec4 & v2)
	{
		v1 = v1 - v2;
	}

	void operator*= (vec4 & v, const float k)
	{
		v = v * k;
	}

	const bool operator== (const vec4 & v1, const vec4 & v2)
	{
		return equalFloats(v1.x, v2.x) && equalFloats(v1.y, v2.y) && equalFloats(v1.z, v2.z) && equalFloats(v1.w, v2.w);
		//return v1.x == v2.x && v1.y == v2.y && v1.z == v2.z && v1.w == v2.w;
	}

	const bool operator!= (const vec4 & v1, const vec4 & v2)
	{
		return !(v1 == v2);
	}

	float vec4::quadrance() const{
		return x*x + y*y + z*z; //FIXME
	}

	float vec4::norm() const{
		return sqrt(quadrance());
	}
	const vec4 vec4::normalize() const {
		vec4 vn;
		float s = 1 / (w * norm());
		vn.x = x * s;
		vn.y = y * s;
		vn.z = z * s;
		vn.w = 1.0f;
		return vn;
	}

	/*vec4 vec4::cross(const vec4 & other) {
		vec4 * tmp = new vec4(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
		return *tmp;
	}*/

	float vec4::dot(const vec4 & other) const{
		return (x * other.x + y * other.y + z * other.z + w * other.w);
	}

	std::ostream & operator<< (std::ostream & os, const vec4 & other) {
		os << '(' << other.x << ',' << other.y << ',' << other.z << ',' << other.w << ')';
		return os;
	}

	std::istream & operator>> (std::istream & is, vec4 & other) {
		is >> other.x;
		is >> other.y;
		is >> other.z;
		is >> other.w;
		return is;
	}

	std::stringstream & operator>> (std::stringstream & is, vec4 & other) {
		is >> other.x;
		is >> other.y;
		is >> other.z;
		is >> other.w;
		return is;
	}

	void vec4::clean() {
		if (x > -1e-5 && x < 1e-5) x = 0;
		if (y > -1e-5 && y < 1e-5) y = 0;
		if (z > -1e-5 && z < 1e-5) z = 0;
		if (w > -1e-5 && w < 1e-5) w = 0;
	}
}
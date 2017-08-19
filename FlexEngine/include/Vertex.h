#pragma once

#include <vector>

#include <glm\vec2.hpp>
#include <glm\vec3.hpp>
#include <glm\vec4.hpp>
#include <glm\gtc\quaternion.hpp>

//struct VertexPosCol
//{
//	VertexPosCol() {};
//	VertexPosCol(float x, float y, float z, float r, float g, float b, float a) : pos{ x, y, z }, col{ r, g, b, a } {}
//	VertexPosCol(float x, float y, float z, const float col[4]) : pos{ x, y, z }, col{ col[0], col[1], col[2], col[3] } {}
//	VertexPosCol(const float pos[3], const float col[4]) : pos{ pos[0], pos[1], pos[2] }, col{ col[0], col[1], col[2], col[3] } {}
//	VertexPosCol(glm::vec3 pos, glm::vec4 col) : pos(pos), col(col) {}
//
//	static const int stride = 3 * sizeof(float) + 4 * sizeof(float);
//	glm::vec3 pos;
//	glm::vec4 col;
//};
//
//struct VertexPosColTex
//{
//	VertexPosColTex() {};
//	VertexPosColTex(float x, float y, float z, float r, float g, float b, float u, float v) : pos{ x, y, z }, col{ r, g, b }, uv(u, v) {}
//	VertexPosColTex(float x, float y, float z, const float col[3], float uv[2]) : pos{ x, y, z }, col{ col[0], col[1], col[2] }, uv{ uv[0], uv[1] } {}
//	VertexPosColTex(glm::vec3 pos, glm::vec3 col, glm::vec2 uv) : pos{ pos[0], pos[1], pos[2] }, col{ col[0], col[1], col[2] }, uv(uv) {}
//
//	static const int stride = 3 * sizeof(float) + 3 * sizeof(float);
//	glm::vec3 pos;
//	glm::vec3 col;
//	glm::vec2 uv;
//};

//struct VertexPosColUV
//{
//	VertexPosColUV() {};
//	VertexPosColUV(float x, float y, float z, float w, float r, float g, float b, float a, float u, float v) : pos{ x, y, z, w }, col{ r, g, b, a }, uv{ u, v } {}
//	VertexPosColUV(float x, float y, float z, float w, const float col[4], float u, float v) : pos{ x, y, z, w }, col{ col[0], col[1], col[2], col[3] }, uv{ u, v } {}
//	VertexPosColUV(float x, float y, float z, float w, glm::vec4, float u, float v) : pos{ x, y, z, w }, col{ col[0], col[1], col[2], col[3] }, uv{ u, v} {}
//	VertexPosColUV(const float pos[4], const float col[4], const float uv[2]) : pos{ pos[0], pos[1], pos[2], pos[3] }, col{ col[0], col[1], col[2], col[3] }, uv{ uv[0], uv[1] } {}
//	VertexPosColUV(glm::vec4 pos, glm::vec4 col, glm::vec2 uv) : pos{ pos[0], pos[1], pos[2], pos[3] }, col{ col[0], col[1], col[2], col[3] }, uv { uv[0], uv[1] } {}
//
//	static const int stride = 4 * sizeof(float) + 4 * sizeof(float) + 2 * sizeof(float);
//	float pos[4];
//	float col[4];
//	float uv[2];
//};
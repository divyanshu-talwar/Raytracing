#version 330
layout(location=0) in vec2 coord2d;
out vec2 fTexCoord;

void main(void) {
	gl_Position = vec4(coord2d, 0.0, 1.0);
	fTexCoord = (coord2d + 1)/2;
}

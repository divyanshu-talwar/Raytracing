#version 330

uniform sampler2D texImage;
in vec2 fTexCoord;
out vec4 color;
void main(void) {
	color = texture(texImage, fTexCoord);
//	color = vec4(0.5,0.5,0.5,1.0);



}

#version 120

uniform sampler2DRect tex0;

uniform vec4 iMouse;
uniform vec3 iResolution;
uniform float iGlobalTime;

varying vec2 texCoordVarying;

void main()
{

    float r = gl_FragCoord.x / iResolution.x;
    float g = gl_FragCoord.y / iResolution.y;
    float b = 1.0;
    float a = 1.0;
	gl_FragColor = vec4(r, g, b, a);

//    gl_FragColor = texture2DRect(tex0, texCoordVarying);
}

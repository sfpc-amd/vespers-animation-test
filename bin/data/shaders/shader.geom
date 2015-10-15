//GEOMETRY SHADER
 #version 120
//  #extension GL_ARB_geometry_shader4 : enable
// https://www.opengl.org/wiki/Geometry_Shader_Examples

uniform vec4 iMouse;
uniform vec3 iResolution;
uniform float iGlobalTime;

uniform int moireAmount;
uniform int moireSpacing;

 ///////////////////////
 void main()
 {
   //increment variable
   int i;
   int j;
   vec4 vertex;
   /////////////////////////////////////////////////////////////
   //This example has two parts
   //	step a) draw the primitive pushed down the pipeline
   //		 there are gl_VerticesIn # of vertices
   //		 put the vertex value into gl_Position
   //		 use EmitVertex => 'create' a new vertex
   // 		use EndPrimitive to signal that you are done creating a primitive!
   //	step b) create a new piece of geometry
   //		I just do the same loop, but I negate the vertex.z
   //	result => the primitive is now mirrored.
   //Pass-thru!

   for(i = 0; i < gl_VerticesIn; i++)
   {
     gl_Position = gl_PositionIn[i];
     EmitVertex();
     
   }
   EndPrimitive();
   //New piece of geometry!
    for(j=0; j < moireAmount; j++) {

   for(i = 0; i < gl_VerticesIn; i++)
   {
            vertex = gl_PositionIn[i];

            vertex = vertex + vec4(
                j*moireSpacing*0.1,
                j*moireSpacing*0.1,
                0.0,
            0.0);

            gl_Position = vertex;
            EmitVertex();
        }
   EndPrimitive();

   }
 }
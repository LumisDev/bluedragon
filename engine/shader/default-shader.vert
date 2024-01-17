#version 450
vec2 positions[3] = vec2[](
    vec2(-1.0, -1.0),  // Vertex 0
    vec2(1.0, -1.0),   // Vertex 1
    vec2(0.0, 1.0)     // Vertex 2
);

void main(){
    gl_Position = vec4(positions[gl_VertexID], 0, 1.0);
}
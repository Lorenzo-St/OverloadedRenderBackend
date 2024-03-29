#pragma once
#include <glm.hpp>
#include <vector>
#include <string>
#include "Stream.h"
#include "Vertex.h"

struct ORB_Mesh 
{
public:

  virtual ~ORB_Mesh();
  ORB_Mesh(int mode, std::vector<Vertex>&& verts, glm::vec4 col) : _drawMode(mode), _verticies(verts), _color(col) {};
  ORB_Mesh() = default;
  virtual void Read(std::string file);
  virtual void Read(Stream& file);
  virtual void Execute() const {};

  glm::vec4 const& Color() const;
  glm::vec4 & Color();

  void AddVertex(Vertex const&);
  std::vector<Vertex> const& Verticies() const;

  GLuint DrawMode() const;
  GLuint& DrawMode();

  
private:
  GLuint _drawMode = 6;
  std::vector<Vertex> _verticies;
  glm::vec4 _color = {1,1,1,1};
};


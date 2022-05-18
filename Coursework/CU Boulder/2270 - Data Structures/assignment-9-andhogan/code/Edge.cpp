#include "Edge.h"

Edge::Edge(shared_ptr<Node> n1, shared_ptr<Node> n2) {
  // DONE FOR YOU
  begin = n1;
  end = n2;
}

Edge::~Edge() {
  // "DONE" FOR YOU
}


shared_ptr<Node> Edge::getStart() {
  // DONE FOR YOU
  return begin;
}

shared_ptr<Node> Edge::getEnd() {
  // DONE FOR YOU
  return end;
}

int Edge::getType() {
  // DONE FOR YOU
  return type;
}

void Edge::setType(int edge_type) {
  this->type = edge_type;
}

// overloading operator << lets you put an Edge object into an output stream.
ostream &operator << (std::ostream& out, Edge edge) {
  // DONE FOR YOU
  out << *edge.begin << " -- " << *edge.end;
  return out;
}
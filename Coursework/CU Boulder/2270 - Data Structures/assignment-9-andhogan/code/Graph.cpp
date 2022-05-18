#include "Graph.h"

#include <iostream>
#include <sstream>

using namespace std;

// fwd declarations
string make_dot(Graph* g);
string what(int& v);

Graph::Graph() {
  // DONE FOR YOU
  directed = false; // graphs are undirected by default
}

Graph::~Graph() {
  // "DONE" FOR YOU
  // no implementation needed
}

vector<shared_ptr<Node>> Graph::getNodes() {
  // DONE FOR YOU
  return nodes;
}

vector<shared_ptr<Edge>> Graph::getEdges() {
  // DONE FOR YOU
  return edges;
}

int Graph::getClock() {
  // DONE FOR YOU
  return clock;
}

void Graph::addNode(shared_ptr<Node> n) {
  // DONE FOR YOU
  nodes.push_back(n);
}

void Graph::addEdge(shared_ptr<Edge> e) {
  // DONE FOR YOU
  edges.push_back(e);
}
 
void Graph::removeNode(shared_ptr<Node> n) {
  // DONE FOR YOU
  for (vector<shared_ptr<Node>>::iterator it = nodes.begin(); it != nodes.end(); it++) {
    if (n == *it) {
      nodes.erase(it);
      break;
    }
  }
}
 
void Graph::removeEdge(shared_ptr<Edge> e) {
  // DONE FOR YOU
  for (vector<shared_ptr<Edge>>::iterator it = edges.begin();
       it != edges.end(); 
       it++) {
    if (e == *it) {
      edges.erase(it);
      break;
    }
  }
}

void Graph::setDirected(bool val) {
  // DONE FOR YOU
  directed = val;
}

bool Graph::isDirected() {
  // DONE FOR YOU
  return directed;
}

set<shared_ptr<Edge>> Graph::getAdjacentEdges(shared_ptr<Node> n) {
  // DONE FOR YOU
  set<shared_ptr<Edge>> ret;
  for (vector<shared_ptr<Edge>>::iterator it = edges.begin(); it != edges.end(); it++) {
    shared_ptr<Edge> edge = *it;
    if (edge->getStart() == n) {
      ret.insert(edge);
    }
    if (!directed && (edge->getEnd() == n)) {
      ret.insert(edge);
    }
  }
  return ret;
}

void Graph::clear() {
  clock = 0;
  // nodes is vector<Node*>
  // for (size_t i = 0; i < nodes.size(); i++) {
  // Node* n = nodes[i];
  // }
  vector<shared_ptr<Node>>::iterator it = nodes.begin();
  for (;it != nodes.end(); it++) {
    shared_ptr<Node> n = *it;
    n->clear();
  }
  vector<shared_ptr<Edge>>::iterator eit = edges.begin();
  for (;eit != edges.end(); eit++) {
    shared_ptr<Edge> e = *eit;
    e->setType(UNDISCOVERED_EDGE);
  }
}

void Graph::tick(string message) {
  // DONE FOR YOU
  //
  // optional debugging function, disabled with if(false) to prevent
  // unused var warning. Change this however you want.
  //
  // recommended use: call it just after incrementing the clock.
  if (false) {
    cout << "// " << message << endl << make_dot(this) << endl;
  }
}

void Graph::dfs(shared_ptr<Node> start) {
  //mark the node being started as GRAY
  start->setColor(GRAY, clock);

  //Create a set of adjacent edges to iterate through
  set<shared_ptr<Edge>> adjEdges = getAdjacentEdges(start);
  set<shared_ptr<Edge>>::iterator edgeit;

  //iterate through the set of edges
  for (edgeit = adjEdges.begin(); edgeit != adjEdges.end(); edgeit++)
  { //within each iteration, create a current edge from one of the edges in the set
      shared_ptr<Edge> curr_edge = *edgeit;
      if (start == curr_edge->getStart() && 
      (curr_edge->getEnd()->getColor() == GRAY || curr_edge->getEnd()->getColor() == BLACK))
      {//If statement adds typing to the edge
       //Checks: If the inserted start node is the same as the edge.start, come through here
       //Then check whether the end nodes have been encountered to set an appropriate typing for the edge.
          if (curr_edge->getStart()->isAncestor(curr_edge->getEnd()))
          { //If A is an ancestor of C, and C was fully explored,
            //then this is a forward edge from A to C
            curr_edge->setType(FORWARD_EDGE);
          }
          else 
          { //If A is not an ancestor of C, and C was fully explored,
            //then this is a cross edge.
            curr_edge->setType(BACK_EDGE);
          }
      }
      if (!directed && start == curr_edge->getEnd() && 
      (curr_edge->getStart()->getColor() == GRAY || curr_edge->getEnd()->getColor() == BLACK))
      { //If statement adds typing to the edge
        //Checks: If the graph is undirected, and inserted start node is the edge.end, come through here
        //Then check whether the start nodes have been encountered to set the typing.

          if (curr_edge->getEnd()->getRank() > curr_edge->getStart()->getRank())
          {//Rank is the level in a spanning tree that a node was found in
           //If the end rank is higher, this means A was discovered before C, and C was discovered while A is still GRAY
           //This is a back edge.
            curr_edge->setType(BACK_EDGE);
          }
          else 
          {//If an edge exists between A and C, and C was completely examined while A was still being searched,
           //This is a forward edge.
              curr_edge->setType(FORWARD_EDGE);
          }
      }
      if (start == curr_edge->getStart() && curr_edge->getEnd()->getColor() == WHITE)
      {//If at the starting vertex, and the end vertex is white, set normal tree edge, and recursively call on the end.
          curr_edge->setType(TREE_EDGE);
          curr_edge->getEnd()->setPredecessor(start);
          clock++;
          dfs(curr_edge->getEnd());
      }
      else if (!directed && start == curr_edge->getEnd() && curr_edge->getStart()->getColor() == WHITE)
      {//
          curr_edge->setType(CROSS_EDGE);
          curr_edge->getStart()->setPredecessor(start);
          clock++;
          dfs(curr_edge->getStart());
      }
  }
  clock++;
  start->setColor(BLACK, clock);
}

void Graph::bfs(shared_ptr<Node> start) {
  clear();
  vector<shared_ptr<Node>> queue;
  shared_ptr<Node> current = start;
  queue.insert(queue.begin() +0, start);
  start->setColor(GRAY, clock);
  start->setRank(0);
  set<shared_ptr<Edge>> ret;
  while (queue.size()>0)
  { //Iterate while nodes are still queued.
    current = queue.back();
    clock++;
    current->setColor(BLACK, clock);
    if (current->getPredecessor())
    {//If statement skipped on first iteration because we are at the starting node, and has no predecessor.
     //Each node after will have a pred and will set its rank based on the pred's rank.
        current->setRank(current->getPredecessor()->getRank() + 1);
    }
    queue.pop_back(); //pops current BLACK node from the stack, 
    //and proceeds to find another node from an adjacent edge. 
    ret = getAdjacentEdges(current);
    set<shared_ptr<Edge>>::iterator it;
    for (it = ret.begin(); it != ret.end(); it++)
    {//iterate through the set of current's adjacent edges
        shared_ptr<Edge> ter = *it; //select an edge from the set to analyze
        if (current == ter->getStart() && ter->getEnd()->getColor() == WHITE)
        {//If the node on the opposite end is WHITE, we have not visited it yet.
         //Insert it into the queue, mark it GRAY, and set its predecessor so that we can trace back.
         //If the node is GRAY or BLACK, we never enter these if statements: it would be redundant to do so. 
            queue.insert(queue.begin() + 0, ter->getEnd());
            clock++;
            ter->setType(TREE_EDGE);
            ter->getEnd()->setColor(GRAY, clock);
            ter->getEnd()->setPredecessor(current);
        }
        else if (directed && current == ter->getEnd() && ter->getStart()->getColor() == WHITE)
        {
            queue.insert(queue.begin() + 0, ter->getStart());
            clock++;
            ter->setType(TREE_EDGE);
            ter->getStart()->setColor(GRAY, clock);
            ter->getStart()->setPredecessor(current);
        }
        
    } 
    /*
    After all edges for the current node have been analyzed and marked GRAY, 
    we return to the beginning of while, pop another node from the stack and mark it BLACK, 
    look at its edges and mark unvisited nodes GRAY, add more nodes to the queue, 
    and continue until the queue is empty.
    */
  }
}

void Graph::bfs(shared_ptr<Node> start, shared_ptr<Node> finish) {
  clear();
  vector<shared_ptr<Node>> queue;
  shared_ptr<Node> current = start;
  queue.insert(queue.begin() +0, start);
  start->setColor(GRAY, clock);
  start->setRank(0);
  set<shared_ptr<Edge>> ret;
  while (queue.size()>0){
    current = queue.back();
    clock++;
    current->setColor(BLACK, clock);
    if (current->getPredecessor()){
        current->setRank(current->getPredecessor()->getRank() + 1);
    }
    queue.pop_back();
    if (current == finish)
    { //for this particular bfs, we're searching for a particular node. 
      //Once it has been found, we can return from the function.
        return;
    }
    ret = getAdjacentEdges(current);
    set<shared_ptr<Edge>>:: iterator it;
    for (it = ret.begin(); it != ret.end(); it++){
        shared_ptr<Edge> ter = *it;
        if (current == ter->getStart() && ter->getEnd()->getColor() == WHITE){
            queue.insert(queue.begin() + 0, ter->getEnd());
            clock++;
            ter->getEnd()->setColor(GRAY, clock);
            ter->getEnd()->setPredecessor(current);
        }
        else if (current == ter->getEnd() && ter->getStart()->getColor() == WHITE){
            queue.insert(queue.begin() + 0, ter->getStart());
            clock++;
            ter->getStart()->setColor(GRAY, clock);
            ter->getStart()->setPredecessor(current);
        }
    }
  }
}


// overloading operator << lets you put a Graph object into an output
// stream.
ostream &operator << (ostream& out, Graph graph) {
  // DONE FOR YOU
  out << graph.nodes.size() << " Nodes:" << endl;
  out << "[";
  for (vector<shared_ptr<Node>>::iterator it = graph.nodes.begin(); it != graph.nodes.end(); it++) {
    shared_ptr<Node> n = *it;
    out << *n << ", ";
  }
  out << "]" << endl;
  out << graph.edges.size() << " Edges:" << endl;
  out << "[";
  for (vector<shared_ptr<Edge>>::iterator it = graph.edges.begin(); it != graph.edges.end(); it++) {
    shared_ptr<Edge> e = *it;
    out << *e << ", ";
  }
  out << "]";
  return out;
}

// what is a helper function that turns a constant (e.g. WHITE or
// FORWARD_EDGE) into a string for debugging goodness. 
string what(int& v) {
  // DONE FOR YOU
  string ret = "Unknown";
  if (v == WHITE) {
    ret = "white";
  } else if (v == GRAY) {
    ret = "gray";
  } else if (v == BLACK) {
    ret = "black";
  } else if (v == UNDISCOVERED_EDGE) {
    ret = "undiscovered";
  } else if (v == TREE_EDGE) {
    ret = "tree";
  } else if (v == BACK_EDGE) {
    ret = "back";
  } else if (v == FORWARD_EDGE) {
    ret = "forward";
  } else if (v == CROSS_EDGE) {
    ret = "cross";
  }
  return ret;
}

// make_dot generates a dotfile string for viewing your graph. Have
// tick() print out the results of this function, and then use
// http://www.webgraphviz.com/ (or get a copy of GraphViz) to view the
// result. If you're stuck, this can help you get un-stuck.
string make_dot(Graph* g) {
  // DONE FOR YOU
  stringstream ss;
  vector<shared_ptr<Node>> nodes = g->getNodes();
  vector<shared_ptr<Edge>> edges = g->getEdges();
  string gt = "graph";
  string con = "--";
  if (g->isDirected()) {
    con = "->";
    gt = "digraph";
  }
  ss << gt << " homework {" << endl;
  int c, dt, ft, r;
  string textColor = "black";
  for (auto it=nodes.begin(); it != nodes.end(); ++it) {
    shared_ptr<Node> n = *it;
    n->getDiscoveryInformation(c, dt, ft, r);
    if (c == BLACK) {
      textColor = "white";
    } else {
      textColor = "black";
    }
    ss << "  " << n->getData() << " [ style=\"filled\" fontcolor=\"" << textColor << "\" fillcolor=\"" << what(c) << "\"" << " ]" << endl;
  }
  
  string edgeColor = "black";
  for (auto it=edges.begin(); it != edges.end(); ++it) {
    shared_ptr<Edge> e = *it;
    if (e->getType() == TREE_EDGE) {
      edgeColor = "black";
    } else if (e->getType() == FORWARD_EDGE) {
      edgeColor = "purple";
    } else if (e->getType() == BACK_EDGE) {
      edgeColor = "blue";
    } else if (e->getType() == CROSS_EDGE) {
      edgeColor = "green";
    } else {
      edgeColor = "gray";
    }
    ss << "  " << e->getStart()->getData() << con << e->getEnd()->getData() << " [color=\"" << edgeColor << "\"]" << endl;
  }
  ss << "}" << endl;
  return ss.str();
}
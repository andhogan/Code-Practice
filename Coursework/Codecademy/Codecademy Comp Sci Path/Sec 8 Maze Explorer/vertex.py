class Vertex:
  def __init__(self, value):
    self.value = value
    self.edges = {}

  def add_edge(self, adjacent_value, weight = 0):
    # adjacent_value = the self.value of the Vertex being connected
    self.edges[adjacent_value] = weight

  def get_edges(self):
    return self.edges.keys()
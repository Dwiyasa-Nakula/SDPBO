import networkx as nx
import matplotlib.pyplot as plt
import numpy as np

# Define the adjacency matrix
adjacency_matrix = np.array([
    [0, 1, 0, 0, 1],
    [1, 0, 1, 1, 1],
    [0, 1, 1, 1, 0],
    [0, 1, 1, 0, 1],
    [1, 1, 0, 1, 0]
])

# Create a NetworkX graph from the adjacency matrix
G = nx.Graph()
G.add_nodes_from(range(len(adjacency_matrix)))

for i in range(len(adjacency_matrix)):
    for j in range(i, len(adjacency_matrix)):
        if adjacency_matrix[i][j] > 0:
            G.add_edge(i, j, weight=adjacency_matrix[i][j])

# Plot the first graph
plt.figure(figsize=(8, 6))
pos = nx.spring_layout(G)  # Define the layout for the nodes
labels = {edge: G[edge[0]][edge[1]]['weight'] for edge in G.edges()}
nx.draw(G, pos, with_labels=True, node_size=500, node_color='skyblue', font_size=10)
nx.draw_networkx_edge_labels(G, pos, edge_labels=labels, font_size=10)
plt.title("Graph 1")
plt.show()

# Create a second graph by removing the edges with weight 1
G2 = G.copy()
edges_to_remove = [(u, v) for u, v, d in G.edges(data=True) if d['weight'] == 1]
G2.remove_edges_from(edges_to_remove)

# Plot the second graph
plt.figure(figsize=(8, 6))
labels2 = {edge: G2[edge[0]][edge[1]]['weight'] for edge in G2.edges()}
nx.draw(G2, pos, with_labels=True, node_size=500, node_color='lightcoral', font_size=10)
nx.draw_networkx_edge_labels(G2, pos, edge_labels=labels2, font_size=10)
plt.title("Graph 2 (Edges with weight 1 removed)")
plt.show()
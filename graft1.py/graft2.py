import networkx as nx
import matplotlib.pyplot as plt

# Define the degree sequence
degree_sequence_a = [3, 3, 5, 5, 5, 5]

# Check if a simple graph can be constructed
if sum(degree_sequence_a) % 2 == 0:
    G_a = nx.configuration_model(degree_sequence_a)
    G_a = nx.Graph(G_a)

    pos_a = nx.spring_layout(G_a)
    nx.draw(G_a, pos_a, with_labels=True, node_size=500, node_color='skyblue', font_size=10, font_color='black', font_weight='bold')
    plt.title("Graph with Degree Sequence [5, 2, 3, 2, 4]")
    plt.show()
else:
    print("No simple graph can be constructed with the given degree sequence.")

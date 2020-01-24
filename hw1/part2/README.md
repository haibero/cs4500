The implementation of the map takes each pair element in the map as a
node. Denoted in node.h. We chose a map for efficient element retrieval

- Files :
   - Node.h:
        - class: Node
        - This file holds the definition for our Node class. The Node class has been implemented to hold a key-value pair.
          We will can use each of these nodes to create whatever structure we would like. In this case, we are creating a map.
          We can also extend this out for linked lists and other implementation. We decided to keep the key type as String but
          to mimic maps in other languages.

    - Map.h:
        - class: Map
        - This file holds the definition of our Map class. The Map class has been implemented to hold an
          array of Node pointers. We can use this map to add nodes with key-value pairs and will be able to
          efficiently retrieve elements based on the key.

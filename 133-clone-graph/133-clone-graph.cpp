/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map <Node*, Node*> visited;
    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return node;
        
        //!= means end
        if(visited.find(node) != visited.end())
            return visited[node];
        
        Node* copy;
        copy = new Node(node->val, vector<Node*>());
        
        vector<Node*> n = node->neighbors;
        
        //add to visited
        visited[node] = copy;
        
        for(int i = 0; i < n.size(); i++){
            copy->neighbors.push_back(cloneGraph(n[i]));
        }
        
        return copy;
    }
};
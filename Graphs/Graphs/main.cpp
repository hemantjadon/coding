//
//  main.cpp
//  Graphs
//
//  Created by Hemant Jadon on 20/07/16.
//  Copyright (c) 2016 Hemant Jadon. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Label{
private:
    int data;
    
public:
    Label(int data):data(data)
    {}
    
    void setData(int data) {
        this->data=data;
    }
    
    int getData() const {
        return data;
    }
};

namespace Graph {
    
    class Graph{
    private:
        
        class Edge;     //  Forward Declaration of class Edge.
        
        class Vertex{
        private:
            bool visited;
            Label* label;
            
            vector<Edge*> OutEdges;
            vector<Edge*> InEdges;
            
        public:
            
            //  Constructor
            Vertex(Label* label):visited(false),label(label)
            {}
            
            
            //  Getters
            bool isVisited() const {
                return this->visited;
            }
            
            Label* getLabel() const {
                return this->label;
            }
            
            vector<Edge*> OutgoingEdges() const {
                return this->OutEdges;
            }
            
            vector<Edge*> IncomingEdges() const {
                return this->InEdges;
            }
            
            
            //  Setters
            void setVisited(bool visited){
                this->visited = visited;
            }
            
            
            //  Visit Changers
            void visit(){
                this->visited = true;
            }
            
            void unvisit(){
                this->visited = false;
            }
            
            void toggleVisited(){
                this->visited = !this->visited;
            }
            
            
            // Functions
            void addIncomingEdge(Edge* edge){
                this->InEdges.push_back(edge);
            }
            
            void addOutgoingEdge(Edge* edge){
                this->OutEdges.push_back(edge);
            }
            
            bool removeIncomingEdge(Edge* edge){
                for (int i=0; i<InEdges.size(); i++) {
                    if (InEdges[i] == edge) {
                        InEdges.erase(InEdges.begin() + i);
                        return true;
                    }
                }
                return false;
            }
            
            bool removeOutgoingEdge(Edge* edge){
                for (int i=0; i<OutEdges.size(); i++) {
                    if (OutEdges[i] == edge) {
                        OutEdges.erase(OutEdges.begin() + i);
                        return true;
                    }
                }
                return false;
            }
            
            long OutDeg(){
                return OutEdges.size();
            }
            
            long InDeg(){
                return InEdges.size();
            }
        };
        
        class Edge{
        private:
            static int INDEX;
            int weight;
            const Vertex* vertex1;
            const Vertex* vertex2;
            
        public:
            //  Constructor
            Edge(Vertex* vertex1,Vertex* vertex2,int weight=1):
            weight(weight),vertex1(vertex1),vertex2(vertex2)
            {}
            
            //  Setters
            void setWeight(int weight){
                this->weight = weight;
            }
            
            //  Getters
            int getWeight() const {
                return this->weight;
            }
            
            const Vertex* getVertex1() const {
                return vertex1;
            }
            
            const Vertex* getVertex2() const {
                return vertex2;
            }
        };
        
        const bool DIRECTED;
        
        
        vector<Vertex*> VertexSet;
        vector<Edge*> EdgeSet;
        
    public:
        Graph(bool DIRECTED=false):DIRECTED(DIRECTED)
        {}
        
        bool isDirected(){
            return this->DIRECTED;
        }
        
        vector<Edge*> getEdgeSet(){
            return this->getEdgeSet();
        }
        
        vector<Vertex*> getVertexSet(){
            return this->getVertexSet();
        }
        
        bool isEmpty(){
            return VertexSet.size() ? 0 : 1;
        }
        
        long size(){
            return VertexSet.size();
        }
        
        Vertex* ContainsVertex(Vertex* vertex){
            for (long i=0; i<VertexSet.size(); i++) {
                if (VertexSet[i] == vertex) {
                    return vertex;
                }
            }
            return NULL;
        }
        
        Vertex* ContainsVertex(const Vertex* vertex){
            for (long i=0; i<VertexSet.size(); i++) {
                if (VertexSet[i] == vertex) {
                    return VertexSet[i];
                }
            }
            return NULL;
        }
        
        Vertex* ContainsVertex(Label* label){
            for (long i=0; i<VertexSet.size(); i++) {
                if (VertexSet[i]->getLabel() == label) {
                    return VertexSet[i];
                }
            }
            return NULL;
        }
        
        Vertex* ContainsVertex(int LabelData){
            for (long i=0; i<VertexSet.size(); i++) {
                if (VertexSet[i]->getLabel()->getData() == LabelData) {
                    return VertexSet[i];
                }
            }
            return NULL;
        }
        
        Vertex* AddVertex(Vertex* vertex){
            if (ContainsVertex(vertex)) {
                return vertex;
            }
            
            VertexSet.push_back(vertex);
            return vertex;
        }
        
        Vertex* AddVertex(Label* label){
            Vertex* vertex = ContainsVertex(label);
            if (vertex) {
                return vertex;
            }
            
            vertex = new Vertex(label);
            VertexSet.push_back(vertex);
            return vertex;
        }
        
        Vertex* AddVertex(int LabelData){
            Vertex* vertex = ContainsVertex(LabelData);
            if (vertex) {
                return vertex;
            }
            
            Label* label = new Label(LabelData);
            vertex = new Vertex(label);
            VertexSet.push_back(vertex);
            return vertex;
        }
        
        Edge* ContainsEdge(Edge* edge){
            for (long i=0; i<EdgeSet.size(); i++) {
                if (EdgeSet[i] == edge) {
                    return edge;
                }
            }
            return NULL;
        }
        
        Edge* ContainsEdge(Vertex* vertex1, Vertex* vertex2,bool vertex_existance_checked=false){
            if (!vertex_existance_checked) {
                if (!ContainsVertex(vertex1) || !ContainsVertex(vertex2)) {
                    return NULL;
                }
            }
            
            vector<Edge*> out_edges_v1 = vertex1->OutgoingEdges();
            for (long i=0; i<out_edges_v1.size(); i++) {
                if(out_edges_v1[i]->getVertex2() == vertex2){
                    return out_edges_v1[i];
                }
            }
            return NULL;
        }
        
        Edge* ContainsEdge(int LabelData1,int LabelData2){
            Vertex* vertex1 = ContainsVertex(LabelData1);
            Vertex* vertex2 = ContainsVertex(LabelData2);
            
            if (!vertex1 || !vertex2) {
                return NULL;
            }
            
            return ContainsEdge(vertex1, vertex2,true);
        }
        
        Edge* AddEdge(Edge* edge,int weight=1){
            if (ContainsEdge(edge)) {
                return edge;
            }
            
            const Vertex* vertex1 = edge->getVertex1();
            const Vertex* vertex2 = edge->getVertex2();
            
            Vertex* v1 = ContainsVertex(vertex1);
            Vertex* v2 = ContainsVertex(vertex2);
            
            if (v1 && v2) {
                Edge* edge = new Edge(v1,v2,weight);
                EdgeSet.push_back(edge);
                if (this->isDirected()) {
                    v1->addOutgoingEdge(edge);
                    v2->addIncomingEdge(edge);
                }
                
                else{
                    v1->addOutgoingEdge(edge);
                    v1->addIncomingEdge(edge);
                    v2->addIncomingEdge(edge);
                    v2->addOutgoingEdge(edge);
                }
                return edge;
            }
            return NULL;
        }
        
        Edge* AddEdge(Vertex* vertex1,Vertex* vertex2,int weight){
            if (ContainsVertex(vertex1) && ContainsVertex(vertex2)) {
                Edge* edge = ContainsEdge(vertex1, vertex2, true);
                if (edge) {
                    return edge;
                }
                
                edge = new Edge(vertex1,vertex2,weight);
                EdgeSet.push_back(edge);
                if (this->isDirected()) {
                    vertex1->addOutgoingEdge(edge);
                    vertex2->addIncomingEdge(edge);
                }
                
                else{
                    vertex1->addOutgoingEdge(edge);
                    vertex1->addIncomingEdge(edge);
                    vertex2->addIncomingEdge(edge);
                    vertex2->addOutgoingEdge(edge);
                }
                return edge;
            }
            return NULL;
        }
        
        Edge* AddEdge(int LabelData_1, int LabelData_2,int weight=1){
            Vertex* vertex1 = ContainsVertex(LabelData_1);
            Vertex* vertex2 = ContainsVertex(LabelData_2);
            
            if (vertex1 && vertex2) {
                return AddEdge(vertex1,vertex2,weight);
            }
            
            return NULL;
        }
        
        void DeleteEdge(Edge* edge,bool edge_existance_checked=false){
            if (!edge_existance_checked) {
                edge = ContainsEdge(edge);
            }
            if (edge) {
                const Vertex* vertex1 = edge->getVertex1();
                const Vertex* vertex2 = edge->getVertex2();
                
                Vertex* v1 = ContainsVertex(vertex1);
                Vertex* v2 = ContainsVertex(vertex2);
                if (this->isDirected()) {
                    v1->removeOutgoingEdge(edge);
                    v2->removeIncomingEdge(edge);
                }
                else {
                    v1->removeOutgoingEdge(edge);
                    v1->removeIncomingEdge(edge);
                    v2->removeIncomingEdge(edge);
                    v2->removeOutgoingEdge(edge);
                }
                for (long i=0; i<EdgeSet.size(); i++) {
                    if (EdgeSet[i] == edge) {
                        EdgeSet.erase(EdgeSet.begin()+i);
                        break;
                    }
                }
                delete edge;
            }
        }
        
        void DeleteEdge(Vertex* vertex1,Vertex* vertex2,bool edge_existance_checked=false){
            Edge* edge = ContainsEdge(vertex1, vertex2);
            
            if (edge) {
                DeleteEdge(edge);
            }
        }
        
        void DeleteEdge(int LabelData_1,int LabelData_2){
            Edge* edge = ContainsEdge(LabelData_1, LabelData_2);
            
            if (edge) {
                DeleteEdge(edge);
            }
        }
        
        void DeleteVertex(Vertex* vertex,bool vertex_existance_checked=false){
            if (!vertex_existance_checked) {
                vertex = ContainsVertex(vertex);
            }
            
            if (vertex) {
                if (this->isDirected()) {
                    while (vertex->OutgoingEdges().size()) {
                        DeleteEdge(vertex->OutgoingEdges()[0],true);
                    }
                    while (vertex->IncomingEdges().size()) {
                        DeleteEdge(vertex->IncomingEdges()[0],true);
                    }
                }
                else {
                    while (vertex->OutgoingEdges().size()) {
                        DeleteEdge(vertex->OutgoingEdges()[0],true);
                    }
                }
                for (long i=0; i<VertexSet.size(); i++) {
                    if (VertexSet[i] == vertex) {
                        VertexSet.erase(VertexSet.begin() + i);
                    }
                }
                delete vertex;
            }
        }
        
        void DeleteVertex(Label* label){
            Vertex* vertex = ContainsVertex(label);
            DeleteVertex(vertex,true);
        }
        
        void DeleteVertex(int LabelData){
            Vertex* vertex = ContainsVertex(LabelData);
            DeleteVertex(vertex,true);
        }
        
        void Clear(){
            while (VertexSet.size()) {
                DeleteVertex(VertexSet[0]);
            }
        }
        
        void ClearEdges(){
            while (EdgeSet.size()) {
                DeleteEdge(EdgeSet[0]);
            }
        }
        
    };
}



int main(int argc, const char * argv[]) {
    Graph::Graph g(false);
    g.AddVertex(1);
    g.AddVertex(2);
    g.AddVertex(3);
    g.AddVertex(4);
    g.AddVertex(5);
    g.AddEdge(1, 2);
    g.AddEdge(2, 3);
    g.AddEdge(3, 4);
    g.AddEdge(4, 5);
    g.AddEdge(5, 1);
    g.AddEdge(1, 3);
    g.AddEdge(2, 4);
    g.ClearEdges();
}

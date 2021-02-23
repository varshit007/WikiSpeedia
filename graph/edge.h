/**
 * @file edge.h
 * Definition and (minimal) implementation of an edge class; used by the Graph class
 * @author Sean Massung, @date Spring 2012
 */

#pragma once

#include <string>
#include <limits.h>

using std::string;

typedef string Vertex;

class Edge {
    public:
        Vertex source; /** The source of the edge **/
        Vertex dest; /** The destination of the edge **/

        /**
         * Parameter constructor for unweighted graphs.
         * @param u - one vertex the edge is connected to
         * @param v - the other vertex it is connected to
         */
        Edge(Vertex u, Vertex v) :
        source(u),
        dest(v),
        label(""),
        weight(1) {}

        /**
         * Parameter constructor for unweighted graphs.
         * @param u - one vertex the edge is connected to
         * @param v - the other vertex it is connected to
         * @param lbl - the edge label
         */
        Edge(Vertex u, Vertex v, string lbl) :
        source(u),
        dest(v),
        label(lbl),
        weight(1) {}

        /**
         * Parameter constructor for weighted graphs.
         * @param u - one vertex the edge is connected to
         * @param v - the other vertex it is connected to
         * @param w - the weight of the edge
         * @param lbl - the edge label
         */
        Edge(Vertex u, Vertex v, int w, string lbl) :
        source(u),
        dest(v),
        label(lbl),
        weight(w) {}

        /**
         * Default constructor.
         */
        Edge() :
        source(""),
        dest(""),
        label(""),
        weight(1) {}

        /**
         * Compares two Edges by the concatenation of their source and destination vertices.
         * operator< is defined so Edges can be sorted with std::sort.
         * @param other - the edge to compare with
         * @return whether the current edge is less than the parameter
         */
        bool operator<(const Edge& other) const {
            string this_edge = this->source + this->dest;
            string other_edge = other.source + other.dest;

            return this_edge < other_edge;
        }

        /**
         * Compares two edges' source and dest.
         * @param other - the edge to compare with
         */
        bool operator==(Edge& other) const {
            if ((this->source != other.source) || (this->dest != other.dest)) {
                return false;
            } else {
                return true;
            }
        }

        /**
         * Gets edge label.
         */
        string getLabel() const { return this->label; }

        /**
         * Gets edge weight.
         */
        int getWeight() const {return this->weight; }
    
    private:
        string label; /** The edge label **/
        int weight; /** The edge weight (if in a weighed graph) **/
};
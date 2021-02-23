#pragma once

#include "graph.h"

/**
 * Populates and returns the graph passed in with data stored at file_path
 * If the graph passed in already has data, it is cleared first
 * @param file_path: Path to the file storing graph vertex data
 * @return Graph with vertices storing data at file_path
 */
Graph& ParseData(Graph& g, string file_path);
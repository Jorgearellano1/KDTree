#include "KDTree.h"
#include "QuadTree.h"
#include "Box.h"
#include <chrono>
#include <iostream>
#include <vector>
#include <fstream>

namespace quadtree {
    template<typename T>
    struct GetBox {
        Box<float> operator()(const T& value) const {
            return Box<float>({value[0], value[1]}, {1.0f, 1.0f}); // Ajusta esto según sea necesario.
        }
    };
}

void printPoints(const std::vector<std::vector<float>>& points) {
    for (const auto& point : points) {
        std::cout << "(";
        for (size_t i = 0; i < point.size(); ++i) {
            std::cout << point[i];
            if (i < point.size() - 1) std::cout << ", ";
        }
        std::cout << ") ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<std::vector<float>> points = {
            {3, 6}, {17, 15}, {13, 15}, {6, 12}, {9, 1}, {2, 7}, {10, 19}
    };

    quadtree::Box<float> box({0.0f, 0.0f}, {20.0f, 20.0f});
    quadtree::Quadtree<std::vector<float>, quadtree::GetBox<std::vector<float>>> quadTree(box);
    KDTree kdTree;

    auto start = std::chrono::high_resolution_clock::now();
    for (const auto& point : points) {
        quadTree.add(point);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> quadInsertDuration = end - start;

    start = std::chrono::high_resolution_clock::now();
    for (const auto& point : points) {
        kdTree.insert(point);
    }
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> kdInsertDuration = end - start;

    std::vector<float> pointToSearch = {10, 19};

    start = std::chrono::high_resolution_clock::now();
    auto resultQuad = quadTree.query(quadtree::Box<float>({pointToSearch[0], pointToSearch[1]}, {1.0f, 1.0f}));
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> quadSearchDuration = end - start;

    start = std::chrono::high_resolution_clock::now();
    bool foundKD = kdTree.search(pointToSearch);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> kdSearchDuration = end - start;

    start = std::chrono::high_resolution_clock::now();
    quadTree.remove(pointToSearch);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> quadDeleteDuration = end - start;

    start = std::chrono::high_resolution_clock::now();
    kdTree.deletePoint(pointToSearch);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> kdDeleteDuration = end - start;

    std::cout << "Resultados de tiempo (en segundos):\n";
    std::cout << "Operación\tQuadtree\tKDTree\n";
    std::cout << "Inserción\t" << quadInsertDuration.count() << "\t" << kdInsertDuration.count() << "\n";
    std::cout << "Búsqueda\t" << quadSearchDuration.count() << "\t" << kdSearchDuration.count() << "\n";
    std::cout << "Eliminación\t" << quadDeleteDuration.count() << "\t" << kdDeleteDuration.count() << "\n";

    return 0;
}

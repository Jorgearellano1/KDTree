#include "KDTree.h"
#include "QuadTree.h"
#include "Box.h"
#include "Octree.h"
#include <chrono>
#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include <cassert>

struct Point3D {
    float x, y, z;
    Point3D(float X = 0, float Y = 0, float Z = 0) : x(X), y(Y), z(Z) {}
};

namespace quadtree {
    template<typename T>
    struct GetBox {
        Box<float> operator()(const T& value) const {
            return Box<float>({value[0], value[1]}, {1.0f, 1.0f});
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

std::vector<std::vector<float>> generateRandomPoints(size_t count, float min, float max) {
    std::vector<std::vector<float>> points;
    points.reserve(count);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(min, max);

    for (size_t i = 0; i < count; ++i) {
        points.push_back({static_cast<float>(dis(gen)), static_cast<float>(dis(gen))});
    }

    for (const auto& point : points) {
        assert(point[0] >= min && point[0] <= max);
        assert(point[1] >= min && point[1] <= max);
    }

    return points;
}

int main() {
    size_t numPoints = 1000; // Número de puntos aleatorios  aqui vamos probando lo para comparar podemos usar numeros mas grandes
    float minVal = 0.0f;
    float maxVal = 1000.0f;

    std::vector<std::vector<float>> points = generateRandomPoints(numPoints, minVal, maxVal);

    quadtree::Box<float> box({minVal, minVal}, {maxVal - minVal, maxVal - minVal});
    quadtree::Quadtree<std::vector<float>, quadtree::GetBox<std::vector<float>>> quadTree(box);
    KDTree kdTree;

    float min[3] = {minVal, minVal, minVal};
    float max[3] = {maxVal, maxVal, maxVal};
    float cellSize[3] = {1.0f, 1.0f, 1.0f};
    Octree<Point3D> octree(min, max, cellSize);

    auto start = std::chrono::high_resolution_clock::now();

    for (const auto& point : points) {
        if (!box.contains(quadtree::GetBox<std::vector<float>>()(point))) {
            std::cerr << "Punto fuera de la caja: (" << point[0] << ", " << point[1] << ")\n";
            continue;
        }
        quadTree.add(point);
    }
    auto resultQuad = quadTree.query(quadtree::Box<float>({points.back()[0], points.back()[1]}, {1.0f, 1.0f}));
    quadTree.remove(points.back());

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> quadTotalDuration = end - start;

    start = std::chrono::high_resolution_clock::now();

    for (const auto& point : points) {
        kdTree.insert(point);
    }
    bool foundKD = kdTree.search(points.back());
    kdTree.deletePoint(points.back());

    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> kdTotalDuration = end - start;

    start = std::chrono::high_resolution_clock::now();

    for (const auto& point : points) {
        Point3D p(point[0], point[1], 0.0f);
        octree.getCell(reinterpret_cast<float*>(&p));
    }
    Point3D pToSearch(points.back()[0], points.back()[1], 0.0f);
    auto octResult = octree.getCell(reinterpret_cast<float*>(&pToSearch)); // Placeholder for actual search

    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> octTotalDuration = end - start;

    std::cout << "Resultados de tiempo de ejecución (en segundos) para " << numPoints << " puntos:\n";
    std::cout << "Operación\tQuadtree\tKDTree\tOctree\n";
    std::cout << "Total\t\t" << quadTotalDuration.count() << "\t" << kdTotalDuration.count() << "\t" << octTotalDuration.count() << "\n";

    return 0;
}

// Copyright 2024 Betamark Pty Ltd. All rights reserved.
// Author: Shlomi Nissan (shlomi@betamark.com)

#pragma once

#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

#include <assimp/scene.h>

namespace assimp2h {
    class Reader {
    public:
        explicit Reader(std::string_view filename);

        auto vertices() const { return vertices_; }
        auto indices() const { return indices_; }

    private:
        std::vector<std::vector<float>> vertices_;
        std::vector<std::vector<unsigned int>> indices_;

        auto ProcessNode(const aiNode* node, const aiScene* scene) -> void;
        auto GetVertices(const aiMesh* mesh) const -> std::vector<float>;
        auto GetIndices(const aiMesh* mesh) const -> std::vector<unsigned int>;
    };

    struct ReaderError : public std::runtime_error {
        using std::runtime_error::runtime_error;
    };
}
// Copyright 2024 Betamark Pty Ltd. All rights reserved.
// Author: Shlomi Nissan (shlomi@betamark.com)

#pragma once

#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

#include <assimp/scene.h>

namespace assimp2c {
    class Reader {
    public:
        explicit Reader(std::string_view filename);

    private:
        std::vector<float> vertices_;
        std::vector<unsigned int> indices_;
        std::string error_;

        auto ProcessNode(const aiNode* node, const aiScene* scene) -> void;
        auto GetVertices(const aiMesh* mesh) -> void;
        auto GetIndices(const aiMesh* mesh) -> void;
    };

    struct ReaderError : public std::runtime_error {
        using std::runtime_error::runtime_error;
    };
}
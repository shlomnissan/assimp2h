// Copyright 2024 Betamark Pty Ltd. All rights reserved.
// Author: Shlomi Nissan (shlomi@betamark.com)

#include "reader.h"

#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <fmt/format.h>

namespace assimp2c {
    Reader::Reader(std::string_view filename) {
        auto importer = Assimp::Importer{};
        auto scene = importer.ReadFile(filename.data(), aiProcess_Triangulate | aiProcess_FlipUVs);
        if (scene == nullptr || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
            throw ReaderError {fmt::format("Failed to load model {}\n", filename)};
        }
        ProcessNode(scene->mRootNode, scene);    
    }

    auto Reader::ProcessNode(const aiNode* node, const aiScene* scene) -> void {
        
    }
}
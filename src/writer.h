// Copyright 2024 Betamark Pty Ltd. All rights reserved.
// Author: Shlomi Nissan (shlomi@betamark.com)

#pragma once

#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

namespace assimp2h {
    class Writer {
    public:
        explicit Writer(std::string_view name);

        auto setVertices(const std::vector<std::vector<float>>& vertices) -> void;
        auto setIndices(const std::vector<std::vector<unsigned int>>& indices) -> void;

        auto Write(std::string_view filename) const -> void;

    private:
        std::string name_;
        std::vector<std::vector<float>> vertices_;
        std::vector<std::vector<unsigned int>> indices_;

        auto WriteVertices(std::ofstream& fh) const -> void;
        auto WriteIndices(std::ofstream& fh) const -> void;
    };
    
    struct WriterError : public std::runtime_error {
        using std::runtime_error::runtime_error;
    };
}
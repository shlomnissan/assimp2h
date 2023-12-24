// Copyright 2024 Betamark Pty Ltd. All rights reserved.
// Author: Shlomi Nissan (shlomi@betamark.com)

#include <cstdlib>
#include <filesystem>
#include <stdexcept>
#include <string>

#include <gflags/gflags.h>
#include <fmt/printf.h>

#include "reader.h"

static bool validateInput(const char*, const std::string& value) {
    return value.empty() ? false : true;
}

DEFINE_string(input, "", "The path to the 3D model");
DEFINE_validator(input, &validateInput);

auto main(int argc, char* argv[]) -> int {
    fmt::print("ASSIMP2C - convert 3D models into C arrays using Assimp\n");
    fmt::print("Copyright (c) 2024 Shlomi Nissan www.betamark.com\n\n");

    if (argc == 1) {
        fmt::print("Usage: assimp2c --input <filename>\n");
    }
    gflags::ParseCommandLineFlags(&argc, &argv, true);

    if (!std::filesystem::exists(FLAGS_input)) {
        fmt::print("Error: Failed to load model '{}'\n", FLAGS_input);
        return EXIT_FAILURE;
    }

    try {
        auto reader = assimp2c::Reader {FLAGS_input};
    } catch (const std::runtime_error& e) {
        fmt::print("Error: {}\n", e.what());
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
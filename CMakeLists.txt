cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CXX_EXTENSIONS ON)

project(hermes LANGUAGES CXX)

add_executable(hermes src/main.cpp src/wallet/wallet.cpp src/primitives/block.cpp src/primitives/transaction.cpp)

add_subdirectory(vendor/uint256_t)
add_subdirectory(vendor/uint256_t/uint128_t)
add_subdirectory(vendor/secp256k1)

find_package(OpenSSL REQUIRED)

target_include_directories(hermes PUBLIC src src/wallet src/primitives src/crypto)

target_link_libraries(hermes PRIVATE OpenSSL::Crypto)
target_link_libraries(hermes PRIVATE uint128_t)
target_link_libraries(hermes PUBLIC uint256_t)
target_link_libraries(hermes PRIVATE secp256k1)

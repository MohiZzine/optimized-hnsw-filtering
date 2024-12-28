# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "C:/Users/farid/OneDrive/Desktop/hnsw/external/benchmark/googletest")
  file(MAKE_DIRECTORY "C:/Users/farid/OneDrive/Desktop/hnsw/external/benchmark/googletest")
endif()
file(MAKE_DIRECTORY
  "C:/Users/farid/OneDrive/Desktop/hnsw/build/external/benchmark/third_party/googletest/build"
  "C:/Users/farid/OneDrive/Desktop/hnsw/build/external/benchmark/third_party/googletest"
  "C:/Users/farid/OneDrive/Desktop/hnsw/build/external/benchmark/third_party/googletest/tmp"
  "C:/Users/farid/OneDrive/Desktop/hnsw/build/external/benchmark/third_party/googletest/src/googletest-stamp"
  "C:/Users/farid/OneDrive/Desktop/hnsw/build/external/benchmark/third_party/googletest/download"
  "C:/Users/farid/OneDrive/Desktop/hnsw/build/external/benchmark/third_party/googletest/src/googletest-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/farid/OneDrive/Desktop/hnsw/build/external/benchmark/third_party/googletest/src/googletest-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/farid/OneDrive/Desktop/hnsw/build/external/benchmark/third_party/googletest/src/googletest-stamp${cfgdir}") # cfgdir has leading slash
endif()

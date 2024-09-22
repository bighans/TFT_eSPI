# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/orsis/src/TFT_eSPI/TFT_eSPI/build/_deps/pngdec-src"
  "/home/orsis/src/TFT_eSPI/TFT_eSPI/build/_deps/pngdec-build"
  "/home/orsis/src/TFT_eSPI/TFT_eSPI/build/_deps/pngdec-subbuild/pngdec-populate-prefix"
  "/home/orsis/src/TFT_eSPI/TFT_eSPI/build/_deps/pngdec-subbuild/pngdec-populate-prefix/tmp"
  "/home/orsis/src/TFT_eSPI/TFT_eSPI/build/_deps/pngdec-subbuild/pngdec-populate-prefix/src/pngdec-populate-stamp"
  "/home/orsis/src/TFT_eSPI/TFT_eSPI/build/_deps/pngdec-subbuild/pngdec-populate-prefix/src"
  "/home/orsis/src/TFT_eSPI/TFT_eSPI/build/_deps/pngdec-subbuild/pngdec-populate-prefix/src/pngdec-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/orsis/src/TFT_eSPI/TFT_eSPI/build/_deps/pngdec-subbuild/pngdec-populate-prefix/src/pngdec-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/orsis/src/TFT_eSPI/TFT_eSPI/build/_deps/pngdec-subbuild/pngdec-populate-prefix/src/pngdec-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()

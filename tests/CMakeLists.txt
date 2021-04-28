# Sources that contain the tests
add_executable(catch2Test catch2Main.cpp) # Just this one contains BOOST_TEST_MAIN
target_sources(catch2Test PRIVATE
        testmotrice.cpp)

# Libraries used in the tests
target_link_libraries(catch2Test)

# Including headers
target_include_directories(catch2Test PRIVATE
        ../include) # Including this allows to simply write #include "funcs.h"
target_include_directories(catch2Test PRIVATE
        ../diitpahomework1/include) # Including this allows to simply write #include "funcs.h"

# Including sources
target_sources(catch2Test PRIVATE
        ../src/motrice.cpp)
target_sources(catch2Test PRIVATE
        ../src/machine.cpp)
target_sources(catch2Test PRIVATE
        ../diitpahomework1/src/CarTrailer.cpp)

#target_compile_options(catch2Test PRIVATE -Wa,-mbig-obj) # Solves assembler error of file too big

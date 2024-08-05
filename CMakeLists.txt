cmake_minimum_required(VERSION 3.10)
project(PracticeCPP VERSION 0.1.0 LANGUAGES C CXX)

# Set C++ standard for all targets
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Specify the include directories
include_directories(${CMAKE_SOURCE_DIR}/AdvancedCPP/09_Project_numword)

# Function to create executables
function(create_executables target_prefix sources)
    foreach(source_file IN LISTS ${sources})
        get_filename_component(target_name ${source_file} NAME_WE)
        add_executable(${target_prefix}_${target_name} ${source_file})
        target_compile_features(${target_prefix}_${target_name} PRIVATE cxx_std_20)
    endforeach()
endfunction()

# Source files for TheBasics
set(THEBASICS_SOURCES
    TheBasics/01_HelloWorld/HelloWorld.cpp
    TheBasics/02_Loops/for.cpp
    TheBasics/02_Loops/range-for.cpp
    TheBasics/02_Loops/switch.cpp
    TheBasics/02_Loops/while.cpp
    TheBasics/03_StatementAndExpressions/SE.cpp
    TheBasics/04_Constructor/constructor.cpp
    TheBasics/05_Pointer/pointer-incr.cpp
    TheBasics/06_Class/class.cpp
    TheBasics/06_Class/struct-class.cpp
    TheBasics/06_Class/rational.cpp
    TheBasics/06_Class/accessors.cpp
    TheBasics/07_Template/template-class.cpp
    TheBasics/07_Template/template-function.cpp
    TheBasics/08_STL/vector.cpp
    TheBasics/08_STL/string.cpp
    TheBasics/08_STL/iostream-file.cpp
    TheBasics/08_STL/iostream-formatting.cpp
)

# Source files for DesignPattern
set(DESIGNPATTERN_SOURCES
    DesignPattern/01_Adapter/objectAdapter.cpp
    DesignPattern/01_Adapter/classAdapter.cpp
    DesignPattern/01_Adapter/cloudStorage.cpp
    DesignPattern/02_Bridge/bridgeRefactor.cpp
    DesignPattern/02_Bridge/vehiclesEngines.cpp
    DesignPattern/03_Composite/boxesProducts.cpp
    DesignPattern/04_Decorator/computershop.cpp
    DesignPattern/04_Decorator/pizza.cpp
    DesignPattern/05_Facade/hotelReservation.cpp
    DesignPattern/05_Facade/weatherAPI.cpp
    DesignPattern/06_Flyweight/sprites.cpp
    DesignPattern/06_Flyweight/textEditor.cpp
    DesignPattern/07_Proxy/readConfig.cpp
    DesignPattern/07_Proxy/confidential.cpp
)

# Source files for AdvancedCPP
set(ADVANCECPP_SOURCES
    AdvancedCPP/01_OperatorOverload/rational.cpp
    AdvancedCPP/01_OperatorOverload/rational2.cpp
    AdvancedCPP/01_OperatorOverload/incr-decr.cpp
    AdvancedCPP/01_OperatorOverload/functor.cpp
    AdvancedCPP/02_MoveSemantics/container.cpp
    AdvancedCPP/02_MoveSemantics/container-02.cpp
    AdvancedCPP/02_MoveSemantics/container-03.cpp
    AdvancedCPP/02_MoveSemantics/vector-test.cpp
    AdvancedCPP/03_LambdaExpressions/lambda-hello.cpp
    AdvancedCPP/03_LambdaExpressions/lambda-capture.cpp
    AdvancedCPP/03_LambdaExpressions/lambda-predicate.cpp
    AdvancedCPP/03_LambdaExpressions/jump.cpp
    AdvancedCPP/04_ConstraintsAndConcepts/constraints.cpp
    AdvancedCPP/05_OptionalsAndVariants/any.cpp
    AdvancedCPP/05_OptionalsAndVariants/optional.cpp
    AdvancedCPP/05_OptionalsAndVariants/variant.cpp
    AdvancedCPP/06_Concurrency/async.cpp
    AdvancedCPP/06_Concurrency/atomic.cpp
    AdvancedCPP/06_Concurrency/mutex.cpp
    AdvancedCPP/06_Concurrency/producer-consumer.cpp
    AdvancedCPP/06_Concurrency/promise.cpp
    AdvancedCPP/06_Concurrency/sleep.cpp
    AdvancedCPP/06_Concurrency/thread.cpp
    AdvancedCPP/07_OtherSubjects/chrono.cpp
    AdvancedCPP/07_OtherSubjects/filesystem.cpp
    AdvancedCPP/07_OtherSubjects/initialization.cpp
    AdvancedCPP/07_OtherSubjects/rng.cpp
    AdvancedCPP/07_OtherSubjects/struct-binding.cpp
    AdvancedCPP/08_OtherCPPFeatures/format.cpp
    AdvancedCPP/08_OtherCPPFeatures/spaceship.cpp
    AdvancedCPP/08_OtherCPPFeatures/spaceship-frac.cpp
    AdvancedCPP/08_OtherCPPFeatures/span.cpp
    AdvancedCPP/09_Project_numword/numword.cpp
    AdvancedCPP/09_Project_numword/numword-test.cpp
)

# Create executables for TheBasics
create_executables(TheBasics ${THEBASICS_SOURCES})

# Create executables for DesignPattern
create_executables(DesignPattern ${DESIGNPATTERN_SOURCES})

# Create executable specifically for numword
add_executable(numword_AdvancedCPP
    AdvancedCPP/09_Project_numword/numword.cpp
    AdvancedCPP/09_Project_numword/numword-test.cpp
)
target_compile_features(numword_AdvancedCPP PRIVATE cxx_std_20)

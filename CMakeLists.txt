cmake_minimum_required(VERSION 3.30.1)
project(PracticeCPP VERSION 0.1.0 LANGUAGES C CXX)

# Set C++ standard for all targets
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

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

# Create executables for TheBasics
foreach(source_file IN LISTS THEBASICS_SOURCES)
    get_filename_component(target_name ${source_file} NAME_WE)
    add_executable(${target_name}_TheBasics ${source_file})
endforeach()

# Create executables for DesignPattern
foreach(source_file IN LISTS DESIGNPATTERN_SOURCES)
    get_filename_component(target_name ${source_file} NAME_WE)
    add_executable(${target_name}_DesignPattern ${source_file})
endforeach()
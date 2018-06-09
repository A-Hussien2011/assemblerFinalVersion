cmake_minimum_required(VERSION 3.10)
project(pass_1)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(pass_1
        main.cpp
        include/OperationInfomation.h
        src/OperationTable.cpp
        include/OperationTable.h
        src/InstructionLine.cpp
        include/InstructionLine.h
        src/Controller.cpp
        src/AsciiCode.cpp
        src/Converters.cpp
        src/DirectiveTable.cpp
        src/GroupTable.cpp
        src/inOutFile.cpp
        src/LitTable.cpp
        src/OperandSizeValidator.cpp
        src/OperandValidator.cpp
        src/OpValidator.cpp
        src/SymbolTable.cpp
        include/Controller.h
        include/AsciiCode.h
        include/Converters.h
        include/DirectiveTable.h
        include/GroupTable.h
        include/inOutFile.h
        include/LitTable.h
        include/OperandSizeValidator.h
        include/OperandValidator.h
        include/OpValidator.h
        include/SymbolTable.h)

cmake_minimum_required(VERSION 3.10)
project(pass_1)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(pass_1
        main.cpp
        src/Controller.cpp
        src/AsciiCode.cpp
        src/Converters.cpp
        src/DirectiveTable.cpp
        src/GroupTable.cpp
        src/inOutFile.cpp
        src/LitTable.cpp
        src/OperandSizeValidator.cpp
        src/OperandValidator.cpp
        src/SymbolTable.cpp
        src/InstructionLine.cpp
        src/OperationTable.cpp
        include/OperationInfomation.h
        include/OperationTable.h
        include/InstructionLine.h
        include/Controller.h
        include/AsciiCode.h
        include/Converters.h
        include/DirectiveTable.h
        include/GroupTable.h
        include/inOutFile.h
        include/LitTable.h
        include/OperandSizeValidator.h
        include/OperandValidator.h
        include/SymbolTable.h src/IntermediateLine.cpp include/IntermediateLine.h)

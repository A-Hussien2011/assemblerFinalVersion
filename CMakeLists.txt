cmake_minimum_required(VERSION 3.10)
project(pass_1)

set(CMAKE_CXX_STANDARD 11)

include_directories("Pass 1")

add_executable(pass_2
        #[["Pass 1/main.cpp"
        "Pass 1/include/OperationInfomation.h"
        "Pass 1/src/OperationTable.cpp"
        "Pass 1/include/OperationTable.h"
        "Pass 1/src/InstructionLine.cpp"
        "Pass 1/include/InstructionLine.h"
        "Pass 1/src/Controller.cpp"
        "Pass 1/src/AsciiCode.cpp"
        "Pass 1/src/Converters.cpp"
        "Pass 1/src/DirectiveTable.cpp"
        "Pass 1/src/GroupTable.cpp"
        "Pass 1/src/inOutFile.cpp"
        "Pass 1/src/LitTable.cpp"
        "Pass 1/src/OperandSizeValidator.cpp"
        "Pass 1/src/OperandValidator.cpp"
        "Pass 1/src/SymbolTable.cpp"
        "Pass 1/include/Controller.h"
        "Pass 1/include/AsciiCode.h"
        "Pass 1/include/Converters.h"
        "Pass 1/include/DirectiveTable.h"
        "Pass 1/include/GroupTable.h"
        "Pass 1/include/inOutFile.h"
        "Pass 1/include/LitTable.h"
        "Pass 1/include/OperandSizeValidator.h"
        "Pass 1/include/OperandValidator.h"
        "Pass 1/include/SymbolTable.h"]]
        "Pass 2/include/IntermediateLine.h"
        "Pass 2/src/IntermediateLine.cpp"
        "Pass 2/include/DirectiveTable.h"
        "Pass 2/src/DirectiveTable.cpp"
        "Pass 2/include/OperationTable.h"
        "Pass 2/src/OperationTable.cpp"
        "Pass 2/main.cpp"
        )

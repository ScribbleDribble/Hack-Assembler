set(can_use_assembler FALSE)

project(Hack-Assembler)

add_executable(
	hack
	Parser.cpp
	CodeGen.cpp
	main.cpp
	SymbolTable.cpp

)

target_link_libraries(hack)	

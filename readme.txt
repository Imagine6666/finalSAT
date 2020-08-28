使用codeblocks16.01，主要用C语言编写（少量用到了C++里面的语法），总体是main.cpp,CnfParser.cpp,Sudoku.cpp,Start.cpp,DPLLSolver.cpp,Global.h这些文件。

在main.cpp中的choice==2模块中可以修改求解的CNF文件名，CnfParser.cpp中的CreateClause函数中的HFilePath可以自己定义cnf文件地址，在Sudoku.cpp中的ToCnf函数中修改pathn可以自己定义在哪里生成求解数独所需的cnf文件（即生成的cnf文件地址）
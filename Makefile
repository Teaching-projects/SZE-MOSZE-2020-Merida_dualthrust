OBJECTS := JSON.o Monster.o Hero.o main.o
COMPILERFLAGS := -std=c++17 -Wall -Werror -Wextra 
COMPILER := g++

CPPFILES := JSON.cpp Monster.cpp Hero.cpp main.cpp

VALGRINDFLAGS:= --leak-check=full --error-exitcode=1
VALGRINDPARAMETER:=  ./a.out scenario1.json

build: $(OBJECTS)
	$(COMPILER) $(COMPILERFLAGS) -o a.out $(OBJECTS)

JSON.o: JSON.cpp JSON.h
	$(COMPILER) $(COMPILERFLAGS) -c JSON.cpp

Monster.o: Monster.cpp Monster.h JSON.h
	$(COMPILER) $(COMPILERFLAGS) -c Monster.cpp

Hero.o: Hero.cpp Hero.h Monster.h JSON.h
	$(COMPILER) $(COMPILERFLAGS) -c Hero.cpp

main.o: main.cpp Monster.h Hero.h
	$(COMPILER) $(COMPILERFLAGS) -c main.cpp

Clean:
	rm -rf $(OBJECTS) a.out cppcheck_results.txt results_scenario_1.txt results_scenario_2.txt

Install_all_dependencies:
	sudo apt install -y cppcheck && sudo apt install -y valgrind && sudo apt install -y gcc g++ && sudo apt install doxygen && sudo apt install graphviz

Install_googletest_and_cmake:
	sudo apt install libgtest-dev && sudo apt install cmake && cd /usr/src/gtest && sudo cmake . && sudo make && sudo cp *.a /usr/lib && sudo ln -s /usr/lib/libgtest.a /usr/local/lib/libgtest.a && sudo ln -s /usr/lib/libgtest_main.a /usr/local/lib/libgtest_main.a	

Static_code_analysis_cppcheck:
	cppcheck $(CPPFILES) --output-file=cppcheck_results.txt && chmod +x warning_check.sh && ./warning_check.sh && chmod +x error_check.sh && ./error_check.sh

Valgrind:
	valgrind $(VALGRINDFLAGS) $(VALGRINDPARAMETER)

In-out_tests:
	cd tests && chmod +x run_test.sh && ./run_test.sh

Generate_documentation: 
	doxygen doxconf

Make_parsertests_with_cmake:
	cd tests && cmake . && make

Run_parsertest:
	cd tests && ./runTests
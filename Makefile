OBJECTS := JSON.o Monster.o Hero.o Map.o Game.o main.o MarkedMap.o PreparedGame.o
COMPILERFLAGS := -std=c++17 -g -Wall -Werror -Wextra 
COMPILER := g++

CPPFILES := JSON.cpp Monster.cpp Hero.cpp Map.cpp Game.cpp main.cpp MarkedMap.cpp PreparedGame.cpp

VALGRINDFLAGS:= --leak-check=full --error-exitcode=1 --track-origins=yes --log-file="Valgrind_log"
VALGRINDPARAMETER:=  ./a.out preparedgame.json -test

build: $(OBJECTS)
	$(COMPILER) $(COMPILERFLAGS) -o a.out $(OBJECTS)

JSON.o: JSON.cpp JSON.h
	$(COMPILER) $(COMPILERFLAGS) -c JSON.cpp

Monster.o: Monster.cpp Monster.h JSON.h Damage.h
	$(COMPILER) $(COMPILERFLAGS) -c Monster.cpp

Hero.o: Hero.cpp Hero.h Monster.h JSON.h Damage.h
	$(COMPILER) $(COMPILERFLAGS) -c Hero.cpp
	
Map.o: Map.cpp Map.h
	$(COMPILER) $(COMPILERFLAGS) -c Map.cpp
	
Game.o: Game.cpp Hero.h Monster.h Map.h
	$(COMPILER) $(COMPILERFLAGS) -c Game.cpp

main.o: main.cpp Monster.h Hero.h ObserverSVGRenderer.h HeroSVGRenderer.h HeroTextRenderer.h ObserverTextRenderer.h 
	$(COMPILER) $(COMPILERFLAGS) -c main.cpp

MarkedMap.o: MarkedMap.cpp MarkedMap.h Map.h
	$(COMPILER) $(COMPILERFLAGS) -c MarkedMap.cpp

PreparedGame.o: PreparedGame.cpp PreparedGame.h Map.h Game.h JSON.h
	$(COMPILER) $(COMPILERFLAGS) -c PreparedGame.cpp

Clean:
	rm -rf $(OBJECTS) a.out cppcheck_results.txt results_scenario_1.txt results_scenario_2.txt

Static_code_analysis_cppcheck:
	cppcheck $(CPPFILES) --output-file=cppcheck_results.txt && chmod +x warning_check.sh && ./warning_check.sh && chmod +x error_check.sh && ./error_check.sh

Memcheck:
	valgrind $(VALGRINDFLAGS) $(VALGRINDPARAMETER)

In-out_tests:
	chmod +x run_test.sh && ./run_test.sh

Generate_documentation:
	doxygen doxyconf

Make_tests_with_cmake:
	cd tests && cmake . && make

Run_parsertest:
	cd tests && ./runParserTests

Run_unittests:
	cd tests && ./runUnitTests
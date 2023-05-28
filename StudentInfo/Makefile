main: main.o merge.o Student.o
	g++ -o main main.o merge.o Student.o
main.o: main.cpp
	g++ -c main.cpp
MergeSort.o: merge.cpp Merge.h
	g++ -c merge.cpp
Student.o: Student.cpp Student.h
	g++ -c Student.cpp
clean:
	rm main *.o
debug: main.cpp merge.cpp Merge.h Student.cpp Student.h
	g++ -g -o main main.cpp merge.cpp Student.cpp

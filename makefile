build: main.o Cliente.o Midia.o Filme.o Locacao.o
    g++ main.o Personagem.o Vilao.o Heroi.o Locacao.o -o $@

main.o: main.cpp
    g++ -c main.cpp

Cliente.o: Cliente.cpp Cliente.h
    g++ -c Cliente.cpp

Midia.o: Midia.cpp Midia.h
    g++ -c Midia.cpp

Filme.o: Filme.cpp Filme.h
    g++ -c Filme.cpp

Locacao.o: Locacao.cpp Locacao.h
    g++ -c Locacao.cpp

run:
    ./output

clean:
    rm *.o output 

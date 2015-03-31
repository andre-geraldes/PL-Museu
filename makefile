teste: parser.l listaligada.c html.c
	flex parser.l
	gcc -o teste html.c listaligada.c lex.yy.c
	./teste < legenda.xml

clean:
	rm lex.yy.c
	rm teste

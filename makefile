teste: parser.l listaligada.c html.c
	flex parser.l
	gcc -o teste html.c listaligada.c lex.yy.c
	./teste < fotos.xml

clean:
	rm lex.yy.c
	rm teste
	rm new.html

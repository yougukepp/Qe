all:clean
	asy fig/subSystem.asy
	asy fig/systemComunicate.asy
	xelatex document.tex
	xelatex document.tex 
	evince document.pdf
clean:
	rm -rf document.aux  document.idx  document.log  document.pdf  document.toc subSystem.pdf systemComunicate.pdf


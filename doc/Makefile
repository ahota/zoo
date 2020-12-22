%.md:
	pandoc *.md -o $@

.PHONY: all readme clean

readme: ../README.md

gh-pages: index.md

all: readme gh-pages

clean:
	rm *.html

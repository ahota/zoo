.PHONY: all index.md ../README.md

all: ../README.md

index.md:
	pandoc -f gfm -t gfm -o $@ 0*_*.md

../README.md: index.md
	cp $< $@

clean:
	rm index.md ../README.md

all: assign8.html gradescope.json

%.json: %.toml
	python3 ../../admin/toml2json.py < $< > $@

%.html: %.md
	pandoc -o $@ $<
